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
	m_time.Start();

	InitMotorTelemetry("frontLeft", xDriveSystem->Flm());
	InitMotorTelemetry("frontRight", xDriveSystem->Frm());
	InitMotorTelemetry("backRight", xDriveSystem->Brm());
	InitMotorTelemetry("backLeft", xDriveSystem->Blm());

	m_navmxp = new AHRS(SPI::Port::kMXP);
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
	UpdateMotorTelemetry("frontLeft");
	UpdateMotorTelemetry("frontRight");
	UpdateMotorTelemetry("backRight");
	UpdateMotorTelemetry("backLeft");
}

void MotionTracking::SendMotorNumberToDash()
{
	frc::SmartDashboard::PutNumber("flm Distance", m_motors["frontLeft"].displacement);
	frc::SmartDashboard::PutNumber("frm Distance", m_motors["frontRight"].displacement);
	frc::SmartDashboard::PutNumber("blm Distance", m_motors["backLeft"].displacement);
	frc::SmartDashboard::PutNumber("brm Distance", m_motors["backRight"].displacement);
}

void MotionTracking::InitMotorTelemetry(std::string name, WPI_TalonSRX& controller)
{
	m_motors[name] = {0.0, 0.0, 0.0, 0.0, m_time.Get(), &controller};
}

void MotionTracking::UpdateMotorTelemetry(std::string name)
{
	if (m_motors.find(name) != m_motors.end()) {
		double currentTime = m_time.Get();
		double currentVelocity = m_motors[name].controller->GetSelectedSensorVelocity(0) * ENCODER_TO_FPS;
		m_motors[name].displacement += (m_motors[name].instVelocity + currentVelocity) * 0.5 * (currentTime - m_motors[name].time);
		m_motors[name].instVelocity = currentVelocity;
		m_motors[name].instPercent = m_motors[name].controller->GetMotorOutputPercent();
		m_motors[name].instCurrent = m_motors[name].controller->GetOutputCurrent();
		m_motors[name].time = currentTime;
	}
}

void MotionTracking::PrintMotorTelemetries()
{
	std::cout << "Displacement (ft)    [" << m_motors["frontLeft"].displacement << ", " << m_motors["frontRight"].displacement << ", " << m_motors["backRight"].displacement << ", " << m_motors["backLeft"].displacement << "]\n";
	std::cout << "Current      (A)     [" << m_motors["frontLeft"].instCurrent << ", " << m_motors["frontRight"].instCurrent << ", " << m_motors["backRight"].instCurrent << ", " << m_motors["backLeft"].instCurrent << "]\n";
	std::cout << "Velocity     (ft/s)  [" << m_motors["frontLeft"].instVelocity << ", " << m_motors["frontRight"].instVelocity << ", " << m_motors["backRight"].instVelocity << ", " << m_motors["backLeft"].instVelocity << "]\n";
}

void MotionTracking::ResetMotorTelemetry(std::string name)
{
	if (m_motors.find(name) != m_motors.end()) {
		double currentTime = m_time.Get();
		m_motors[name].displacement = 0;
		m_motors[name].instVelocity = 0;
		m_motors[name].instPercent = 0;
		m_motors[name].instCurrent = 0;
		m_motors[name].time = currentTime;
	}
}

void MotionTracking::ResetTelemetries()
{
	ResetMotorTelemetry("frontLeft");
	ResetMotorTelemetry("frontRight");
	ResetMotorTelemetry("backRight");
	ResetMotorTelemetry("backLeft");
}

double MotionTracking::GetAngle()
{
	return fmod(m_navmxp->GetAngle()*(Pi / 18.0) + QuarterPi, 2 * Pi);
}

