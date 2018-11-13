#ifndef _COMMANDS_PROFILEMOTIONBASE_H_
#define _COMMANDS_PROFILEMOTIONBASE_H_

#include "libIterativeRobot/commands/CommandGroup.h"
#include <vector>

class ProfileMotionBase : public libIterativeRobot::CommandGroup {
  private:
    std::vector<int> leftSetpoints;
    std::vector<int> rightSetpoints;
  public:
    ProfileMotionBase(std::vector<int> leftSetpoints, std::vector<int> rightSetpoints);
};

#endif // _COMMANDS_PROFILEMOTION_H_
