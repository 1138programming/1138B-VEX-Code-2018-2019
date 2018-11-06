#include "libIterativeRobot/commands/FlipperUp.h"
#include "libIterativeRobot/Robot.h"

FlipperUp::FlipperUp(std::int32_t target) {
  this->target = target;
  requires(Robot::flipper);
}

bool FlipperUp::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void FlipperUp::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void FlipperUp::execute() {
  // Code that runs when this command is scheduled to run
  std::int32_t position = Robot::flipper->getEncoderValue();
  if (position > target) {
    Robot::flipper->move(-127);
  } else if (position < target) {
    Robot::flipper->move(127);
  } else {
    Robot::flipper->move(0);
  }
}

bool FlipperUp::isFinished() {
  return threshold(target - Robot::flipper->getEncoderValue(), 20); // This is the default value anyways, so this method can be removed
}

void FlipperUp::end() {
  // Code that runs when isFinished() returns true.
  Robot::flipper->move(0);
}

void FlipperUp::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
