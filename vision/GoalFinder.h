#ifndef GOALFINDER_H
#define GOALFINDER_H

#include "VisionProcess.h"

class GoalFinder : public VisionProcess
{
  private:
    // vision parameters
    Range redRange;
    Range greenRange;
    Range blueRange;

    // overlay options
    RGBValue color;
    OverlayTextOptions options;

    ColorImage img;

  public:
    GoalFinder(const char *cameraIp);
    virtual void DoVision();
    JpegFromImaq * GetDebugImage();
};

#endif
