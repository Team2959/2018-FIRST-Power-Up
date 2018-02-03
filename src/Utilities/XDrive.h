/*
 * XDrive.h
 *
 *  Created on: Jan 25, 2018
 *      Author: TuffyPelly
 */

#pragma once

#include <Drive/RobotDriveBase.h>
#include <memory>
#include <llvm/raw_ostream.h>
#include "ctre/Phoenix.h"
#include <string>
#include <Timer.h>
#include <SmartDashboard/SmartDashboard.h>


class XDrive: public frc::RobotDriveBase
{
private:

	std::shared_ptr<WPI_TalonSRX> m_frontLeftMotor;
	std::shared_ptr<WPI_TalonSRX> m_backLeftMotor;
	std::shared_ptr<WPI_TalonSRX> m_frontRightMotor;
	std::shared_ptr<WPI_TalonSRX> m_backRightMotor;


public:
	XDrive();
	~XDrive() override = default;

	// Drive robot via XDrive
	// Magnitude is 0 .. 1 for how fast to move
	// Total Angle is 0 .. 2 * Pi in radians for direction
	// Rotation is -1 .. 1
	void Drive(double magnitude, double totalAngle, double rotation);

	void StopMotor() override;
	void GetDescription(llvm::raw_ostream& desc) const override;

	void InitSendable(frc::SendableBuilder& builder) override;

	std::shared_ptr<WPI_TalonSRX> FlmPointer();
	std::shared_ptr<WPI_TalonSRX> FrmPointer();
	std::shared_ptr<WPI_TalonSRX> BlmPointer();
	std::shared_ptr<WPI_TalonSRX> BrmPointer();





private:
	void CreateAndConfigureMotorController(std::shared_ptr<WPI_TalonSRX> motor, int canId, std::string name);
};
