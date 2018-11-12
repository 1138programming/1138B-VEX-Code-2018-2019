#include "libIterativeRobot/commands/DefaultCommands/StopFlipper.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

StopFlipper::StopFlipper() {
  requires(Robot::flipper);
  this->priority = DefaultCommandPriority; // Lowest priority
}

bool StopFlipper::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void StopFlipper::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  //Robot::flipper->lock();
  //Robot::flipper->enablePID();
}

void StopFlipper::execute() {
  Robot::flipper->move(0);
  //printf("Stopping flipper\n");
}

bool StopFlipper::isFinished() {
  return false;
}

void StopFlipper::end() {
  // Code that runs when isFinished() returns true.
}

void StopFlipper::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
