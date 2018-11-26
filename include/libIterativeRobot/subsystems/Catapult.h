#ifndef _SUBSYSTEMS_CATAPULT_H_
#define _SUBSYSTEMS_CATAPULT_H_

#include "./Subsystem.h"

class Catapult : public libIterativeRobot::Subsystem {
  private:
    Motor* firstCatapultMotor;
    Motor* secondCatapultMotor;

    //PIDController* controller; // Probably won't be needed
  public:
    void initDefaultCommand();
    void move(int speed);
    Catapult();
};

#endif // _SUBSYSTEMS_CATAPULT_H_
