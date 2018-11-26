#include "libIterativeRobot/commands/DefaultCommands/StopCatapult.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

StopCatapult::StopCatapult() {
  requires(Robot::catapult);
  this->priority = DefaultCommandPriority; // Lowest priority
}

bool StopCatapult::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void StopCatapult::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  //Robot::flipper->lock();
  //Robot::flipper->enablePID();
}

void StopCatapult::execute() {
  Robot::flipper->move(0);
  //printf("Stopping flipper\n");
}

bool StopCatapult::isFinished() {
  return false;
}

void StopCatapult::end() {
  // Code that runs when isFinished() returns true.
}

void StopCatapult::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
