#include "libIterativeRobot/Robot.h"
#include "libIterativeRobot/events/EventScheduler.h"
#include "libIterativeRobot/events/JoystickButton.h"
#include "libIterativeRobot/events/JoystickChannel.h"

#include "libIterativeRobot/commands/StopBase.h"
#include "libIterativeRobot/commands/DriveWithJoy.h"
#include "libIterativeRobot/commands/FlipperControl.h"
#include "libIterativeRobot/commands/ClawControl.h"
#include "libIterativeRobot/commands/FlipperUp.h"
#include "libIterativeRobot/commands/FlipClaw.h"
#include "libIterativeRobot/commands/SpeedChange.h"
#include "libIterativeRobot/commands/MoveBaseTo.h"

#include "libIterativeRobot/commands/AutonGroup1.h"
#include "libIterativeRobot/commands/AutonGroup2.h"

AutonChooser* Robot::autonChooser = 0;
Base*  Robot::base = 0;
Claw*  Robot::claw = 0;
Flipper*  Robot::flipper = 0;

pros::Controller* Robot::mainController = 0;
pros::Controller* Robot::partnerController = 0;

Robot::Robot() {
  printf("Overridden robot constructor!\n");
  autonGroup = NULL;
  // Initialize any subsystems
  autonChooser = AutonChooser::getInstance();
  base = new Base();
  claw = new Claw();
  flipper = new Flipper();

  mainController = new pros::Controller(pros::E_CONTROLLER_MASTER);
  partnerController = new pros::Controller(pros::E_CONTROLLER_PARTNER);

  // Define buttons and channels
  libIterativeRobot::JoystickChannel* RightX = new libIterativeRobot::JoystickChannel(mainController, pros::E_CONTROLLER_ANALOG_RIGHT_X);
  libIterativeRobot::JoystickChannel* LeftY = new libIterativeRobot::JoystickChannel(mainController, pros::E_CONTROLLER_ANALOG_LEFT_Y);
  //libIterativeRobot::JoystickChannel* PartnerLeftY = new libIterativeRobot::JoystickChannel(partnerController, pros::E_CONTROLLER_ANALOG_LEFT_Y);
  //libIterativeRobot::JoystickButton* flipClaw = new libIterativeRobot::JoystickButton(partnerController, pros::E_CONTROLLER_DIGITAL_L1);
  libIterativeRobot::JoystickButton* flipperForward = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_R1);
  libIterativeRobot::JoystickButton* flipperBackward = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_R2);
  libIterativeRobot::JoystickButton* slowBase = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_UP);
  libIterativeRobot::JoystickButton* normalBase = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_DOWN);
  //libIterativeRobot::JoystickButton* moveForward = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_RIGHT);

  // Add commands to be run to buttons
  DriveWithJoy* driveCommand = new DriveWithJoy();
  RightX->whilePastThreshold(driveCommand);
  LeftY->whilePastThreshold(driveCommand);

  flipperForward->whileHeld(new FlipperControl(127));
  flipperBackward->whileHeld(new FlipperControl(-127));
  //PartnerLeftY->whilePastThreshold(new ClawControl());

  //flipClaw->whenPressed(new FlipClaw());
  slowBase->whenPressed(new SpeedChange(0.5));
  normalBase->whenPressed(new SpeedChange(1));

  //moveForward->whenPressed(new MoveBaseTo((int)ticksPerRev18, (int)ticksPerRev18));
}

void Robot::robotInit() {
  printf("Robot created.\n");
}

void Robot::autonInit() {
  printf("Default autonInit() function\n");
  libIterativeRobot::EventScheduler::getInstance()->initialize();
  autonChooser->uninit();

  switch (autonChooser->getAutonChoice()) {
    case 0:
      autonGroup = new AutonGroup1();
      break;
    case 1:
      autonGroup = new AutonGroup2();
      break;
  }

  autonGroup->run();
}

void Robot::autonPeriodic() {
  //printf("Default autonPeriodic() function\n");
  libIterativeRobot::EventScheduler::getInstance()->update();
  Motor::periodicUpdate();
  PIDController::loopAll();
}

void Robot::teleopInit() {
  printf("Default teleopInit() function\n");
  libIterativeRobot::EventScheduler::getInstance()->initialize();
  autonChooser->init();
}

void Robot::teleopPeriodic() {
  //printf("Default teleopPeriodic() function\n");
  libIterativeRobot::EventScheduler::getInstance()->update();
  Motor::periodicUpdate();
  PIDController::loopAll();
}

void Robot::disabledInit() {
  printf("Default disabledInit() function\n");
  libIterativeRobot::EventScheduler::getInstance()->initialize();
  autonChooser->uninit();
}

void Robot::disabledPeriodic() {
  //printf("Default disabledPeriodic() function\n");
}
