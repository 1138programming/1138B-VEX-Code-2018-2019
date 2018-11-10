#include "libIterativeRobot/commands/BlueAutonEncoder.h"
#include "libIterativeRobot/commands/Delay.h"
#include "libIterativeRobot/commands/MoveBaseTo.h"
#include "libIterativeRobot/commands/MoveBaseFor.h"
#include "libIterativeRobot/commands/MoveFlipperFor.h"
#include "libIterativeRobot/commands/MoveFlipperTo.h"

BlueAutonEncoder::BlueAutonEncoder() {
  addSequentialCommand(new MoveBaseTo(300, 300));
  addParallelCommand(new Delay(1000));
  addSequentialCommand(new MoveFlipperFor(200, 127));
  addParallelCommand(new Delay(500));
  addSequentialCommand(new MoveBaseTo(2800, 3000));
  addParallelCommand(new MoveFlipperTo(0, 1000, true));
  addSequentialCommand(new MoveBaseTo(-1000, -1000)); // Back away from 1st cap
  addSequentialCommand(new MoveBaseTo(-800, 800)); // Turn
  addSequentialCommand(new MoveBaseTo(1200, 1200)); // Move forwards toward 2nd cap
  addSequentialCommand(new MoveBaseTo(800, -800)); // Turn
  addSequentialCommand(new MoveBaseTo(1000, 1000)); // Move forwards toward cap
  addParallelCommand(new Delay(1000));
  addParallelCommand(new MoveFlipperFor(1000, 80)); // Turn flipper fo flip 2nd cap
  addSequentialCommand(new MoveBaseTo(-500, -500)); // Move backwards from 2nd cap
  addSequentialCommand(new MoveBaseTo(900, -900));
  addSequentialCommand(new MoveBaseTo(4000, 4000));
  addParallelCommand(new MoveFlipperFor(2000, -127));
}
