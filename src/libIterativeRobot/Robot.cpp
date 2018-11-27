#include "libIterativeRobot/Robot.h"
#include "libIterativeRobot/events/EventScheduler.h"
#include "libIterativeRobot/events/JoystickButton.h"
#include "libIterativeRobot/events/JoystickChannel.h"

#include "libIterativeRobot/commands/OICommands/CatapultControl.h"
#include "libIterativeRobot/commands/OICommands/DriveWithJoy.h"
#include "libIterativeRobot/commands/OICommands/FlipperMove.h"
#include "libIterativeRobot/commands/OICommands/SpeedChange.h"

#include "libIterativeRobot/commands/EncoderCommands/MoveCollectorTo.h"

#include "libIterativeRobot/commands/AutonCommandGroups/RedAutonWaitTimes.h"
#include "libIterativeRobot/commands/AutonCommandGroups/BlueAutonWaitTimes.h"
#include "libIterativeRobot/commands/AutonCommandGroups/RedAutonEncoder.h"
#include "libIterativeRobot/commands/AutonCommandGroups/BlueAutonEncoder.h"

AutonChooser* Robot::autonChooser = 0;
Base*  Robot::base = 0;
Catapult* Robot::catapult = 0;
Flipper*  Robot::flipper = 0;

pros::Controller* Robot::mainController = 0;
pros::Controller* Robot::partnerController = 0;

Robot::Robot() {
  printf("Overridden robot constructor!\n");
  autonGroup = NULL;
  // Initialize any subsystems
  autonChooser = AutonChooser::getInstance();
  base = new Base();
  catapult = new Catapult();
  flipper = new Flipper();

  mainController = new pros::Controller(pros::E_CONTROLLER_MASTER);
  partnerController = new pros::Controller(pros::E_CONTROLLER_PARTNER);

  // Define buttons and channels
  libIterativeRobot::JoystickChannel* RightX = new libIterativeRobot::JoystickChannel(mainController, pros::E_CONTROLLER_ANALOG_RIGHT_X);
  libIterativeRobot::JoystickChannel* LeftY = new libIterativeRobot::JoystickChannel(mainController, pros::E_CONTROLLER_ANALOG_LEFT_Y);
  libIterativeRobot::JoystickChannel* LeftYPartner = new libIterativeRobot::JoystickChannel(partnerController, pros::E_CONTROLLER_ANALOG_LEFT_Y);
  //libIterativeRobot::JoystickChannel* PartnerLeftY = new libIterativeRobot::JoystickChannel(partnerController, pros::E_CONTROLLER_ANALOG_LEFT_Y);
  //libIterativeRobot::JoystickButton* flipClaw = new libIterativeRobot::JoystickButton(partnerController, pros::E_CONTROLLER_DIGITAL_L1);
  libIterativeRobot::JoystickChannel* flipperMove = new libIterativeRobot::JoystickChannel(partnerController, pros::E_CONTROLLER_ANALOG_RIGHT_Y);
  libIterativeRobot::JoystickButton* catapultMoveCommand = new libIterativeRobot::JoystickButton(partnerController, pros::E_CONTROLLER_DIGITAL_R1);
  libIterativeRobot::JoystickButton* slowBase = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_UP);
  libIterativeRobot::JoystickButton* normalBase = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_DOWN);
  //libIterativeRobot::JoystickButton* moveForward = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_RIGHT);

  // Add commands to be run to buttons
  DriveWithJoy* driveCommand = new DriveWithJoy();
  RightX->whilePastThreshold(driveCommand);
  LeftY->whilePastThreshold(driveCommand);

  LeftYPartner->whilePastThreshold(new CatapultControl());

  flipperMove->whilePastThreshold(new FlipperMove());

  catapultMoveCommand->whenPressed(new MoveCollectorTo(3000, 1500, false));

  slowBase->whenPressed(new SpeedChange(0.5));
  normalBase->whenPressed(new SpeedChange(1));
}

void Robot::robotInit() {
  printf("Robot created.\n");
}

void Robot::autonInit() {
  printf("Default autonInit() function\n");

  libIterativeRobot::EventScheduler::getInstance()->initialize();
  Motor::resetEncoders();

  autonChooser->uninit();

  switch (autonChooser->getAutonChoice()) {
    case 0:
      autonGroup = new RedAutonEncoder();
      break;
    case 1:
      autonGroup = new BlueAutonEncoder();
      break;
    case 2:
      autonGroup = new RedAutonWaitTimes();
      break;
    case 3:
      autonGroup = new BlueAutonWaitTimes();
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
  Motor::resetEncoders();
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
  Motor::resetEncoders();
  autonChooser->uninit();
}

void Robot::disabledPeriodic() {
  //printf("Default disabledPeriodic() function\n");
}
