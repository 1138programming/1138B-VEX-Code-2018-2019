#include "main.h"
#include "libIterativeRobot/commands/DefaultCommands/StopCatapult.h"

Catapult::Catapult() {
  // Set up motors
  firstCatapultMotor = Motor::getMotor(firstCatapultPort);
  secondCatapultMotor = Motor::getMotor(secondCatapultPort);

  secondCatapultMotor->reverse();

  firstCatapultMotor->addFollower(secondCatapultMotor);
}

void Catapult::initDefaultCommand() {
  // Setup up a default command here
  setDefaultCommand(new StopCatapult());
}

void Catapult::move(int speed) {
  firstCatapultMotor->setSpeed(speed);
}
