#include "WebServer.h"

#include <fstream>
#include <sstream>
#include <string>

#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#include "HTTPRequest.h"
#include "../util/CTSocket.h"
#include "../vision/JpegFromImaq.h"

#define PORT_NUMBER 80

map<string, HttpRequestHandler *> WebServer::requestHandlers;
HttpFileHandler WebServer::defaultHandler;

WebServer::WebServer()
{
  task = new Task("WebServerTask", (FUNCPTR) WebServer::ProcessRequests);
  task->Start((UINT32)this);
}

WebServer::~WebServer()
{
  delete task;
}

void WebServer::SetRequestHandler(string path, HttpRequestHandler *handler)
{
  requestHandlers[path] = handler;
}

void WebServer::ProcessRequests(WebServer *server)
{
  int sockNum = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(PORT_NUMBER);
  addr.sin_addr.s_addr = htonl(INADDR_ANY);

  bind(sockNum, (struct sockaddr *) &addr, sizeof(addr));
  listen(sockNum, 1024);

  while (1) {
    CTSocket *socket = new CTSocket(accept(sockNum, NULL, 0));

    pthread_t thread;
    if (!pthread_create(&thread, NULL, ProcessRequest, socket)) {
      pthread_detach(thread);
    }
  }
}

void * WebServer::ProcessRequest(void *context)
{
  CTSocket &socket = *((CTSocket *) context);
  HttpRequest request(socket);
  string requestPath("");
  requestPath += request.GetFilename();

  if (requestHandlers.find(requestPath) != requestHandlers.end()) {
    requestHandlers[requestPath]->HandleRequest(request, socket);
  } else {
    defaultHandler.HandleRequest(request, socket);
  }

  delete &socket;
  pthread_exit(NULL);
  return NULL;
}

void * WebServer::OldProcessRequest(void *context)
{
  CTSocket &socket = *((CTSocket *) context);
  HttpRequest request(socket);
  string filename("/cybertooth/www");

  filename += request.GetFilename();

  std::cout << "HTTP Request: " << filename << std::endl;

  if (filename == "/cybertooth/www/camera") {
    std::cout << "camera request!" << std::endl;
    AxisCamera &camera = AxisCamera::GetInstance("10.39.40.11");
    ColorImage img(IMAQ_IMAGE_RGB);

    if (!camera.GetImage(&img)) {
      std::cout << "Image not acquired :(" << std::endl;
      std::ostringstream header;
      header << "HTTP/1.0 404 Not Found\r\nConnection: close\r\n\r\n";
      socket << header.str();
    } else {
      std::cout << "Got image" << std::endl;
      JpegFromImaq jpeg(img.GetImaqImage());
  
      std::ostringstream header;
      header << "HTTP/1.0 200 OK\r\nConnection: close\r\nContent-Length: ";
      header << jpeg.Size() << "\r\n\r\n";
      socket << header.str();

      socket.Send((const char *) jpeg.GetJpeg(), jpeg.Size());

      imaqDispose(img.GetImaqImage());
    }

    delete &socket;
    pthread_exit(NULL);
    return NULL;
  }

  fstream file;
  file.open(filename.c_str(), ios::in|ios::binary|ios::ate);

  std::ostringstream header;
  header << "HTTP/1.0 200 OK\r\nConnection: close\r\nContent-Length: ";
  header << file.tellg() << "\r\n\r\n";
  socket << header.str();

  file.seekg(0, ios::beg);
  socket << file;
  file.close();
  delete &socket;
  pthread_exit(NULL);
  return NULL;
}
