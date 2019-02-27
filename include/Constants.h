/**
 * @file Constants.h
 * @brief Provides constants used throughout the entire code. Contains user-readable motor names
 */

 #include "abstractBaseClasses/Motor.h"

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#define DEFAULT_TASK_TIME 10000
#define DELAY_TIME 10
#define MAX_MOTORS 20
#define MAX_FOLLOWERS 3

// Motor ports
const int leftFrontBasePort = 20;
const int leftMiddleBasePort1 = 19;
const int leftMiddleBasePort2 = 9;
const int leftBackBasePort = 10;

const int rightFrontBasePort = 11;
const int rightMiddleBasePort1 = 12;
const int rightMiddleBasePort2 = 2;
const int rightBackBasePort = 1;

//Motor and encoder constants
const int KMaxMotorSpeed = 127;
const int KMaxJoystickValue = 127;
const int encoderTicks = 360; // Encoder ticks in one revolution
const float rotationsPerInch = 31.400156410256; // TODO check if this is correct

// IME addresses
const unsigned char exampleIMEAddress = 0;

// Encoder ports
const int exampleEncoderTopPort = 0;
const int exampleEncoderBottomPort = 1;

// Encoder Constants
const int ticksPerRev36 = 1800; // Ticks per revolution on an 36:1 gear motor
const int ticksPerRev18 = 900; // Ticks per revolution on an 18:1 gear motor
const int ticksPerRev6 = 300; // Ticks per revolution on an 6:1 gear motor

// Global things that we need

#endif
