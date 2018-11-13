#include "main.h"
#include "math.h"
#include "libIterativeRobot/commands/DefaultCommands/StopBase.h"


Base::Base() {
  // Set up motors
  leftFrontMotor = Motor::getMotor(leftFrontBasePort);
  leftMiddleMotor = Motor::getMotor(leftMiddleBasePort);
  leftBackMotor = Motor::getMotor(leftBackBasePort);

  rightFrontMotor = Motor::getMotor(rightFrontBasePort);
  rightMiddleMotor = Motor::getMotor(rightMiddleBasePort);
  rightBackMotor = Motor::getMotor(rightBackBasePort);

  rightBackMotor->reverse();
  rightFrontMotor->reverse();
  leftMiddleMotor->reverse();

  leftFrontMotor->addFollower(leftMiddleMotor);
  leftFrontMotor->addFollower(leftBackMotor);

  rightFrontMotor->addFollower(rightMiddleMotor);
  rightFrontMotor->addFollower(rightBackMotor);

  leftController = new PIDController(leftFrontMotor, 0.5, 0, 0);
  rightController = new PIDController(rightFrontMotor, 0.5, 0, 0);

  leftController->setThreshold(30);
  rightController->setThreshold(30);
}

void Base::initDefaultCommand() {
  // Setup up a default command herea
  setDefaultCommand(new StopBase());
}

/**
 * Move the base
 * @param left - speed of the left side
 * @param right - speed of the right side
 */
void Base::move(int left, int right) {
  leftFrontMotor->setSpeed(left);
  rightFrontMotor->setSpeed(right);
}

void Base::moveBaseTo(int leftTarget, int rightTarget, int motorSpeed) {
  leftFrontMotor->getMotorObject()->move_relative(leftTarget, motorSpeed ? motorSpeed : 100); // TODO: Move last argument to a variable
  leftMiddleMotor->getMotorObject()->move_relative(leftTarget, motorSpeed ? motorSpeed : 100);
  leftBackMotor->getMotorObject()->move_relative(leftTarget, motorSpeed ? motorSpeed : 100);

  rightFrontMotor->getMotorObject()->move_relative(rightTarget, motorSpeed ? motorSpeed : 100);
  rightMiddleMotor->getMotorObject()->move_relative(rightTarget, motorSpeed ? motorSpeed : 100);
  rightBackMotor->getMotorObject()->move_relative(rightTarget, motorSpeed ? motorSpeed : 100);
}

void Base::setMultiplier(float multiplier) {
  leftFrontMotor->setMultiplier(multiplier);
  leftMiddleMotor->setMultiplier(multiplier);
  leftBackMotor->setMultiplier(multiplier);

  rightFrontMotor->setMultiplier(multiplier);
  rightMiddleMotor->setMultiplier(multiplier);
  rightBackMotor->setMultiplier(multiplier);
}

bool Base::baseAtTarget() {
  return abs(leftFrontMotor->getMotorObject()->get_target_position() - leftFrontMotor->getMotorObject()->get_position()) <= 5; // Tune threshold and make a varaible
}

void Base::setSetpoint(int leftSetpoint, int rightSetpoint) {
  leftController->setSetpoint(leftSetpoint);
  rightController->setSetpoint(rightSetpoint);
}

void Base::setSetpointRelative(int leftSetpoint, int rightSetpoint) {
  leftController->setSetpointRelative(leftSetpoint);
  rightController->setSetpointRelative(rightSetpoint);
}

bool Base::atSetpoint() {
  return leftController->atSetpoint() && rightController->atSetpoint();
}

void Base::enablePID() {
  leftController->enabled = true;
  rightController->enabled = true;
}

void Base::disablePID() {
  leftController->enabled = false;
  rightController->enabled = false;
}

void Base::setMaxPIDSpeed(int maxSpeed) {
  leftController->setMaxPIDSpeed(maxSpeed);
  rightController->setMaxPIDSpeed(maxSpeed);
}

std::int32_t Base::getLeftEncoder() {
  return leftFrontMotor->getEncoderValue();
}

std::int32_t Base::getRightEncoder() {
  return rightFrontMotor->getEncoderValue();
}
