/**
 * @file Constants.h
 * @brief Provides constants used throughout the entire code. Contains user-readable motor names
 */

 #include "abstractBaseClasses/Motor.h"

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#define DEFAULT_TASK_TIME 10000
#define DELAY_TIME 10
#define MAX_MOTORS 29
#define MAX_FOLLOWERS 3

// Motor ports
const int leftFrontBasePort = 6;
const int leftMiddleBasePort = 7;
const int leftBackBasePort = 8;

const int rightFrontBasePort = 3;
const int rightMiddleBasePort = 2;
const int rightBackBasePort = 1;

const int firstArmPort = 10;
const int secondArmPort = 9;

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

// Global things that we need

#endif
