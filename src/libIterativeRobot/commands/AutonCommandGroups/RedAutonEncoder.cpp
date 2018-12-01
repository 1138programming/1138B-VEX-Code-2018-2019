#include "libIterativeRobot/commands/AutonCommandGroups/RedAutonEncoder.h"
#include "libIterativeRobot/commands/TimeCommands/Delay.h"
#include "libIterativeRobot/commands/EncoderCommands/MoveBaseTo.h"
#include "libIterativeRobot/commands/TimeCommands/MoveBaseFor.h"
#include "libIterativeRobot/commands/TimeCommands/MoveFlipperFor.h"
#include "libIterativeRobot/commands/EncoderCommands/MoveFlipperTo.h"
#include "libIterativeRobot/commands/EncoderCommands/MoveCatapultTo.h"
#include "libIterativeRobot/commands/OICommands/LoadCatapult.h"

RedAutonEncoder::RedAutonEncoder() {
  addSequentialCommand(new MoveFlipperTo(-1600));
  addSequentialCommand(new MoveCatapultTo(-15000, 5000, false));
  addSequentialCommand(new MoveBaseTo(1300, 0, 100));
  addSequentialCommand(new MoveBaseTo(1200, 800, 100));
  addSequentialCommand(new MoveBaseTo(700, 1000, 100));
  addSequentialCommand(new MoveBaseTo(700, 700));
  addSequentialCommand(new MoveBaseTo(-600, -600, 100));
  addSequentialCommand(new MoveBaseTo(-1000, 1000, 100));
  addSequentialCommand(new MoveBaseTo(2500, 2500));
}
