#include "libIterativeRobot/commands/AutonCommandGroups/FrontTileAuton.h"

#include "libIterativeRobot/commands/TimeCommands/MoveBaseFor.h"

FrontTileAuton::FrontTileAuton(bool isRed) {
    addSequentialCommand(new MoveBaseFor(1000, 200, 200)); // duration, left, right
    addSequentialCommand(new MoveBaseFor(750, (isRed ? 1 : -1) * 200, (isRed ? 1 : -1) * -200)); // duration, left, right
    addSequentialCommand(new MoveBaseFor(1500, 200, 200));
}