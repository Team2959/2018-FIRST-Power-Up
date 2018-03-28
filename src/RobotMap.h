/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#ifndef SRC_ROBOT_MAP_H_
#define SRC_ROBOT_MAP_H_

constexpr double Pi = 3.1415926535;
constexpr double HalfPi = Pi / 2.0;
constexpr double QuarterPi = Pi / 4.0;

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// CAN Mapping - Talons
constexpr int FRONT_LEFT_DRIVE_MOTOR_CAN = 1;
constexpr int FRONT_RIGHT_DRIVE_MOTOR_CAN = 2;
constexpr int BACK_RIGHT_DRIVE_MOTOR_CAN = 3;
constexpr int BACK_LEFT_DRIVE_MOTOR_CAN = 4;
constexpr int CUBE_VERTICAL_MOTOR_CAN = 5;

// PWM Mappings - Sparks
constexpr int CUBE_ARMS_OPEN_CLOSE_MOTOR = 4;
constexpr int CLIMB_LEFT_MOTOR = 7;
constexpr int CLIMB_RIGHT_MOTOR = 6;

// Digital IO Mappings
constexpr int CLIMB_TOP_LIMIT_SWITCH = 9;
constexpr int CLIMB_BOTTOM_LIMIT_SWITCH = 7;
constexpr int CUBE_PRESENT_OPTICAL_SWITCH = 6;
constexpr int AT_BOTTOM_LIMIT_SWITCH = 5; //competition bot
//constexpr int AT_BOTTOM_LIMIT_SWITCH = 8; //practice bot

// Pneumatics Control Module (PCM) Solenoids
constexpr int FOLD_CUBE_ARMS_SOLENOID = 1;
constexpr int OPEN_CLOSE_CUBE_ARMS_SOLENOID = 0;

constexpr double NoTarget = -1;
constexpr double AtTarget = -2;
constexpr int CubeColor = 1;
constexpr int TapeColor = 2;
constexpr static double TargetSize = 0.85; // percentage of frame filled

#endif /* SRC_ROBOT_MAP_H_ */
