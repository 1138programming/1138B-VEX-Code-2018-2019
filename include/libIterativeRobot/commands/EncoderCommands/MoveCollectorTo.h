#ifndef _COMMANDS_MOVECOLLECTORTO_H_
#define _COMMANDS_MOVECOLLECTORTO_H_

#include "libIterativeRobot/commands/Command.h"

class MoveCollectorTo: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    MoveCollectorTo(int target, int timeout = 2000, bool absolute = false);
  private:
    int target = 0;
    int startTime = 0;
    int timeout = 0;
    bool absolute = false;
};

#endif // _COMMANDS_MOVECOLLECTORTO_H_
