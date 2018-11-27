#include "libIterativeRobot/commands/OICommands/FlipperMove.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

FlipperMove::FlipperMove() {
  requires(Robot::flipper);
  this->priority = 2;
}

bool FlipperMove::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void FlipperMove::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  // printf("Catapult control initialized\n");
  //Robot::catapult->disablePID();
  //printf("Catapult control initialized\n");
}

void FlipperMove::execute() {
  printf("Catapult control running\n");
  Robot::flipper->move(threshold(Robot::partnerController->get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y)));
}

bool FlipperMove::isFinished() {
  return true;
}

void FlipperMove::end() {
  // Code that runs when isFinished() returns true.
  //Robot::catapult->lock();
}

void FlipperMove::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
