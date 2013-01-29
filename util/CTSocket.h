#ifndef CTSOCKET_H
#define CTSOCKET_H

#include <string>

class CTSocket
{
  public:
    CTSocket(int socketNum);
    ~CTSocket();

    const CTSocket& operator << ( const std::string&) const;
    const CTSocket& operator << ( std::istream &stream) const;
    const CTSocket& operator >> ( std::string&) const;
    void Send(const char *data, size_t size);
  private:
    int socketNum;
    int bufferSize;
};

#endif
