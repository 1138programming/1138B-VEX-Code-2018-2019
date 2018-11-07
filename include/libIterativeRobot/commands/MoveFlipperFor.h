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
    MoveFlipperFor(int duration, int speed = 127, bool endWithBase = false);
  private:
    int duration = 0;
    int speed = 127;
    bool endWithBase = false;
    int startTime;
};

#endif // _COMMANDS_MOVEFLIPPERFOR_H_
