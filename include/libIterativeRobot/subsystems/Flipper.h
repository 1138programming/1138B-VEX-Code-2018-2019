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
    bool atSetpoint();
    void loop();
    void lock();
    void disablePID();
    void enablePID();
    std::int32_t getEncoderValue();
    Flipper();
};

#endif // _SUBSYSTEMS_FLIPPER_H_
