#include "libIterativeRobot/commands/AutonGroup1.h"
#include "libIterativeRobot/commands/DriveToPosition.h"

AutonGroup1::AutonGroup1() {
  //addSequentialCommand(new DriveToPosition(1250, -1250)); // Forwards one tile
  //addSequentialCommand(new DriveToPosition(-208, -208)); // Rotate 45 degrees
  //addSequentialCommand(new DriveToPosition(-30, -30)); // Rotate x degrees

  addSequentialCommand(new DriveToPosition(-2500, 2500));
  addSequentialCommand(new DriveToPosition(2500, -2500));

  addSequentialCommand(new DriveToPosition(-416, -416));
  addSequentialCommand(new DriveToPosition(-2500, 2500, 200));

  //addSequentialCommand(new DriveToPosition(1000, 1000));
  //addParallelCommand(new FlywheelRevUp());
  //addSequentialCommand(new CollectorMiddleForwardTimed(1000));
}
