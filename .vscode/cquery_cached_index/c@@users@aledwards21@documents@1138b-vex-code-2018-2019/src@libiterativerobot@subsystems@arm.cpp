#include "main.h"
#include "libIterativeRobot/commands/StopArm.h"

Arm::Arm() {
  // Get arm motors
  firstArmMotor = Motor::getMotor(firstArmPort);
  secondArmMotor = Motor::getMotor(secondArmPort);

  // Add all follower motors
  firstArmMotor->addFollower(secondArmMotor);

  // Reverse motors as necessary
  secondArmMotor->reverse();

  armController = new PIDController(firstArmMotor, 0.32, 0, 0.05);
}

void Arm::initDefaultCommand() {
  setDefaultCommand(new StopArm());
}

/**
 * Move the arm
 * @param left - speed of the left side
 * @param right - speed of the right side
 */
void Arm::move(int speed) {
  //printf("Arm speed is %d\n", speed);
  firstArmMotor->setSpeed(speed);
}

void Arm::setSetpoint(int setpoint) {
  armController->setSetpoint(setpoint);
}

bool Arm::atSetpoint() {
  return armController->atSetpoint();
}

void Arm::loop() {
  armController->loop();
}

void Arm::lock() {
  armController->lock();
}

void Arm::disablePID() {
  armController->enabled = false;
}

void Arm::enablePID() {
  armController->enabled = true;
}

std::int32_t Arm::getEncoderValue() {
  return armMotor->getEncoderValue();
}
