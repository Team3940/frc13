#include "GoalFinder.h"
#include "JpegFromImaq.h"
#include <iostream>
#include <fstream>

GoalFinder::GoalFinder(const char *cameraIp) : VisionProcess(cameraIp), img(IMAQ_IMAGE_RGB)
{
  redRange.minValue = 200;
  redRange.maxValue = 255;
  greenRange.minValue = 200;
  greenRange.maxValue = 255;
  blueRange.minValue = 200;
  blueRange.maxValue = 255;

  // overlay options
  color.R = 0x0;
  color.G = 0xFF;
  color.B = 0x0;
  color.alpha = 0x00;

  options.fontName = "Litt";
  options.fontSize = 32;
  options.bold = 1;
  options.italic = 0;
  options.underline = 0;
  options.strikeout = 0;
  options.horizontalTextAlignment = IMAQ_LEFT;
  options.verticalTextAlignment = IMAQ_BOTTOM;
  RGBValue backColor;
  backColor.R = 0;
  backColor.G = 0;
  backColor.B = 0;
  backColor.alpha = 0;
  options.backgroundColor = backColor;
  options.angle = 0;
}

void GoalFinder::DoVision()
{
  std::cout << "DoVision call" << std::endl;
/*
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
  Point point1;
  point1.x = 100;
  point1.y = 100;

  Point point2;
  point2.x = 200;
  point2.y = 200;

  // Image *overlay = imaqCreateImage(IMAQ_IMAGE_RGB, DEFAULT_BORDER_SIZE);
  ColorImage overlay(IMAQ_IMAGE_RGB);

  if (!camera->GetImage(&img)) {
    std::cout << "Image not acquired :(" << std::endl;
    return NULL;
  }

  std::cout << "Got image" << std::endl;

  BinaryImage result;
  imaqColorThreshold(result.GetImaqImage(), img.GetImaqImage(), 1, IMAQ_RGB, &redRange, &greenRange, &blueRange);
  imaqConvexHull(result.GetImaqImage(), result.GetImaqImage(), 8);
  std::cout << "convex hull error:  " << imaqGetLastErrorFunc() << std::endl;
  //imaqOverlayLine(result.GetImaqImage(), point1, point2, &color, "");
  //imaqOverlayText(result.GetImaqImage(), point1, "Primary Goal", &color, &options, "");
  //imaqMergeOverlay(overlay.GetImaqImage(), result.GetImaqImage(), NULL, 256, "");

  // print out the center mass for each particle to the console
  int particleCount = result.GetNumberParticles();
  for (int particle = 0; particle < particleCount; particle++) {
    ParticleAnalysisReport report = result.GetParticleAnalysisReport(particle);
    std::cout << "Particle " << particle << " X:  " << report.center_mass_x_normalized << "  Y:  " << report.center_mass_y_normalized << std::endl; 
  }

  JpegFromImaq *jpeg = new JpegFromImaq(overlay.GetImaqImage());
  return jpeg;
}
