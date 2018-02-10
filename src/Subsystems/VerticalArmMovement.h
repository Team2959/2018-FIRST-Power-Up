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

enum CubeVerticalPlace
{
	Exchange = 0,
	Level2 = 1,
	Level3 = 2,
	Portal = 3,
	Switch = 4,
	Scale = 5
};

class VerticalArmMovement: public frc::Subsystem
{
private:
	WPI_TalonSRX m_cubeLiftMotor;

public:
	VerticalArmMovement();
	~VerticalArmMovement() override = default;

	void InitDefaultCommand() override;

	void MoveArm(CubeVerticalPlace target, double scaleHeight = 0.0);
	bool IsAtPosition(CubeVerticalPlace target, double scaleHeight = 0.0);
};

#endif /* SRC_SUBSYSTEMS_VERTICALARMMOVEMENT_H_ */
