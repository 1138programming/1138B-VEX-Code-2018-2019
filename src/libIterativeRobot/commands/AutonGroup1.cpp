#include "libIterativeRobot/commands/AutonGroup1.h"
#include "libIterativeRobot/commands/MoveBaseTo.h"
#include "libIterativeRobot/commands/MoveFlipperFor.h"

AutonGroup1::AutonGroup1() {
  //addSequentialCommand(new MoveFlipperFor(5000, 127, false));
  addSequentialCommand(new MoveBaseTo(3000, 3000));
  //addSequentialCommand(new MoveFlipperFor(500, 0, false));
  addSequentialCommand(new MoveBaseTo(-500, -500));
  addSequentialCommand(new MoveBaseTo(800, -800));
  addSequentialCommand(new MoveBaseTo(-300, 300));
  addSequentialCommand(new MoveBaseTo(1200, 1800));
  addParallelCommand(new MoveFlipperFor(1000, 127, false));
  /*addSequentialCommand(new MoveBaseTo(-800, 800));
  addSequentialCommand(new MoveBaseTo(1000, 1000));
  addParallelCommand(new MoveFlipperFor(1000, -127, false));*/
  //addSequentialCommand(new DriveToPosition(1250, -1250)); // Forwards one tile
  //addSequentialCommand(new DriveToPosition(-208, -208)); // Rotate 45 degrees
  //addSequentialCommand(new DriveToPosition(-30, -30)); // Rotate x degrees

  //addSequentialCommand(new DriveToPosition(-2500, 2500));
  //addSequentialCommand(new DriveToPosition(2500, -2500));

  //addSequentialCommand(new DriveToPosition(-416, -416));
  //addSequentialCommand(new DriveToPosition(-2500, 2500, 200));

  //addSequentialCommand(new DriveToPosition(1000, 1000));
  //addParallelCommand(new FlywheelRevUp());
  //addSequentialCommand(new CollectorMiddleForwardTimed(1000));
}
