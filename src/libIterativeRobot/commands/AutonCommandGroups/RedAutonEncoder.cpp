#include "libIterativeRobot/commands/AutonCommandGroups/RedAutonEncoder.h"
#include "libIterativeRobot/commands/TimeCommands/Delay.h"
#include "libIterativeRobot/commands/EncoderCommands/MoveBaseTo.h"
#include "libIterativeRobot/commands/TimeCommands/MoveBaseFor.h"
#include "libIterativeRobot/commands/TimeCommands/MoveFlipperFor.h"
#include "libIterativeRobot/commands/EncoderCommands/MoveFlipperTo.h"

RedAutonEncoder::RedAutonEncoder() {
  //addSequentialCommand(new MoveBaseTo(1000, 1000));
  addSequentialCommand(new MoveBaseTo(300, 300));
  addParallelCommand(new Delay(1000));
  addSequentialCommand(new MoveFlipperFor(200, 127));
  addParallelCommand(new Delay(500));
  addSequentialCommand(new MoveBaseTo(3000, 3000)); // Move forward
  addParallelCommand(new MoveFlipperTo(0, 1000, true)); // Reset flipper
  addSequentialCommand(new MoveBaseTo(-1000, -1000)); // Move back
  addSequentialCommand(new MoveBaseTo(800, -800));
  addSequentialCommand(new MoveBaseTo(1200, 1200));
  addSequentialCommand(new MoveBaseTo(-800, 800));
  addSequentialCommand(new MoveBaseTo(1000, 1000));
  addParallelCommand(new Delay(1000));
  addParallelCommand(new MoveFlipperFor(1000, 80));
  addSequentialCommand(new MoveBaseTo(-500, -500)); // Move backwards from 2nd cap
  addSequentialCommand(new MoveBaseTo(-900, 900));
  addSequentialCommand(new MoveBaseTo(4000, 4000));
  addParallelCommand(new MoveFlipperFor(2000, -127));
}
