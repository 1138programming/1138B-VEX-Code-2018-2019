#include "libIterativeRobot/commands/OICommands/FlipperControl.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

FlipperControl::FlipperControl(int speed) {
  requires(Robot::flipper);
  this->priority = 2;
  this->speed = speed;
}

bool FlipperControl::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void FlipperControl::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  // printf("Flipper control initialized\n");
  //Robot::flipper->disablePID();
  //printf("Flipper control initialized\n");
}

void FlipperControl::execute() {
  printf("Flipper control running\n");
  Robot::flipper->move(speed);
}

bool FlipperControl::isFinished() {
  return true;
}

void FlipperControl::end() {
  // Code that runs when isFinished() returns true.
  //Robot::flipper->lock();
}

void FlipperControl::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
