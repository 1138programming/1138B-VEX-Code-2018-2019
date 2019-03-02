#ifndef _COMMANDS_FRONTTILEAUTON_H_
#define _COMMANDS_FRONTTILEAUTON_H_

#include "libIterativeRobot/commands/CommandGroup.h"

class FrontTileAuton : public libIterativeRobot::CommandGroup {
  private:
  public:
    FrontTileAuton(bool isRed = false);
};

#endif // _COMMANDS_FRONTTILEAUTON_H_
