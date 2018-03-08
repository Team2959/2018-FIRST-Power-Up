/*
 * CubeArms.cpp
 *
 *  Created on: Jan 31, 2018
 *      Author: Andrew
 */

#include "Subsystems/CubeArms.h"
#include "RobotMap.h"

CubeArms::CubeArms() : frc::Subsystem("CubeArms"),
	m_foldArms {FOLD_CUBE_ARMS_SOLENOID}
{
}

void CubeArms::FoldUp()
{
	m_foldArms.Set(false);
}

void CubeArms::FoldDown()
{
	m_foldArms.Set(true);
}
