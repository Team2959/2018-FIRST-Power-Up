/*
 * CubeDeliverySubsystem.cpp
 *
 *  Created on: Feb 3, 2018
 *      Author: Andrew
 */

#include "Subsystems/CubeDelivery.h"
#include "RobotMap.h"

CubeDelivery::CubeDelivery() : frc::Subsystem("CubeDeliverySubsystem")
{
	m_cubeLiftMotor.reset(new WPI_TalonSRX(CUBE_VERTICAL_MOTOR_CAN));
	m_cubeManipulationMotor.reset(new frc::Spark(CUBE_ARMS_OPEN_CLOSE_MOTOR));
}

void CubeDelivery::OpenArms()
{
	m_openCloseArms.Set(frc::DoubleSolenoid::Value::kForward);
}

void CubeDelivery::CloseArms()
{
	m_openCloseArms.Set(frc::DoubleSolenoid::Value::kReverse);
}

void CubeDelivery::StopWheels()
{
	m_cubeManipulationMotor->Set(0);
}

void CubeDelivery::SpinWheelsIn()
{
	m_cubeManipulationMotor->Set(1);
}

void CubeDelivery::SpinWheelsOutFast()
{
	m_cubeManipulationMotor->Set(-1);
}

void CubeDelivery::SpinWheelsOutSlow()
{
	m_cubeManipulationMotor->Set(-0.25);
}

bool CubeDelivery::ArmsAreOpen()
{
	return m_openCloseArms.Get() == frc::DoubleSolenoid::Value::kForward;
}
