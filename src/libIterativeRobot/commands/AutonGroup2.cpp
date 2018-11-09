#include "libIterativeRobot/commands/AutonGroup2.h"
#include "libIterativeRobot/commands/Delay.h"
#include "libIterativeRobot/commands/MoveBaseTo.h"
#include "libIterativeRobot/commands/MoveFlipperFor.h"

AutonGroup2::AutonGroup2() {
  addSequentialCommand(new MoveBaseTo(200, 200));
  addSequentialCommand(new MoveFlipperFor(200, 127, false));
  addParallelCommand(new Delay(500));
  addSequentialCommand(new MoveBaseTo(3100, 3100));
  addSequentialCommand(new MoveBaseTo(-1000, -1000));
  addSequentialCommand(new MoveBaseTo(-800, 800));
  addSequentialCommand(new MoveBaseTo(1200, 1200));
  addSequentialCommand(new MoveBaseTo(700, -700));
  addSequentialCommand(new MoveBaseTo(1200, 1200));
  addParallelCommand(new Delay(1000));
  addParallelCommand(new MoveFlipperFor(1000, 80, false));
  addSequentialCommand(new MoveBaseTo(-900, -900));
  addSequentialCommand(new MoveBaseTo(900, -900));
  addSequentialCommand(new MoveBaseTo(4000, 4000));
  addParallelCommand(new MoveFlipperFor(2000, -127, false));
}
