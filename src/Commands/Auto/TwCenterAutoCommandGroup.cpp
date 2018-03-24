/*
 * TwCenterAutoCommandGroup.cpp
 *
 *  Created on: Mar 24, 2018
 *      Author: Kevin
 */

#include <Commands/Auto/TwCenterAutoCommandGroup.h>
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

TwCenterAutoCommandGroup::TwCenterAutoCommandGroup(Side switchSide, Side scaleSide) :
	frc::CommandGroup("TwCenterAuto")
{
	if(switchSide == Side::Left)
	{
		// Drive to switch.
		AddSequential(new RotateRelativeAngleCommand(-QuarterPi,0.5));
		AddSequential(new TwoWheelDriveCommand(11, 1, false));
		AddSequential(new RotateRelativeAngleCommand(QuarterPi,0.5));
		AddSequential(new TwoWheelDriveCommand(1, 1, false));
		// Deliver cube into switch.
		AddSequential(new DeliverCubeCommand());
		AddSequential(new TimedCommand(1.5));
		AddParallel(new StopArmWheelsCommand());
		//Back away from switch.
		//AddSequential(new TwoWheelDriveCommand(1, -1, false));
		//AddSequential(new RotateRelativeAngleCommand(-QuarterPi,0.5));

		if(scaleSide == Side::Left)
		{

		}

		else
		{

		}
	}
	else if(switchSide == Side::Right)
	{
		AddSequential(new RotateRelativeAngleCommand(QuarterPi,0.5));
		AddSequential(new TwoWheelDriveCommand(10, 1, false));
		AddSequential(new RotateRelativeAngleCommand(-QuarterPi,0.5));
		AddSequential(new TwoWheelDriveCommand(4, 1, false));
		AddSequential(new RotateRelativeAngleCommand(-QuarterPi,0.5));
		AddSequential(new TwoWheelDriveCommand(1, 1, false));
		// Deliver cube into switch.
		AddSequential(new DeliverCubeCommand());
		AddSequential(new TimedCommand(1.5));
		AddParallel(new StopArmWheelsCommand());
		//Back away from switch.
		AddSequential(new TwoWheelDriveCommand(1, -1, false));
		AddSequential(new RotateRelativeAngleCommand(QuarterPi,0.5));

		if(scaleSide == Side::Left)
				{

				}

				else
				{

				}

	}
}
