#include "HttpVisionHandler.h"

HttpVisionHandler::HttpVisionHandler(VisionProcess *visionProcess)
{
  this->visionProcess = visionProcess;
}

void HttpVisionHandler::HandleRequest(HttpRequest &request, CTSocket &socket)
{
  HttpResponse response;

  JpegFromImaq *jpeg = visionProcess->GetDebugImage();

  response.SetData(jpeg->GetJpeg(), jpeg->Size());

  response.Send(socket);

  delete jpeg;
}
