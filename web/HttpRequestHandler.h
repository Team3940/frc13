#ifndef HTTPREQUESTHANDLER_H
#define HTTPREQUESTHANDLER_H

#include "HttpRequest.h"
#include "HttpResponse.h"

class HttpRequestHandler
{
  public:
    virtual void HandleRequest(HttpRequest &request, CTSocket &socket) = 0;
};

#endif
