#ifndef _SUBSYSTEMS_BASE_H_
#define _SUBSYSTEMS_BASE_H_

#include "./Subsystem.h"
#include "api.h"

class Base : public libIterativeRobot::Subsystem {
  private:
    // Base motors
    Motor* leftFrontMotor;
    Motor* leftBackMotor;

    Motor* rightFrontMotor;
    Motor* rightBackMotor;

    PIDController* leftController;
    PIDController* rightController;

  public:
    void initDefaultCommand();
    void move(int left, int right);
    void moveBaseTo(int leftTarget, int rightTarget, int motorSpeed = 0);
    bool baseAtTarget();
    void setSetpoint(int leftSetpoint, int rightSetpoint);
    void setSetpointRelative(int leftSetpoint, int rightSetpoint);
    int getSetpointLeft();
    int getSetpointRight();
    int getOutputLeft();
    int getOutputRight();
    bool atSetpoint();
    void disablePID();
    void enablePID();
    void setMaxPIDSpeed(int maxSpeed = KMaxMotorSpeed);
    void setMultiplier(float multiplier);
    std::int32_t getLeftEncoder();
    std::int32_t getRightEncoder();
    Base();
};

#endif // _SUBSYSTEMS_BASE_H_
