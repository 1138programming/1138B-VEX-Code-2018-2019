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
    FlipperControl(int speed = 127);
  private:
    int speed = 0;
};

#endif // _COMMANDS_FLIPPERCONTROL_H_
