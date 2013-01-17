#ifndef JPEGFROMIMAQ_H
#define JPEGFROMIMAQ_H

#include "WPILib.h"

class JpegFromImaq
{
  private:
    char *jpegBuffer;
    unsigned int size;

  public:
    JpegFromImaq(const Image *image);
    ~JpegFromImaq();
    void * GetJpeg();
    unsigned int Size();

};

#endif
