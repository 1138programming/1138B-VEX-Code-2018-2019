#include "libIterativeRobot/commands/AutonGroup1.h"
#include "libIterativeRobot/commands/Delay.h"
#include "libIterativeRobot/commands/MoveBaseTo.h"
#include "libIterativeRobot/commands/MoveFlipperFor.h"
#include "libIterativeRobot/commands/MoveFlipperTo.h"

AutonGroup1::AutonGroup1() {
  addSequentialCommand(new MoveBaseTo(300, 300, 2000));
  addParallelCommand(new Delay(1000));
  addSequentialCommand(new MoveFlipperFor(200, 127, false));
  addParallelCommand(new Delay(500));
  addSequentialCommand(new MoveBaseTo(3000, 3000, 2000)); // Move forward
  addParallelCommand(new MoveFlipperTo(0, 1000, true)); // Reset flipper
  addSequentialCommand(new MoveBaseTo(-1000, -1000, 2000)); // Move back
  addSequentialCommand(new MoveBaseTo(800, -800, 2000));
  addSequentialCommand(new MoveBaseTo(1200, 1200, 2000));
  addSequentialCommand(new MoveBaseTo(-800, 800, 2000));
  addSequentialCommand(new MoveBaseTo(1000, 1000, 2000));
  addParallelCommand(new Delay(1000));
  addParallelCommand(new MoveFlipperFor(1000, 80, false));
  addSequentialCommand(new MoveBaseTo(-500, -500, 2000)); // Move backwards from 2nd cap
  addSequentialCommand(new MoveBaseTo(-900, 900, 2000));
  addSequentialCommand(new MoveBaseTo(4000, 4000, 2000));
  addParallelCommand(new MoveFlipperFor(2000, -127, false));
}
