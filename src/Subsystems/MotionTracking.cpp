/*
 * MotionTracking.cpp
 *
 *  Created on: Feb 2, 2018
 *      Author: Bryce's Omen
 */

#include <Subsystems/MotionTracking.h>


MotionTracking::MotionTracking(void): Subsystem("MotionTracking")
{

	// TODO Auto-generated constructor stub

	m_time.Start();
	m_previous = m_time.Get();
}

MotionTracking::~MotionTracking() {
	// TODO Auto-generated destructor stub
	m_time.Stop();
}

void MotionTracking::SetMotorPointers(std::shared_ptr<WPI_TalonSRX> flm, std::shared_ptr<WPI_TalonSRX> frm, std::shared_ptr<WPI_TalonSRX> blm, std::shared_ptr<WPI_TalonSRX> brm)
{
	m_frontLeftMotor = flm;
	m_frontRightMotor = frm;
	m_backLeftMotor = blm;
	m_backRightMotor = brm;
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
