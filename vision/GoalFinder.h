#ifndef GOALFINDER_H
#define GOALFINDER_H

#include "VisionProcess.h"

class GoalFinder : public VisionProcess
{
  private:

  public:
    GoalFinder(const char *cameraIp);
    virtual void DoVision();
    JpegFromImaq * GetDebugImage();
};

#endif
