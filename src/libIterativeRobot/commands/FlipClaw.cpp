#include "libIterativeRobot/commands/FlipClaw.h"
#include "libIterativeRobot/commands/MoveClawTo.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

FlipClaw::FlipClaw() {
  requires(Robot::claw);
  this->priority = 1;
}

bool FlipClaw::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void FlipClaw::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void FlipClaw::execute() {
  //printf("Moving claw to: %d\n", target);
}

bool FlipClaw::isFinished() {
  return true;
}

void FlipClaw::end() {
  // Code that runs when isFinished() returns true.
  //Robot::claw->lock();
  //int target = (ticksPerRev18 / 2) + (int)(floor(Robot::claw->getEncoderValue() / ticksPerRev18) * ticksPerRev18);
  int pos = Robot::claw->getEncoderValue() - (int)(floor(Robot::claw->getEncoderValue() / ticksPerRev18) * ticksPerRev18), target;

  if ((int)(ticksPerRev18 / 4) < pos && pos < (int)(3 * ticksPerRev18 / 4)) {
    target = (int)(floor(Robot::claw->getEncoderValue() / ticksPerRev18) * ticksPerRev18);
  } else {
    target = (ticksPerRev18 / 2) + (int)(floor(Robot::claw->getEncoderValue() / ticksPerRev18) * ticksPerRev18);
  }

  Command* moveClawTo = new MoveClawTo(target);
  moveClawTo->run();
}

void FlipClaw::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
