#include "main.h"
#include "math.h"
#include "libIterativeRobot/commands/DefaultCommands/StopBase.h"


Base::Base() {
  // Set up motors
  leftFrontMotor = Motor::getMotor(leftFrontBasePort);
  leftBackMotor = Motor::getMotor(leftBackBasePort);

  rightFrontMotor = Motor::getMotor(rightFrontBasePort);
  rightBackMotor = Motor::getMotor(rightBackBasePort);

  leftFrontMotor->addFollower(leftBackMotor);

  rightFrontMotor->addFollower(rightBackMotor);

  leftController = new PIDController(leftFrontMotor, 0.61, 0, 0.008);
  rightController = new PIDController(rightFrontMotor, 0.6, 0, 0.008);

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
  leftBackMotor->getMotorObject()->move_relative(leftTarget, motorSpeed ? motorSpeed : 100);

  rightFrontMotor->getMotorObject()->move_relative(rightTarget, motorSpeed ? motorSpeed : 100);
  rightBackMotor->getMotorObject()->move_relative(rightTarget, motorSpeed ? motorSpeed : 100);
}

void Base::setMultiplier(float multiplier) {
  leftFrontMotor->setMultiplier(multiplier);
  leftBackMotor->setMultiplier(multiplier);

  rightFrontMotor->setMultiplier(multiplier);
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

int Base::getSetpointLeft() {
  return leftController->getSetpoint();
}

int Base::getSetpointRight() {
  return rightController->getSetpoint();
}

int Base::getOutputLeft() {
  return leftController->getOutput();
  //return leftFrontMotor->getSlewedSpeed();
}

int Base::getOutputRight() {
  return rightController->getOutput();
  //return rightFrontMotor->getSlewedSpeed();
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
