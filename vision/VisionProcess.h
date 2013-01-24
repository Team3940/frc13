#ifndef VISIONPROCESS_H
#define VISIONPROCESS_H

#include "WPILib.h"
#include "JpegFromImaq.h"

class VisionProcess
{
  private:
    bool enabled;
    Task *task;
    Timer *timer;
    
    static void VisionTask(VisionProcess * vp);

  protected:
    AxisCamera *camera;

  public:
    VisionProcess(const char *cameraIp = NULL);
    virtual ~VisionProcess();
    virtual void DoVision() = 0;
    virtual JpegFromImaq * GetDebugImage() = 0;
    void Start();
    void Stop();
};

#endif
