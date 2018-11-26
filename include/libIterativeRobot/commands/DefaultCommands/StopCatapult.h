#ifndef _COMMANDS_STOPCATAPULT_H_
#define _COMMANDS_STOPCATAPULT_H_

#include "libIterativeRobot/commands/Command.h"

class StopCatapult: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    StopCatapult();
  private:
};

#endif // _COMMANDS_STOPCATAPULT_H_
