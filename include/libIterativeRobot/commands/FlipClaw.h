#ifndef _COMMANDS_FLIPCLAW_H_
#define _COMMANDS_FLIPCLAW_H_

#include "libIterativeRobot/commands/Command.h"

class FlipClaw: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    FlipClaw();
};

#endif // _COMMANDS_FLIPCLAW_H_
