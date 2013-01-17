#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "WPILib.h"
#include "../net/CTSocket.h"
#include <string>
#include <map>

#include "HttpRequest.h"
#include "HttpResponse.h"
#include "HttpRequestHandler.h"
#include "HttpFileHandler.h"

class WebServer
{
  public:
    WebServer();
    ~WebServer();

    void SetRequestHandler(string path, HttpRequestHandler *handler);

  private:
    Task* task;
    static map<string, HttpRequestHandler *> requestHandlers;
    static HttpFileHandler defaultHandler;

    static void ProcessRequests(WebServer *server);
    static void * ProcessRequest(void *context);
    void * OldProcessRequest(void *context);
};

#endif
