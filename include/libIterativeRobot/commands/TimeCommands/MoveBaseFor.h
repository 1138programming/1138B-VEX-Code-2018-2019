#ifndef _COMMANDS_MOVEBASEFOR_H_
#define _COMMANDS_MOVEBASEFOR_H_

#include "libIterativeRobot/commands/Command.h"

class MoveBaseFor: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    MoveBaseFor(int duration, int leftSpeed = KMaxMotorSpeed, int rightSpeed = KMaxMotorSpeed);
  private:
    int duration = 0;
    int startTime;
    int leftSpeed = KMaxMotorSpeed;
    int rightSpeed = KMaxMotorSpeed;
};

#endif // _COMMANDS_MOVEBASEFOR_H_
