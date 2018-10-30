#include "libIterativeRobot/commands/ArmUp.h"
#include "libIterativeRobot/Robot.h"

ArmUp::ArmUp(std::int32_t target) {
  this->target = target;
  requires(Robot::arm);
}

bool ArmUp::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void ArmUp::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void ArmUp::execute() {
  // Code that runs when this command is scheduled to run
  std::int32_t position = Robot::arm->getEncoderValue();
  if (position > target) {
    Robot::arm->move(-127);
  } else if (position < target) {
    Robot::arm->move(127);
  } else {
    Robot::arm->move(0);
  }
}

bool ArmUp::isFinished() {
  return threshold(target - Robot::arm->getEncoderValue(), 20); // This is the default value anyways, so this method can be removed
}

void ArmUp::end() {
  // Code that runs when isFinished() returns true.
  Robot::arm->move(0); 
}

void ArmUp::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
