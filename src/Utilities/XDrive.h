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

class XDrive: public frc::RobotDriveBase
{
private:
	std::shared_ptr<WPI_TalonSRX> m_frontLeftMotor;
	std::shared_ptr<WPI_TalonSRX> m_backLeftMotor;
	std::shared_ptr<WPI_TalonSRX> m_frontRightMotor;
	std::shared_ptr<WPI_TalonSRX> m_backRightMotor;
	frc:: Timer time();
	double previous;
	double flmDistance = 0;
	double frmDistance = 0;
	double brmDistance = 0;
	double blmDistance = 0;
	double flmPrevSpeed = 0;
	double frmPrevSpeed = 0;
	double brmPrevSpeed = 0;
	double blmPrevSpeed = 0;
	double Xdis = 0;
	double Ydis = 0;


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

private:
	void CreateAndConfigureMotorController(std::shared_ptr<WPI_TalonSRX> motor, int canId, std::string name);
};
