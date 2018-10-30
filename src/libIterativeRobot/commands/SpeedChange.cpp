#include "libIterativeRobot/commands/SpeedChange.h"
#include "libIterativeRobot/Robot.h"

SpeedChange::SpeedChange(float multiplier) {
  this->multiplier = multiplier;
  requires(Robot::base);
}

bool SpeedChange::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void SpeedChange::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  Robot::base->setMultiplier(multiplier);
}

void SpeedChange::execute() {
  // Code that runs when this command is scheduled to run
}

bool SpeedChange::isFinished() {
  return true; // This is the default value anyways, so this method can be removed
}

void SpeedChange::end() {
  // Code that runs when isFinished() returns true.
}

void SpeedChange::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
