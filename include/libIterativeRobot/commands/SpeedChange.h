#ifndef _COMMANDS_SPEEDCHANGE_H_
#define _COMMANDS_SPEEDCHANGE_H_

#include "libIterativeRobot/commands/Command.h"

class SpeedChange : public libIterativeRobot::Command {
  private:
    float multiplier;
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    SpeedChange(float multiplier);
};

#endif // _COMMANDSSPEEDCHANGE_H_
