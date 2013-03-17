#include "ClimbCommand.h"
#include <sstream>
#include <cmath>

ClimbCommand::ClimbCommand(AutoOperator *autoCtrl, float hingeAngle, float conveyorDistance)
{
  this->autoCtrl = autoCtrl;
  this->hingeAngle = hingeAngle;
  this->conveyorDistance = conveyorDistance;
}

ClimbCommand::~ClimbCommand()
{
}

void ClimbCommand::Reset()
{
}

std::string ClimbCommand::ToString()
{
  ostringstream ss;
  ss << "ClimbCommand:  " << hingeAngle << " deg, ";
  ss << conveyorDistance << " inches";
  return ss.str();
}

bool ClimbCommand::Run()
{
  autoCtrl->SetDesiredHingeAngle(hingeAngle);
  autoCtrl->SetDesiredConveyorDistance(conveyorDistance);
  return autoCtrl->AtDesiredPosition();
}
