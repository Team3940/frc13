#include "HttpFileHandler.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

void HttpFileHandler::HandleRequest(HttpRequest &request, CTSocket &socket)
{
  // TODO:  Rework this to use CTSocket
  std::string filename("/cybertooth/www");
  filename += request.GetFilename();

  fstream file;
  file.open(filename.c_str(), ios::in|ios::binary|ios::ate);

  std::cout << "serving file:  " << filename << std::endl;

  std::ostringstream header;
  header << "HTTP/1.0 200 OK\r\nConnection: close\r\nContent-Length: ";
  header << file.tellg() << "\r\n\r\n";
  socket << header.str();

  file.seekg(0, ios::beg);
  socket << file;
  file.close();
}
