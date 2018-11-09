#include "libIterativeRobot/commands/MoveBaseTo.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

MoveBaseTo::MoveBaseTo(int leftTarget, int rightTarget, int timeout, bool absolute) {
  requires(Robot::base);
  this->priority = 1;
  this->leftTarget = leftTarget;
  this->rightTarget = rightTarget;
  this->timeout = timeout;
  this->absolute = absolute;
}

bool MoveBaseTo::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void MoveBaseTo::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor

  //Robot::base->setMultiplier(1);

  Robot::base->enablePID();
  if (absolute)
    Robot::base->setSetpoint(leftTarget, rightTarget);
  else
    Robot::base->setSetpointRelative(leftTarget, rightTarget);

  startTime = pros::millis();
}

void MoveBaseTo::execute() {
  //printf("Moving base to: %d\n", target);
  printf("Moving base\n");
}

bool MoveBaseTo::isFinished() {
  return Robot::base->atSetpoint() || pros::millis() - startTime >= timeout;
}

void MoveBaseTo::end() {
  // Code that runs when isFinished() returns true.
  //Robot::base->lock();
  //Robot::base->setMultiplier(1);
  Robot::base->disablePID();
}

void MoveBaseTo::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
  //Robot::base->setMultiplier(1);
  Robot::base->disablePID();
}
