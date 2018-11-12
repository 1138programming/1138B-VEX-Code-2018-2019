#include "libIterativeRobot/commands/BlueAutonWaitTimes.h"
#include "libIterativeRobot/commands/Delay.h"
#include "libIterativeRobot/commands/MoveBaseTo.h"
#include "libIterativeRobot/commands/MoveBaseFor.h"
#include "libIterativeRobot/commands/MoveFlipperFor.h"
#include "libIterativeRobot/commands/MoveFlipperTo.h"

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
