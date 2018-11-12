#include "libIterativeRobot/commands/EncoderCommands/DriveToPosition.h"
#include "libIterativeRobot/Robot.h"

DriveToPosition::DriveToPosition(int leftTarget, int rightTarget, int motorSpeed) {
  requires(Robot::base);
  this->priority = 1;
  this->leftTarget = leftTarget;
  this->rightTarget = rightTarget;
  this->motorSpeed = motorSpeed;
}

bool DriveToPosition::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void DriveToPosition::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  Robot::base->moveBaseTo(leftTarget, rightTarget, motorSpeed);
}

void DriveToPosition::execute() {
  // Code that runs when this command is scheduled to run
}

bool DriveToPosition::isFinished() {
  return Robot::base->baseAtTarget(); // This is the default va  lue anyways, so this method can be removed
}

void DriveToPosition::end() {
  // Code that runs when isFinished() returns true.
}

void DriveToPosition::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
