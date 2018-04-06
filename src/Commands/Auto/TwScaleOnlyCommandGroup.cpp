/*
 * TwScaleOnlyCommandGroup.cpp
 *
 *  Created on: Mar 26, 2018
 *      Author: CW
 */

#include <Commands/Auto/TwScaleOnlyCommandGroup.h>
#include <Commands/Auto/TwoWheelDriveCommand.h>
#include <Commands/Auto/MoveToVerticalCubePositionCommand.h>
#include <Commands/MoveToAbsoluteHeightCommand.h>
#include <Commands/DeliverCubeCommand.h>
#include <Subsystems/VerticalArmMovement.h>
#include "RobotMap.h"
#include "Robot.h"
#include <Commands/StopArmWheelsCommand.h>
#include <Commands/Auto/RotateRelativeAngleCommand.h>
#include <Commands/SpinArmWheelsInCommand.h>
#include <Commands/FoldArmsUpCommand.h>
#include <Commands/FoldArmsDownCommand.h>
#include <Commands/Auto/DriveStraightCommand.h>
#include <Commands/Auto/DriveToVisionTargetCommand.h>

TwScaleOnlyCommandGroup::TwScaleOnlyCommandGroup(bool botOnLeft, Side scaleSide, Side switchSide) :
	frc::CommandGroup("TwScaleOnly")
{
	bool driveWheels = true;
	double rotateSpeed = 0.15;
	double deliverCubeDelayTime = 1.0;
	if (!botOnLeft && scaleSide == Side::Right)
	{
		// starting right and scale is right side
		// drive to scale and turn towards it
		AddParallel(new MoveToAbsoluteHeightCommand(Robot::VerticalArmMovmentSubsystem->MaxScaleHeight()));
		AddSequential(new TwoWheelDriveCommand(25.0, 1, driveWheels));
		AddSequential(new MoveToVerticalCubePositionCommand(Robot::VerticalArmMovmentSubsystem->MaxScaleHeight()));
//		AddSequential(new RotateRelativeAngleCommand(-QuarterPi, rotateSpeed));
		// spit cube into scale
		AddParallel(new DeliverCubeCommand());
		AddSequential(new TimedCommand(deliverCubeDelayTime));
		AddParallel(new StopArmWheelsCommand());
		// move vertical system to bottom
		AddParallel(new MoveToVerticalCubePositionCommand(0));
		// get another cube
		AddSequential(new TwoWheelDriveCommand(3.0, -1, driveWheels));
		AddParallel(new FoldArmsDownCommand());
		AddSequential(new RotateRelativeAngleCommand(-HalfPi, rotateSpeed));
		AddParallel(new SpinArmWheelsInCommand());
		AddSequential(new DriveToVisionTargetCommand());
		AddParallel(new FoldArmsUpCommand());
	}
	else if (!botOnLeft && scaleSide == Side::Left)
	{
		// starting right and scale is left side
		if (switchSide == Side::Right)
		{
			// drive to switch
			AddSequential(new TwoWheelDriveCommand(10, 1, driveWheels));
			AddSequential(new RotateRelativeAngleCommand(-QuarterPi, rotateSpeed));
			AddSequential(new DriveStraightCommand(2.0, 0.3));
			//Deliver Cube to Switch
			AddParallel(new DeliverCubeCommand());
			AddSequential(new TimedCommand(deliverCubeDelayTime));
			AddParallel(new StopArmWheelsCommand());
		}
		else
		{
			// drive to gap between platform and cubes behind switch
			AddSequential(new TwoWheelDriveCommand(19.5, 1, driveWheels));
		}
	}
	else if (botOnLeft && scaleSide == Side::Right)
	{
		// starting right and scale is left side
		if (switchSide == Side::Left)
		{
			// drive to switch
			AddSequential(new TwoWheelDriveCommand(10, 1, driveWheels));
			AddSequential(new RotateRelativeAngleCommand(QuarterPi, rotateSpeed));
			AddSequential(new DriveStraightCommand(2.0, 0.3));
			//Deliver Cube to Switch
			AddParallel(new DeliverCubeCommand());
			AddSequential(new TimedCommand(deliverCubeDelayTime));
			AddParallel(new StopArmWheelsCommand());
		}
		else
		{
			// drive to gap between platform and cubes behind switch
			AddSequential(new TwoWheelDriveCommand(19.5, 1, driveWheels));
		}
	}
	else if (botOnLeft && scaleSide == Side::Left)
	{
		// starting left and scale is left side
		AddParallel(new MoveToAbsoluteHeightCommand(Robot::VerticalArmMovmentSubsystem->MaxScaleHeight()));
		AddSequential(new TwoWheelDriveCommand(27, 1, driveWheels));
		AddSequential(new RotateRelativeAngleCommand(HalfPi, rotateSpeed));
		AddSequential(new MoveToVerticalCubePositionCommand(Robot::VerticalArmMovmentSubsystem->MaxScaleHeight()));
		AddSequential(new TwoWheelDriveCommand(0.75, 1, driveWheels));
		// spit cube into scale
		AddParallel(new DeliverCubeCommand());
		AddSequential(new TimedCommand(deliverCubeDelayTime));
		AddParallel(new StopArmWheelsCommand());
	}
}
