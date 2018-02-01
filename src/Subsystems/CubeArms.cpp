/*
 * CubeArms.cpp
 *
 *  Created on: Jan 31, 2018
 *      Author: Andrew
 */

#include "CubeArms.h"

CubeArms::CubeArms() : Subsystem("CubeArms")
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
