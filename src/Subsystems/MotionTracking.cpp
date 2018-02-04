/*
 * MotionTracking.cpp
 *
 *  Created on: Feb 2, 2018
 *      Author: Bryce's Omen
 */

#include "Subsystems/MotionTracking.h"
#include <SmartDashboard/SmartDashboard.h>
#include "Commands/WheelTrackingCommand.h"

MotionTracking::MotionTracking(std::shared_ptr<XDrive> xDriveSystem): frc::Subsystem("MotionTracking")
{
	m_frontLeftMotor = xDriveSystem->FlmPointer();
	m_frontRightMotor = xDriveSystem->FrmPointer();
	m_backLeftMotor = xDriveSystem->BlmPointer();
	m_backRightMotor = xDriveSystem->BrmPointer();

	m_time.Start();
	m_previous = m_time.Get();
}

MotionTracking::~MotionTracking()
{
	m_time.Stop();
}

void MotionTracking::InitDefaultCommand()
{
	SetDefaultCommand(new WheelTrackingCommand());
}

void MotionTracking::UpdateWheels()
{
	double current = m_time.Get();
	double diff = current - m_previous;
	m_previous = current;
	double flm = m_frontLeftMotor->GetSelectedSensorVelocity(0) *(0.0025566346646476);
	double frm = m_frontRightMotor->GetSelectedSensorVelocity(0) *(0.0025566346646476);
	double brm = m_backRightMotor->GetSelectedSensorVelocity(0) *(0.0025566346646476);
	double blm = m_backLeftMotor->GetSelectedSensorVelocity(0) *(0.0025566346646476);
	m_flmDistance += ((m_flmPrevSpeed + flm) /2.0)*diff;
	m_frmDistance += ((m_frmPrevSpeed + frm) /2.0)*diff;
	m_brmDistance += ((m_brmPrevSpeed + brm) /2.0)*diff;
	m_blmDistance += ((m_blmPrevSpeed + blm) /2.0)*diff;
}

void MotionTracking::SendMotorNumberToDash()
{
	frc::SmartDashboard::PutNumber("flm Distance"  , m_flmDistance);
	frc::SmartDashboard::PutNumber("frm Distance"  , m_frmDistance);
	frc::SmartDashboard::PutNumber("blm Distance"  , m_blmDistance);
	frc::SmartDashboard::PutNumber("brm Distance"  , m_brmDistance);
}
