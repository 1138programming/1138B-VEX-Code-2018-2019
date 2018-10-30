#include "main.h"
#include "math.h"
#include "libIterativeRobot/commands/StopBase.h"


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
