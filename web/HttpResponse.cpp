#include "HTTPResponse.h"
#include <sstream>

HttpResponse::HttpResponse()
{
}

void HttpResponse::SetData(void *data, int size)
{
  this->data = data;
  this->size = size;
}

void HttpResponse::Send(CTSocket &socket)
{
  std::ostringstream header;
  header << "HTTP/1.0 200 OK\r\nConnection: close\r\nContent-Length: ";
  header << size << "\r\n\r\n";
  socket << header.str();

  socket.Send((const char *) data, size);
}
