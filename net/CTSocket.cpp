#include "CTSocket.h"
#include "socket.h"
#include "sockLib.h"
#include <string>

CTSocket::CTSocket(int socketNum)
{
  this->bufferSize = 16384;
  this->socketNum = socketNum;
}

CTSocket::~CTSocket()
{
  close(socketNum);
}

const CTSocket& CTSocket::operator << ( const std::string &str) const
{
  send(socketNum, str.c_str(), str.size(), 0);
  return *this;
}

const CTSocket& CTSocket::operator << ( std::istream &stream) const
{
  char buffer[bufferSize];
  while (stream.good()) {
    stream.read(buffer, bufferSize);
    send(socketNum, buffer, stream.gcount(), 0);
  }
  return *this;
}

const CTSocket& CTSocket::operator >> ( std::string &str) const
{
  char buffer[bufferSize];
  memset(buffer, 0, bufferSize);
  recv(socketNum, buffer, bufferSize, 0);
  str = buffer;
  return *this;
}

void CTSocket::Send(const char *data, size_t size)
{
  send(socketNum, data, size, 0);
}
