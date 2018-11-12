#ifndef _COMMANDS_MOVEFLIPPERFOR_H_
#define _COMMANDS_MOVEFLIPPERFOR_H_

#include "libIterativeRobot/commands/Command.h"

class MoveFlipperFor: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    MoveFlipperFor(int duration, int speed = KMaxMotorSpeed, bool endWithBase = false, int threshold = 100);
  private:
    int duration = 0;
    int startTime;
    int speed = KMaxMotorSpeed;
    bool endWithBase = false;
    int threshold = 100;
};

#endif // _COMMANDS_MOVEFLIPPERFOR_H_
