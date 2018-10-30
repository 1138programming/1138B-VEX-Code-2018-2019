#include "libIterativeRobot/Robot.h"
#include "libIterativeRobot/events/EventScheduler.h"
#include "libIterativeRobot/events/JoystickButton.h"
#include "libIterativeRobot/events/JoystickChannel.h"

#include "libIterativeRobot/commands/StopBase.h"
#include "libIterativeRobot/commands/DriveWithJoy.h"
#include "libIterativeRobot/commands/ArmControl.h"

#include "libIterativeRobot/commands/AutonGroup1.h"

Base*  Robot::base = 0;
Arm*  Robot::arm = 0;

pros::Controller* Robot::mainController = 0;
pros::Controller* Robot::partnerController = 0;

Robot::Robot() {
  printf("Overridden robot constructor!\n");
  autonGroup = NULL;
  // Initialize any subsystems
  base = new Base();
  arm = new Arm();

  mainController = new pros::Controller(pros::E_CONTROLLER_MASTER);
  partnerController = new pros::Controller(pros::E_CONTROLLER_PARTNER);

  // Define buttons and channels
  libIterativeRobot::JoystickChannel* RightX = new libIterativeRobot::JoystickChannel(mainController, pros::E_CONTROLLER_ANALOG_RIGHT_X);
  libIterativeRobot::JoystickChannel* LeftY = new libIterativeRobot::JoystickChannel(mainController, pros::E_CONTROLLER_ANALOG_LEFT_Y);
  libIterativeRobot::JoystickChannel* PartnerRightY = new libIterativeRobot::JoystickChannel(partnerController, pros::E_CONTROLLER_ANALOG_RIGHT_Y);

  // Add commands to be run to buttons
  DriveWithJoy* driveCommand = new DriveWithJoy();
  RightX->whilePastThreshold(driveCommand);
  LeftY->whilePastThreshold(driveCommand);

  PartnerRightY->whilePastThreshold(new ArmControl());
}

void Robot::robotInit() {
  printf("Robot created.\n");
}

void Robot::autonInit() {
  printf("Default autonInit() function\n");
  libIterativeRobot::EventScheduler::getInstance()->initialize();
  autonGroup = new AutonGroup1();
  autonGroup->run();
}

void Robot::autonPeriodic() {
  //printf("Default autonPeriodic() function\n");
  libIterativeRobot::EventScheduler::getInstance()->update();
  Motor::periodicUpdate();
  //PIDController::loopAll();
}

void Robot::teleopInit() {
  printf("Default teleopInit() function\n");
  libIterativeRobot::EventScheduler::getInstance()->initialize();
}

void Robot::teleopPeriodic() {
  //printf("Default teleopPeriodic() function\n");
  libIterativeRobot::EventScheduler::getInstance()->update();
  Motor::periodicUpdate();
  //PIDController::loopAll();
}

void Robot::disabledInit() {
  printf("Default disabledInit() function\n");
  libIterativeRobot::EventScheduler::getInstance()->initialize();
}

void Robot::disabledPeriodic() {
  //printf("Default disabledPeriodic() function\n");
}
