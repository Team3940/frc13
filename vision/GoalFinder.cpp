#include "GoalFinder.h"
#include "JpegFromImaq.h"
#include <iostream>
#include <fstream>

GoalFinder::GoalFinder(const char *cameraIp) : VisionProcess(cameraIp)
{
}

void GoalFinder::DoVision()
{
/*
  std::cout << "DoVision call" << std::endl;
  ColorImage img(IMAQ_IMAGE_RGB);
  if (!camera->GetImage(&img)) {
    std::cout << "Image not acquired :(" << std::endl;
    return;
  }

  std::cout << "Got image" << std::endl;

  JpegFromImaq jpeg(img.GetImaqImage());

  std::ofstream outfile;
  outfile.open("/cybertooth/flat2.jpeg", ios::out | ios::trunc | ios::binary);
  outfile.write((const char *) jpeg.GetJpeg(), jpeg.Size());
  outfile.close();
  
  std::cout << "Saved image" << std::endl;
*/
}

JpegFromImaq * GoalFinder::GetDebugImage()
{
  ColorImage img(IMAQ_IMAGE_RGB);

  if (!camera->GetImage(&img)) {
    std::cout << "Image not acquired :(" << std::endl;
    return NULL;
  }

  std::cout << "Got image" << std::endl;
  JpegFromImaq *jpeg = new JpegFromImaq(img.GetImaqImage());
  return jpeg;
}
