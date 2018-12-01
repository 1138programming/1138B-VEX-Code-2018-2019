#include "libIterativeRobot/commands/EncoderCommands/MoveCatapultTo.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

MoveCatapultTo::MoveCatapultTo(int target, int timeout, bool absolute) {
  requires(Robot::catapult);

  this->target = target;
  this->timeout = timeout;
  this->absolute = absolute;

  this->priority = 1;
}

bool MoveCatapultTo::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void MoveCatapultTo::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor

  Robot::catapult->enablePID();
  if (absolute)
    Robot::catapult->setSetpoint(target);
  else
    Robot::catapult->setSetpointRelative(target);

  startTime = pros::millis();
}

void MoveCatapultTo::execute() {
  //printf("Moving catapult to %d, catapult is at %d, at target is %d\n", Robot::catapult->getSetpoint(), Robot::catapult->getEncoderValue(), Robot::catapult->atSetpoint());
}

bool MoveCatapultTo::isFinished() {
  //return Robot::catapult->atSetpoint() || pros::millis() - startTime >= timeout;
  return Robot::catapult->atSetpoint();
  //return false;
}

void MoveCatapultTo::end() {
  // Code that runs when isFinished() returns true.
  Robot::catapult->disablePID();
}

void MoveCatapultTo::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
  Robot::catapult->disablePID();
}
