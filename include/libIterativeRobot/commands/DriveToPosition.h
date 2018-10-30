#ifndef _COMMANDS_DRIVETOPOSITION_H_
#define _COMMANDS_DRIVETOPOSITION_H_

#include "libIterativeRobot/commands/Command.h"

class DriveToPosition : public libIterativeRobot::Command {
  private:
    int leftTarget;
    int rightTarget;
    int motorSpeed;
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    DriveToPosition(int leftTarget, int rightTarget);
    DriveToPosition(int leftTarget, int rightTarget, int motorSpeed);
};

#endif // _COMMANDS_DRIVETOPOSITION_H_
