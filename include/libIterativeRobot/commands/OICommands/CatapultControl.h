#ifndef _COMMANDS_CATAPULTCONTROL_H_
#define _COMMANDS_CATAPULTCONTROL_H_

#include "libIterativeRobot/commands/Command.h"

class CatapultControl: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    CatapultControl();
  private:
};

#endif // _COMMANDS_CATAPULTCONTROL_H_
