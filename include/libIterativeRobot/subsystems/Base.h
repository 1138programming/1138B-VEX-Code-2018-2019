#ifndef _SUBSYSTEMS_BASE_H_
#define _SUBSYSTEMS_BASE_H_

#include "./Subsystem.h"
#include "api.h"

class Base : public libIterativeRobot::Subsystem {
  private:
    // Base motors
    Motor* leftFrontMotor;
    Motor* leftMiddleMotor1;
    Motor* leftMiddleMotor2;
    Motor* leftBackMotor;

    Motor* rightFrontMotor;
    Motor* rightMiddleMotor1;
    Motor* rightMiddleMotor2;
    Motor* rightBackMotor;

  public:
    void initDefaultCommand();
    void move(int left, int right);
    Base();
};

#endif // _SUBSYSTEMS_BASE_H_
