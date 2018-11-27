#ifndef _COMMANDS_FLIPPREMOVE_H_
#define _COMMANDS_FLIPPREMOVE_H_

#include "libIterativeRobot/commands/Command.h"

class FlipperMove: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    FlipperMove();
  private:
};

#endif // _COMMANDS_FLIPPREMOVE_H_
