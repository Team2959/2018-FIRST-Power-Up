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
	bool driveWheels = true;
	double rotateSpeed = 0.15;
	if(switchSide == Side::Right)
	{
		// Drive to switch.
		AddSequential(new RotateRelativeAngleCommand(QuarterPi, rotateSpeed));
		AddSequential(new TwoWheelDriveCommand(12.5, 1, driveWheels));
		AddSequential(new RotateRelativeAngleCommand(-QuarterPi, rotateSpeed));
		AddSequential(new TwoWheelDriveCommand(4, 1, driveWheels));
		// Deliver cube into switch.
		AddSequential(new DeliverCubeCommand());
		AddSequential(new TimedCommand(1.5));
		AddParallel(new StopArmWheelsCommand());
		//Back away from switch.
		//AddSequential(new TwoWheelDriveCommand(1, -1, driveWheels));
		//AddSequential(new RotateRelativeAngleCommand(QuarterPi, rotateSpeed));

		if(scaleSide == Side::Left)
		{
		}
		else
		{
		}
	}
	else //if(switchSide == Side::Left)
	{
		AddSequential(new RotateRelativeAngleCommand(-QuarterPi, rotateSpeed));
		AddSequential(new TwoWheelDriveCommand(10.5, 1, driveWheels));
		AddSequential(new RotateRelativeAngleCommand(HalfPi, rotateSpeed));
		AddSequential(new TwoWheelDriveCommand(3.5, 1, driveWheels));
		AddSequential(new RotateRelativeAngleCommand(QuarterPi, rotateSpeed));
		AddSequential(new TwoWheelDriveCommand(1.5, 1, driveWheels));
		// Deliver cube into switch.
		AddSequential(new DeliverCubeCommand());
		AddSequential(new TimedCommand(1.5));
		AddParallel(new StopArmWheelsCommand());
		//Back away from switch.
		//AddSequential(new TwoWheelDriveCommand(1, -1, driveWheels));
		//AddSequential(new RotateRelativeAngleCommand(QuarterPi, rotateSpeed));
	}
}
