#include "libIterativeRobot/commands/AutonCommandGroups/BlueAutonWaitTimes.h"
#include "libIterativeRobot/commands/TimeCommands/Delay.h"
#include "libIterativeRobot/commands/EncoderCommands/MoveBaseTo.h"
#include "libIterativeRobot/commands/TimeCommands/MoveBaseFor.h"
#include "libIterativeRobot/commands/TimeCommands/MoveFlipperFor.h"
#include "libIterativeRobot/commands/EncoderCommands/MoveFlipperTo.h"

BlueAutonWaitTimes::BlueAutonWaitTimes() {
  addSequentialCommand(new MoveBaseFor(150));
  addSequentialCommand(new Delay(500));
  addSequentialCommand(new MoveFlipperFor(200, 127));
  addSequentialCommand(new Delay(500));
  addSequentialCommand(new MoveBaseFor(1000));
  addParallelCommand(new MoveFlipperTo(0, 1000, true));
  addSequentialCommand(new Delay(500));
  addSequentialCommand(new MoveBaseFor(80, -127, -127));
  addSequentialCommand(new Delay(500));
  addSequentialCommand(new MoveBaseFor(400, -127, 127));
  addSequentialCommand(new Delay(500));
  addSequentialCommand(new MoveBaseFor(1375, -127, -127));
}
