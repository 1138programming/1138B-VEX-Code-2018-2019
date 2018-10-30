#include "main.h"
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
