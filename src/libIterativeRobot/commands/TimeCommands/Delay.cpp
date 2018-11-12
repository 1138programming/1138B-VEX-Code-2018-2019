#include "libIterativeRobot/commands/TimeCommands/Delay.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

Delay::Delay(int duration) {
  this->priority = 1;
  this->duration = duration;
}

bool Delay::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void Delay::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  startTime = pros::millis();
}

void Delay::execute() {
  //printf("Moving claw to: %d\n", target);
}

bool Delay::isFinished() {
    return pros::millis() - startTime >= duration;
}

void Delay::end() {
  // Code that runs when isFinished() returns true.
}

void Delay::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
