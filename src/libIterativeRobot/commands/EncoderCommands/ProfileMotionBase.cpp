#include "libIterativeRobot/commands/EncoderCommands/ProfileMotionBase.h"
#include "libIterativeRobot/commands/EncoderCommands/MoveBaseTo.h"

ProfileMotionBase::ProfileMotionBase(std::vector<int> leftSetpoints, std::vector<int> rightSetpoints) {
  if (leftSetpoints.size() != rightSetpoints.size())
    return;

  for (size_t i = 0; i < leftSetpoints.size(); i++) {
    addSequentialCommand(new MoveBaseTo(leftSetpoints[i], rightSetpoints[i]));
  }
}
