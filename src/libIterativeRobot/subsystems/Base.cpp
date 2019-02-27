#include "main.h"
#include "math.h"
#include "libIterativeRobot/commands/DefaultCommands/StopBase.h"


Base::Base() {
  // Set up motors
  leftFrontMotor = Motor::getMotor(leftFrontBasePort);
  leftMiddleMotor1 = Motor::getMotor(leftMiddleBasePort1);
  leftMiddleMotor2 = Motor::getMotor(leftMiddleBasePort2);
  leftBackMotor = Motor::getMotor(leftBackBasePort);

  rightFrontMotor = Motor::getMotor(rightFrontBasePort);
  rightMiddleMotor1 = Motor::getMotor(rightMiddleBasePort1);
  rightMiddleMotor2 = Motor::getMotor(rightMiddleBasePort2);
  rightBackMotor = Motor::getMotor(rightBackBasePort);

  leftFrontMotor->reverse();
  leftMiddleMotor1->reverse();
  leftMiddleMotor2->reverse();
  leftBackMotor->reverse();

  leftFrontMotor->addFollower(leftMiddleMotor1);
  leftFrontMotor->addFollower(leftMiddleMotor2);
  leftFrontMotor->addFollower(leftBackMotor);

  rightFrontMotor->addFollower(rightMiddleMotor1);
  rightFrontMotor->addFollower(rightMiddleMotor2);
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
  leftFrontMotor->getMotorObject()->move_velocity(left);
  leftMiddleMotor1->getMotorObject()->move_velocity(left);
  leftMiddleMotor2->getMotorObject()->move_velocity(left);
  leftBackMotor->getMotorObject()->move_velocity(left);

  rightFrontMotor->getMotorObject()->move_velocity(-right);
  rightMiddleMotor1->getMotorObject()->move_velocity(-right);
  rightMiddleMotor2->getMotorObject()->move_velocity(-right);
  rightBackMotor->getMotorObject()->move_velocity(-right);
}
