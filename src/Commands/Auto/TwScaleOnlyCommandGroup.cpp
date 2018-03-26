/*
 * TwScaleOnlyCommandGroup.cpp
 *
 *  Created on: Mar 26, 2018
 *      Author: CW
 */

#include <Commands/Auto/TwScaleOnlyCommandGroup.h>
#include <Commands/Auto/TwoWheelDriveCommand.h>
#include <Commands/Auto/MoveToVerticalCubePositionCommand.h>
#include <Commands/DeliverCubeCommand.h>
#include <Subsystems/VerticalArmMovement.h>
#include "RobotMap.h"
#include <Commands/StopArmWheelsCommand.h>
#include <Commands/Auto/RotateRelativeAngleCommand.h>
#include <Commands/SpinArmWheelsInCommand.h>
#include <Commands/FoldArmsUpCommand.h>
#include <Commands/FoldArmsDownCommand.h>

TwScaleOnlyCommandGroup::TwScaleOnlyCommandGroup(bool botOnLeft, Side scaleSide) :
frc::CommandGroup("TwScaleOnly")
{

	if(botOnLeft && scaleSide == Side::Left)
	{

	}
	if(botOnLeft && scaleSide == Side::Right)
	{

	}
	if(!botOnLeft && scaleSide == Side::Left)
	{

	}
	if(!botOnLeft && scaleSide == Side::Right)
	{
			AddSequential(new TwoWheelDriveCommand(25, 1, false));
			AddSequential(new RotateRelativeAngleCommand(-QuarterPi*-3, 0.3));
			AddParallel(new MoveToVerticalCubePositionCommand(VerticalArmMovement::CubeVerticalPlace::Scale));
			// spit cube into scale
			AddSequential(new DeliverCubeCommand());
			AddSequential(new TimedCommand(1.5));
			AddParallel(new StopArmWheelsCommand());
	}

}

TwScaleOnlyCommandGroup::~TwScaleOnlyCommandGroup()
{

}

