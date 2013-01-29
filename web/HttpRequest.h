#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include "../util/CTSocket.h"

class HttpRequest
{
  public:
    HttpRequest(const CTSocket &socket);

    std::string GetFilename();

  private:
    std::string filename;
};

#endif
