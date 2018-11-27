#include "main.h"
#include "libIterativeRobot/commands/DefaultCommands/StopCatapult.h"

Catapult::Catapult() {
  // Set up motors
  firstCatapultMotor = Motor::getMotor(firstCatapultPort);
  secondCatapultMotor = Motor::getMotor(secondCatapultPort);

  catapultController = new PIDController(firstCatapultMotor, 0.5, 0, 0);

  firstCatapultMotor->reverse();

  firstCatapultMotor->addFollower(secondCatapultMotor);
}

void Catapult::initDefaultCommand() {
  // Setup up a default command here
  setDefaultCommand(new StopCatapult());
}

void Catapult::move(int speed) {
  firstCatapultMotor->setSpeed(speed);
}

void Catapult::setSetpoint(int setpoint) {
  catapultController->setSetpoint(setpoint);
}

int Catapult::getSetpoint() {
  catapultController->getSetpoint();
}

void Catapult::setSetpointRelative(int setpoint) {
  catapultController->setSetpointRelative(setpoint);
}

bool Catapult::atSetpoint() {
  return catapultController->atSetpoint();
}

void Catapult::disablePID() {
  catapultController->enabled = false;
}

void Catapult::enablePID() {
  catapultController->enabled = true;
}
