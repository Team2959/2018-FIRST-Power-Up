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

	void Drive(double magnitude, double totalAngle, double rotation);

	void StopMotor() override;
	void GetDescription(llvm::raw_ostream& desc) const override;

	void InitSendable(frc::SendableBuilder& builder) override;
};
