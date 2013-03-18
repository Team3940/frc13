#include "DeployShooterCommand.h"
#include <sstream>

DeployShooterCommand::DeployShooterCommand(Shooter *shooter)
{
  this->shooter = shooter;
}

DeployShooterCommand::~DeployShooterCommand()
{
}

void DeployShooterCommand::Reset()
{
}

std::string DeployShooterCommand::ToString()
{
  return "";
}

bool DeployShooterCommand::Run()
{
  shooter->DeployShooter();
  shooter->SetShooterEnable(true);
  if (shooter->GetActualDeployState() == DEPLOYED) {
    shooter->Shoot();
  }
  return false;
}
