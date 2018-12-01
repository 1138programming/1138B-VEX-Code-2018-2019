#include "libIterativeRobot/commands/OICommands/CatapultControl.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

CatapultControl::CatapultControl() {
  requires(Robot::catapult);
  this->priority = 2;
}

bool CatapultControl::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void CatapultControl::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  // printf("Catapult control initialized\n");
  //Robot::catapult->disablePID();
  //printf("Catapult control initialized\n");
}

void CatapultControl::execute() {
  printf("Catapult control running, encoder value is %d\n", Robot::catapult->getEncoderValue());
  Robot::catapult->move(threshold(Robot::partnerController->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)));
}

bool CatapultControl::isFinished() {
  return true;
}

void CatapultControl::end() {
  // Code that runs when isFinished() returns true.
  //Robot::catapult->lock();
}

void CatapultControl::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
