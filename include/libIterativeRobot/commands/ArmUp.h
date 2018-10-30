#ifndef _COMMANDS_ARMUP_H_
#define _COMMANDS_ARMUP_H_

#include "libIterativeRobot/commands/Command.h"

class ArmUp : public libIterativeRobot::Command {
  private:
    std::int32_t target;
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    ArmUp(std::int32_t target);
};

#endif // _COMMANDS_ARMUP_H_
