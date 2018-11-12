#include "libIterativeRobot/commands/TimeCommands/MoveFlipperFor.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

MoveFlipperFor::MoveFlipperFor(int duration, int speed, bool endWithBase, int threshold) {
  requires(Robot::flipper);
  this->priority = 1;
  this->duration = duration;
  this->speed = speed;
  this->endWithBase = endWithBase;
  this->threshold = threshold;
}

bool MoveFlipperFor::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void MoveFlipperFor::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  startTime = pros::millis();
  Robot::flipper->disablePID();
}

void MoveFlipperFor::execute() {
  //printf("Moving claw to: %d\n", target);
  Robot::flipper->move(speed);
  printf("Moving flipper, speed is %d\n", speed);
}

bool MoveFlipperFor::isFinished() {
  if (endWithBase) {
    if (pros::millis() - startTime >= threshold) {
      return Robot::base->atSetpoint() || pros::millis() - startTime >= duration;
    } else {
      return pros::millis() - startTime >= duration;
    }
  } else {
    return pros::millis() - startTime >= duration;
  }
}

void MoveFlipperFor::end() {
  // Code that runs when isFinished() returns true.
  Robot::flipper->move(0);
}

void MoveFlipperFor::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
  Robot::flipper->move(0);
}
