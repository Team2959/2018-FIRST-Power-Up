/*
 * VerticleMovementCommand.cpp
 *
 *  Created on: Feb 9, 2018
 *      Author: Andrew
 */

#include <Commands/VerticalMovementCommand.h>
#include "Robot.h"

const double LowerScaleHeight = 4.0;
const double UpperScaleHeight = 6.0;
const double UpperSlider = 1.0;
const double LowerSlider = 0.5;
const double ConversionSlope = (UpperScaleHeight - LowerScaleHeight) / (UpperSlider - LowerSlider);

VerticalMovementCommand::VerticalMovementCommand() : frc::Command("VerticalMovement")
{
	Requires(Robot::VerticalArmMovmentSubsystem.get());
}

void VerticalMovementCommand::Execute()
{
	double sliderAxis = Robot::oi->GetButtonBox()->GetRawAxis(3);

	if (sliderAxis < -0.75)
	{
		Robot::VerticalArmMovmentSubsystem->MoveArm(VerticalArmMovement::Exchange);
	}
	else if (sliderAxis < -0.5)
	{
		Robot::VerticalArmMovmentSubsystem->MoveArm(VerticalArmMovement::Level2);
	}
	else if (sliderAxis < -0.25)
	{
		Robot::VerticalArmMovmentSubsystem->MoveArm(VerticalArmMovement::Level3);
	}
	else if (sliderAxis < 0)
	{
		Robot::VerticalArmMovmentSubsystem->MoveArm(VerticalArmMovement::Portal);
	}
	else if (sliderAxis < 0.25)
	{
		Robot::VerticalArmMovmentSubsystem->MoveArm(VerticalArmMovement::Switch);
	}
	else if (sliderAxis > 0.5)
	{
		double position = LowerScaleHeight + ConversionSlope * (sliderAxis - LowerSlider);
		Robot::VerticalArmMovmentSubsystem->MoveArm(VerticalArmMovement::Scale, position);
	}
}

bool VerticalMovementCommand::IsFinished()
{
	return false;
}



