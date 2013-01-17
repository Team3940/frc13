#ifndef HTTPFILEHANDLER_H
#define HTTPFILEHANDLER_H

#include "HttpRequestHandler.h"

class HttpFileHandler : public HttpRequestHandler
{
  private:

  public:
    virtual void HandleRequest(HttpRequest &request, CTSocket &socket);
};

#endif
