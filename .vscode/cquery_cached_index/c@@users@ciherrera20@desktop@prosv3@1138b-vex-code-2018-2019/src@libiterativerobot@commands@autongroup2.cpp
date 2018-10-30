#include "libIterativeRobot/commands/AutonGroup2.h"
#include "libIterativeRobot/commands/MoveClawFor.h"

AutonGroup1::AutonGroup1() {
  addSequentialCommand(new MoveClawFor(1000));
  addSequentialCommand(new MoveClawFor(1000));
}
