#ifndef _COMMANDS_STOPFLIPPER_H_
#define _COMMANDS_STOPFLIPPER_H_

#include "libIterativeRobot/commands/Command.h"

class StopFlipper: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    StopFlipper();
  private:
};

#endif // _COMMANDS_STOPFLIPPER_H_
