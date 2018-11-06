#ifndef _COMMANDS_FLIPPERUP_H_
#define _COMMANDS_FLIPPERUP_H_

#include "libIterativeRobot/commands/Command.h"

class FlipperUp : public libIterativeRobot::Command {
  private:
    std::int32_t target;
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    FlipperUp(std::int32_t target);
};

#endif // _COMMANDS_FLIPPERUP_H_
