#include "JpegFromImaq.h"

JpegFromImaq::JpegFromImaq(const Image *image)
{
  FlattenType flattenType = IMAQ_FLATTEN_IMAGE;
  CompressionType compressionType = IMAQ_COMPRESSION_JPEG;
  jpegBuffer = (char *) imaqFlatten(image, flattenType, compressionType, 750, &size);
}

JpegFromImaq::~JpegFromImaq()
{
  imaqDispose(jpegBuffer);
}

void * JpegFromImaq::GetJpeg()
{
  for (char *p = jpegBuffer; p <= (jpegBuffer + size - 2); p++) {
    if (memcmp(p, "\xFF\xD8", 2) == 0) {
      return p;
    }
  }
  return NULL;
}

unsigned int JpegFromImaq::Size()
{
  return size;
}
