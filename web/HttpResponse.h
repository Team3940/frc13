#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H

#include "../util/CTSocket.h"

class HttpResponse
{
  public:
    HttpResponse();
    void SetData(void *data, int size);
    void Send(CTSocket &socket);

  private:
    void *data;
    unsigned int size;
};

#endif
