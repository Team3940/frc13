#include "VisionProcess.h"

VisionProcess::VisionProcess(const char *cameraIp)
{
  camera = &AxisCamera::GetInstance(cameraIp);

  task = new Task("VisionTask", (FUNCPTR)VisionProcess::VisionTask, 200);
  task->Start((UINT32) this);
  enabled = false;

  timer = new Timer();
}

VisionProcess::~VisionProcess()
{
  task->Stop();
}

void VisionProcess::VisionTask(VisionProcess* vp)
{
  while (true) {
    if (vp->enabled && vp->timer->Get() > (30)) {
      vp->DoVision();
      vp->timer->Reset();
    }
    Wait(0.002);
  }
}

void VisionProcess::Start()
{
  enabled = true;
  timer->Start();
}

void VisionProcess::Stop()
{
  enabled = false;
  timer->Stop();
}
