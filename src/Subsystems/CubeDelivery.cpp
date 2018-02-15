/*
 * CubeDeliverySubsystem.cpp
 *
 *  Created on: Feb 3, 2018
 *      Author: Andrew
 */

#include "Subsystems/CubeDelivery.h"
#include "RobotMap.h"
#include <SmartDashboard/SmartDashboard.h>

CubeDelivery::CubeDelivery() : frc::Subsystem("CubeDeliverySubsystem"),
	m_openCloseArms {OPEN_CLOSE_CUBE_ARMS_SOLENOID},
	m_cubeManipulationMotor {CUBE_ARMS_OPEN_CLOSE_MOTOR},
	m_cubePresentSwitch {CUBE_PRESENT_OPTICAL_SWITCH}
{
	UpdateSmartDashboard();
}

void CubeDelivery::OpenArms()
{
	m_openCloseArms.Set(true);
}

void CubeDelivery::CloseArms()
{
	m_openCloseArms.Set(false);
}

void CubeDelivery::StopWheels()
{
	m_cubeManipulationMotor.Set(0);
}

void CubeDelivery::SpinWheelsIn()
{
	m_cubeManipulationMotor.Set(1);
}

void CubeDelivery::SpinWheelsOut(double speed)
{
	if (speed < -1)
	{
		speed = -1;
	}
	else if (speed > 0)
	{
		speed = 0;
	}

	m_cubeManipulationMotor.Set(speed);
}

bool CubeDelivery::ArmsAreOpen()
{
	return m_openCloseArms.Get();
}

bool CubeDelivery::CubePresent()
{
	return m_cubePresentSwitch.Get();
}

void CubeDelivery::UpdateSmartDashboard()
{
	frc::SmartDashboard::PutBoolean("   Arms Open", ArmsAreOpen());
	frc::SmartDashboard::PutBoolean("  Cube Possession", CubePresent());
}
