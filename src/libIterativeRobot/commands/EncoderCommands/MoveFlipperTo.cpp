#include "libIterativeRobot/commands/EncoderCommands/MoveFlipperTo.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

MoveFlipperTo::MoveFlipperTo(int target, int timeout, bool absolute) {
  requires(Robot::flipper);

  this->target = target;
  this->timeout = timeout;
  this->absolute = absolute;

  this->priority = 1;
}

bool MoveFlipperTo::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void MoveFlipperTo::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor

  Robot::flipper->enablePID();
  if (absolute)
    Robot::flipper->setSetpoint(target);
  else
    Robot::flipper->setSetpointRelative(target);

  startTime = pros::millis();
}

void MoveFlipperTo::execute() {
  //printf("Moving flipper to %d, flipper is at %d, at target is %d\n", Robot::flipper->getSetpoint(), Robot::flipper->getEncoderValue(), Robot::flipper->atSetpoint());
}

bool MoveFlipperTo::isFinished() {
  //return Robot::flipper->atSetpoint() || pros::millis() - startTime >= timeout;
  return Robot::flipper->atSetpoint();
  //return false;
}

void MoveFlipperTo::end() {
  // Code that runs when isFinished() returns true.
  Robot::flipper->disablePID();
}

void MoveFlipperTo::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
  Robot::flipper->disablePID();
}
