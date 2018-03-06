/*
 * VerticleMovementCommand.cpp
 *
 *  Created on: Feb 9, 2018
 *      Author: Andrew
 */

#include <Commands/VerticalArmMovementFromCoPilot.h>
#include "Robot.h"

//const double LowerScaleHeight = 4.0;
//const double UpperScaleHeight = 6.0;
//const double UpperSlider = 1.0;
//const double LowerSlider = 0.5;
//const double ConversionSlope = (UpperScaleHeight - LowerScaleHeight) / (UpperSlider - LowerSlider);

VerticalArmMovementFromCoPilot::VerticalArmMovementFromCoPilot() : frc::Command("VerticalMovement")
{
	Requires(Robot::VerticalArmMovmentSubsystem.get());
}

void VerticalArmMovementFromCoPilot::Execute()
{
	double axis = Robot::oi->GetButtonBox()->GetRawAxis(0);
	// convert from -1 .. 1 to 0 .. 1 range
	axis = (axis + 1.0) / 2.0;
	Robot::VerticalArmMovmentSubsystem->MoveArmToHeight(axis);

//	double sliderAxis = Robot::oi->GetButtonBox()->GetRawAxis(3);
//	if (sliderAxis < -0.75)
//	{
//		Robot::VerticalArmMovmentSubsystem->MoveArm(VerticalArmMovement::Exchange);
//	}
//	else if (sliderAxis < -0.5)
//	{
//		Robot::VerticalArmMovmentSubsystem->MoveArm(VerticalArmMovement::Level2);
//	}
//	else if (sliderAxis < -0.25)
//	{
//		Robot::VerticalArmMovmentSubsystem->MoveArm(VerticalArmMovement::Level3);
//	}
//	else if (sliderAxis < 0)
//	{
//		Robot::VerticalArmMovmentSubsystem->MoveArm(VerticalArmMovement::Portal);
//	}
//	else if (sliderAxis < 0.25)
//	{
//		Robot::VerticalArmMovmentSubsystem->MoveArm(VerticalArmMovement::Switch);
//	}
//	else if (sliderAxis > 0.5)
//	{
//		double position = LowerScaleHeight + ConversionSlope * (sliderAxis - LowerSlider);
//		Robot::VerticalArmMovmentSubsystem->MoveArm(VerticalArmMovement::Scale, position);
//	}
}

bool VerticalArmMovementFromCoPilot::IsFinished()
{
	return false;
}
