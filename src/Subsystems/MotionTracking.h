/*
 * MotionTracking.h
 *
 *  Created on: Feb 2, 2018
 *      Author: Bryce's Omen
 */

#ifndef SRC_SUBSYSTEMS_MOTIONTRACKING_H_
#define SRC_SUBSYSTEMS_MOTIONTRACKING_H_

#include <Commands/Subsystem.h>
#include <Utilities/XDrive.h>
#include <Timer.h>


class MotionTracking: public frc::Subsystem
{
public:
	MotionTracking();
	virtual ~MotionTracking();
	void SetMotorPointers(std::shared_ptr<WPI_TalonSRX> flm, std::shared_ptr<WPI_TalonSRX> frm, std::shared_ptr<WPI_TalonSRX> blm, std::shared_ptr<WPI_TalonSRX> brm);
    void UpdateWheels();
    void SendMotorNumberToDash();
    void InitDefaultCommand() override;

private:
	frc::Timer m_time;
	double m_previous;
	double m_flmDistance = 0;
	double m_frmDistance = 0;
	double m_brmDistance = 0;
	double m_blmDistance = 0;
	double m_flmPrevSpeed = 0;
	double m_frmPrevSpeed = 0;
	double m_brmPrevSpeed = 0;
	double m_blmPrevSpeed = 0;
	double m_Xdis = 0;
	double m_Ydis = 0;

	std::shared_ptr<WPI_TalonSRX> m_frontLeftMotor;
	std::shared_ptr<WPI_TalonSRX> m_backLeftMotor;
	std::shared_ptr<WPI_TalonSRX> m_frontRightMotor;
	std::shared_ptr<WPI_TalonSRX> m_backRightMotor;
};

#endif /* SRC_SUBSYSTEMS_MOTIONTRACKING_H_ */
