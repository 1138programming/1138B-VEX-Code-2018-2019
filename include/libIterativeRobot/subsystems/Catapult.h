#ifndef _SUBSYSTEMS_CATAPULT_H_
#define _SUBSYSTEMS_CATAPULT_H_

#include "./Subsystem.h"

class Catapult : public libIterativeRobot::Subsystem {
  private:
    Motor* firstCatapultMotor;
    Motor* secondCatapultMotor;

    PIDController* catapultController;

    //PIDController* controller; // Probably won't be needed
  public:
    void initDefaultCommand();
    void move(int speed);
    void setSetpoint(int setpoint);
    int getSetpoint();
    void setSetpointRelative(int setpoint);
    bool atSetpoint();
    void disablePID();
    void enablePID();
    Catapult();
};

#endif // _SUBSYSTEMS_CATAPULT_H_
