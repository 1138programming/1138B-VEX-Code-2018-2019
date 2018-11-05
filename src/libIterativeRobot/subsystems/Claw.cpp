#include "main.h"
#include "libIterativeRobot/commands/StopClaw.h"

Claw::Claw() {
  // Get arm motors
  clawMotor = Motor::getMotor(clawPort);

  clawController = new PIDController(clawMotor, 0.32, 0, 0.05);
}

void Claw::initDefaultCommand() {
  setDefaultCommand(new StopClaw());
}

/**
 * Move the arm
 * @param left - speed of the left side
 * @param right - speed of the right side
 */
void Claw::move(int speed) {
  //printf("Claw speed is %d\n", speed);
  clawMotor->setSpeed(speed);
}

void Claw::setSetpoint(int setpoint) {
  clawController->setSetpoint(setpoint);
}

bool Claw::atSetpoint() {
  return clawController->atSetpoint();
}

void Claw::loop() {
  clawController->loop();
}

void Claw::lock() {
  clawController->lock();
}

void Claw::disablePID() {
  clawController->enabled = false;
}

void Claw::enablePID() {
  clawController->enabled = true;
}

std::int32_t Claw::getEncoderValue() {
  return clawMotor->getEncoderValue();
}

int Claw::getSetpoint() {
  return clawController->getSetpoint();
}
