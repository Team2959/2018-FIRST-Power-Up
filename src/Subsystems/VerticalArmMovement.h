/*
 * VerticalArmMovment.h
 *
 *  Created on: Feb 10, 2018
 *      Author: CW
 */

#ifndef SRC_SUBSYSTEMS_VERTICALARMMOVEMENT_H_
#define SRC_SUBSYSTEMS_VERTICALARMMOVEMENT_H_

#include <Commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include "RobotMap.h"

class VerticalArmMovement: public frc::Subsystem
{
private:
	WPI_TalonSRX m_cubeLiftMotor;

	 // approximately 24" of travel with diameter of 1.08 for an encoder with 4096 ticks
	const double GearDiameter = Pi * 1.08;
	const double DistanceToTicksFactor = 4096 / GearDiameter;

	const double ScaleHeightMinimum = 4.0;	// in feet
	const double ScaleHeightMaximum = 6.0;
	const double ScalePositionMaximum = 100000;
	const double ScalePositionMinimum = ScalePositionMaximum - 24 * DistanceToTicksFactor;
	const double ScaleConversionSlope = (ScalePositionMaximum-ScalePositionMinimum)/(ScaleHeightMaximum-ScaleHeightMinimum);

	const int Level1Position = 5.5 * DistanceToTicksFactor;
	const int ExchangePosition = 8.5 * DistanceToTicksFactor;
	const int Level2Position = 16.5 * DistanceToTicksFactor;
	const int SwitchPosition = 24.5 * DistanceToTicksFactor;
	const int PortalPosition = 25.5 * DistanceToTicksFactor;
	const int Level3Position = 27.5 * DistanceToTicksFactor;

public:
	enum CubeVerticalPlace
	{
		Level1 = 0,
		Exchange = 1,
		Level2 = 2,
		Level3 = 3,
		Portal = 4,
		Switch = 5,
		Scale = 6
	};

public:
	VerticalArmMovement();
	~VerticalArmMovement() override = default;

	void InitDefaultCommand() override;

	void MoveArm(CubeVerticalPlace target, double scaleHeight = 0.0);
	void MoveArmToHeight(double height);
	bool IsAtPosition(CubeVerticalPlace target, double scaleHeight = 0.0);
	bool IsAtSwitchOrHigher();
};

#endif /* SRC_SUBSYSTEMS_VERTICALARMMOVEMENT_H_ */
