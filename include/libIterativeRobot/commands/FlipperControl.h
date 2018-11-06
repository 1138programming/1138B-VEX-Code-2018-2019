#ifndef _COMMANDS_FLIPPERCONTROL_H_
#define _COMMANDS_FLIPPERCONTROL_H_

#include "libIterativeRobot/commands/Command.h"

class FlipperControl: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    FlipperControl();
  private:
    bool Up;
};

#endif // _COMMANDS_FLIPPERCONTROL_H_
