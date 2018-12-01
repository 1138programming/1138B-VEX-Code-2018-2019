#ifndef _COMMANDS_LOADCATAPULT_H_
#define _COMMANDS_LOADCATAPULT_H_

#include "libIterativeRobot/commands/Command.h"

class LoadCatapult: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    LoadCatapult();
  private:
    const int offset = -4500;
    const int thirdRotation = (int)(ticksPerRev36 * 25 / 3);
};

#endif // _COMMANDS_LOADCATAPULT_H_
