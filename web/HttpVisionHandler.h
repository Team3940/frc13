#ifndef HTTPVISIONHANDLER_H
#define HTTPVISIONHANDLER_H

#include "WebServer.h"
#include "../vision/VisionProcess.h"

class HttpVisionHandler : public HttpRequestHandler
{
  private:
    VisionProcess *visionProcess;

  public:
    HttpVisionHandler(VisionProcess *visionProcess);
    virtual void HandleRequest(HttpRequest &request, CTSocket &socket);
};

#endif
