#include "libIterativeRobot/commands/EncoderCommands/MoveCollectorTo.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

MoveCollectorTo::MoveCollectorTo(int target, int timeout, bool absolute) {
  requires(Robot::flipper);

  this->target = target;
  this->timeout = timeout;
  this->absolute = absolute;

  this->priority = 3;
}

bool MoveCollectorTo::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void MoveCollectorTo::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor

  Robot::catapult->enablePID();
  if (absolute)
    Robot::catapult->setSetpoint(target);
  else
    Robot::catapult->setSetpointRelative(target);

  startTime = pros::millis();
}

void MoveCollectorTo::execute() {
  //printf("Moving flipper to %d, flipper is at %d, at target is %d\n", Robot::flipper->getSetpoint(), Robot::flipper->getEncoderValue(), Robot::flipper->atSetpoint());
}

bool MoveCollectorTo::isFinished() {
  //return Robot::flipper->atSetpoint() || pros::millis() - startTime >= timeout;
  return Robot::flipper->atSetpoint();
  //return false;
}

void MoveCollectorTo::end() {
  // Code that runs when isFinished() returns true.
  Robot::flipper->disablePID();
}

void MoveCollectorTo::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
  Robot::flipper->disablePID();
}
