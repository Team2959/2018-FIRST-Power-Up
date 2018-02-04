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

// Can Mapping - Talons
constexpr int Front_LEFT_DRIVE_MOTOR_CAN = 1;
constexpr int Front_Right_DRIVE_MOTOR_CAN = 2;
constexpr int Back_Right_DRIVE_MOTOR_CAN = 3;
constexpr int Back_Left_DRIVE_MOTOR_CAN = 4;
constexpr int CUBE_VERTICAL_MOTOR_CAN = 5;

// PWM Mappings - Sparks
constexpr int CUBE_ARMS_OPEN_CLOSE_MOTOR = 0;
constexpr int CLIMB_LEFT_MOTOR = 1;
constexpr int CLIMB_RIGHT_MOTOR = 2;

// Digital IO Mappings
constexpr int CLIMB_TOP_LIMIT_SWITCH = 4;

// Pneumatic Solenoids
constexpr int FOLD_CUBE_ARMS_FORWARD_SOLENOID = 0;
constexpr int FOLD_CUBE_ARMS_REVERSE_SOLENOID = 1;
constexpr int OPEN_CLOSE_CUBE_ARMS_FORWARD_SOLENOID = 2;
constexpr int OPEN_CLOSE_CUBE_ARMS_REVERSE_SOLENOID = 3;

#endif /* SRC_ROBOT_MAP_H_ */
