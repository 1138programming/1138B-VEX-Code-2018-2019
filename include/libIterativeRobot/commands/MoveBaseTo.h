#ifndef _COMMANDS_MOVEBASETO_H_
#define _COMMANDS_MOVEBASETO_H_

#include "libIterativeRobot/commands/Command.h"

class MoveBaseTo: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    MoveBaseTo(int leftTarget = 0, int rightTarget = 0, bool absolute = false, float multiplier = 1);
  private:
    int leftTarget = 0;
    int rightTarget = 0;
    bool absolute = false;
    float multiplier = 1;
};

#endif // _COMMANDS_MOVEBASETO_H_
