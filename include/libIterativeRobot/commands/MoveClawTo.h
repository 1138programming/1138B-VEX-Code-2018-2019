#ifndef _COMMANDS_MOVECLAWTO_H_
#define _COMMANDS_MOVECLAWTO_H_

#include "libIterativeRobot/commands/Command.h"

class MoveClawTo: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    MoveClawTo(int target);
  private:
    int target = 0;
};

#endif // _COMMANDS_MOVECLAWTO_H_
