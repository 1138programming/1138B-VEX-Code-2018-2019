#ifndef _SUBSYSTEMS_FLIPPER_H_
#define _SUBSYSTEMS_FLIPPER_H_

#include "./Subsystem.h"
#include "api.h"

class Flipper : public libIterativeRobot::Subsystem {
  private:
    // Flipper motors
    Motor* flipperMotor;

    PIDController* flipperController;

  public:
    void initDefaultCommand();
    void move(int speed);
    void setSetpoint(int setpoint);
    int getSetpoint();
    void setSetpointRelative(int setpoint);
    bool atSetpoint();
    void disablePID();
    void enablePID();
    void setMaxPIDSpeed(int maxSpeed = KMaxMotorSpeed);
    std::int32_t getEncoderValue();
    Flipper();
};

#endif // _SUBSYSTEMS_FLIPPER_H_
