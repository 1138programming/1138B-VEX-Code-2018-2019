#include "libIterativeRobot/commands/MoveBaseFor.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

MoveBaseFor::MoveBaseFor(int duration, int leftSpeed, int rightSpeed) {
  requires(Robot::base);
  this->priority = 1;
  this->duration = duration;
  this->leftSpeed = leftSpeed;
  this->rightSpeed = rightSpeed;
}

bool MoveBaseFor::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void MoveBaseFor::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  startTime = pros::millis();
  Robot::base->disablePID();
}

void MoveBaseFor::execute() {
  //printf("Moving claw to: %d\n", target);
  Robot::base->move(leftSpeed, rightSpeed);
  //printf("Moving base, speed is %d\n", speed);
}

bool MoveBaseFor::isFinished() {
  return pros::millis() - startTime >= duration;
}

void MoveBaseFor::end() {
  // Code that runs when isFinished() returns true.
  Robot::base->move(0, 0);
}

void MoveBaseFor::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
  Robot::base->move(0, 0);
}
