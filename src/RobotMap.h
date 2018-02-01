/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

constexpr double Pi = 3.1415926535;
constexpr double HalfPi = Pi / 2.0;
constexpr double QuarterPi = Pi / 4.0;

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// Can Mapping
constexpr int Front_LEFT_DRIVE_MOTOR_CAN = 1;
constexpr int Front_Right_DRIVE_MOTOR_CAN = 2;
constexpr int Back_Right_DRIVE_MOTOR_CAN = 3;
constexpr int Back_Left_DRIVE_MOTOR_CAN = 4;

//PWM Mappings
constexpr int CLIMB_LEFT_MOTOR = 1;
constexpr int CLIMB_RIGHT_MOTOR = 2;

// DIO Mappings
constexpr int CLIMB_TOP_LIMIT_SWITCH = 4;
