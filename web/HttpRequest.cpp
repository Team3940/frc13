#include "HttpRequest.h"

HttpRequest::HttpRequest(const CTSocket &socket)
{
  std::string request;
  socket >> request;
  int pos = request.find("HTTP/");
  filename = request.substr(4, pos - 5);
}

std::string HttpRequest::GetFilename()
{
  return filename;
}
