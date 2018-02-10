/*
 * VerticalArmMovment.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: Devin
 */

#include <Subsystems/VerticalArmMovment.h>
#include "RobotMap.h"


VerticalArmMovment::VerticalArmMovment() : frc::Subsystem("VerticalArmMovmentSubsystem"),
	m_cubeLiftMotor {CUBE_VERTICAL_MOTOR_CAN}
{
}

VerticalArmMovment::~VerticalArmMovment()
{
}

void VerticalArmMovment::MoveArm(CubeVerticalPlace target, double height = 0.0);
{
//	m_cubeLiftMotor.Set();
}
