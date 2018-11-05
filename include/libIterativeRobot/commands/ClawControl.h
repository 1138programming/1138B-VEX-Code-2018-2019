#ifndef _COMMANDS_CLAWCONTROL_H_
#define _COMMANDS_CLAWCONTROL_H_

#include "libIterativeRobot/commands/Command.h"

class ClawControl: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    ClawControl();
  private:
    bool Up;
};

#endif // _COMMANDS_CLAWCONTROL_H_
