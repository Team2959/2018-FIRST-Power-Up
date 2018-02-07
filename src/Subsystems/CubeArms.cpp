/*
 * CubeArms.cpp
 *
 *  Created on: Jan 31, 2018
 *      Author: Andrew
 */

#include "Subsystems/CubeArms.h"
#include "RobotMap.h"

CubeArms::CubeArms() : frc::Subsystem("CubeArms"),
	m_foldArms {FOLD_CUBE_ARMS_FORWARD_SOLENOID, FOLD_CUBE_ARMS_REVERSE_SOLENOID}
{
}

void CubeArms::FoldUp()
{
	m_foldArms.Set(frc::DoubleSolenoid::Value::kForward);
}

void CubeArms::FoldDown()
{
	m_foldArms.Set(frc::DoubleSolenoid::Value::kReverse);
}
