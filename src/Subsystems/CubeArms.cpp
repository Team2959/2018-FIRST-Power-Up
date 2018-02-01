/*
 * CubeArms.cpp
 *
 *  Created on: Jan 31, 2018
 *      Author: Andrew
 */

#include "CubeArms.h"
//#include <WPILib.h>

CubeArms::CubeArms() : Subsystem("CubeArms")
{
	// TODO Auto-generated constructor stub

}

CubeArms::~CubeArms() {
	// TODO Auto-generated destructor stub
}

void CubeArms::FoldUp()
{
	m_foldArms.Set(frc::DoubleSolenoid::Value::kForward);
}
void CubeArms::FoldDown()
{
	m_foldArms.Set(frc::DoubleSolenoid::Value::kReverse);
}


