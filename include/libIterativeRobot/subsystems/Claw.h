#ifndef _SUBSYSTEMS_CLAW_H_
#define _SUBSYSTEMS_CLAW_H_

#include "./Subsystem.h"
#include "api.h"

class Claw : public libIterativeRobot::Subsystem {
  private:
    // Claw motors
    Motor* clawMotor;

    PIDController* clawController;

  public:
    void initDefaultCommand();
    void move(int speed);
    void setSetpoint(int setpoint);
    bool atSetpoint();
    void loop();
    void lock();
    void disablePID();
    void enablePID();
    std::int32_t getEncoderValue();
    int getSetpoint();
    Claw();
};

#endif // _SUBSYSTEMS_CLAW_H_
