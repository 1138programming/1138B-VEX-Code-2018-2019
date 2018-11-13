#include "main.h"
#include "libIterativeRobot/commands/DefaultCommands/StopFlipper.h"

Flipper::Flipper() {
  // Get flipper motors
  flipperMotor = Motor::getMotor(flipperPort);

  flipperController = new PIDController(flipperMotor, 0.32, 0, 0.05);
}

void Flipper::initDefaultCommand() {
  setDefaultCommand(new StopFlipper());
}

/**
 * Move the flipper
 * @param left - speed of the left side
 * @param right - speed of the right side
 */
void Flipper::move(int speed) {
  //printf("Flipper speed is %d\n", speed);
  flipperMotor->setSpeed(speed);
}

void Flipper::setSetpoint(int setpoint) {
  flipperController->setSetpoint(setpoint);
}

void Flipper::setSetpointRelative(int setpoint) {
  flipperController->setSetpointRelative(setpoint);
}

bool Flipper::atSetpoint() {
  return flipperController->atSetpoint();
}

void Flipper::disablePID() {
  flipperController->enabled = false;
}

void Flipper::enablePID() {
  flipperController->enabled = true;
}

void Flipper::setMaxPIDSpeed(int maxSpeed) {
  flipperController->setMaxPIDSpeed(maxSpeed);
}

std::int32_t Flipper::getEncoderValue() {
  return flipperMotor->getEncoderValue();
}
