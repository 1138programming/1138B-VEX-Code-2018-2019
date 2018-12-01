#include "libIterativeRobot/commands/OICommands/LoadCatapult.h"
#include "libIterativeRobot/commands/EncoderCommands/MoveCatapultTo.h"
#include "libIterativeRobot/commands/TimeCommands/Delay.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

LoadCatapult::LoadCatapult() {
  requires(Robot::catapult);
  this->priority = 2;
}

bool LoadCatapult::canRun() {
  printf("Load catapult checking if can run\n");
  return true;
}

void LoadCatapult::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  printf("Load catapult init\n");
}

void LoadCatapult::execute() {
  int target = -thirdRotation;
  printf("Target value is %d, priority is %d\n", target, priority);
  Command* moveCatapultTo = new MoveCatapultTo(target, 2000, false);
  moveCatapultTo->run();
}

bool LoadCatapult::isFinished() {
  printf("Load catapult checking if finished\n");
  return true;
}

void LoadCatapult::end() {
  // Code that runs when isFinished() returns true.
  //Robot::catapult->lock();
  printf("Load catapult ended\n");
}

void LoadCatapult::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
  printf("Load catapult interrupted\n");
}
