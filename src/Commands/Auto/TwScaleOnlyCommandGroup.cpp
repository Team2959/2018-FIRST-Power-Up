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

TwScaleOnlyCommandGroup::TwScaleOnlyCommandGroup(bool botOnLeft, Side scaleSide) :
	frc::CommandGroup("TwScaleOnly")
{
	bool driveWheels = true;
	double rotateSpeed = 0.15;
	double deliverCubeDelayTime = 1.0;
	if(!botOnLeft && scaleSide == Side::Right)
	{
		AddParallel(new MoveToAbsoluteHeightCommand(Robot::VerticalArmMovmentSubsystem->MaxScaleHeight()));
		AddSequential(new TwoWheelDriveCommand(25.5, 1, driveWheels));
		AddSequential(new MoveToVerticalCubePositionCommand(Robot::VerticalArmMovmentSubsystem->MaxScaleHeight()));
		AddSequential(new RotateRelativeAngleCommand(-QuarterPi, rotateSpeed));
		// spit cube into scale
		AddSequential(new DeliverCubeCommand());
		AddSequential(new TimedCommand(deliverCubeDelayTime));
		AddParallel(new StopArmWheelsCommand());
		AddSequential(new MoveToVerticalCubePositionCommand(0));
	}
	else if(!botOnLeft && scaleSide == Side::Left)
	{
		AddSequential(new TwoWheelDriveCommand(19.5, 1, driveWheels));
		AddSequential(new RotateRelativeAngleCommand(-HalfPi, rotateSpeed));
		AddSequential(new TwoWheelDriveCommand(18.0, 1, driveWheels));
		AddParallel(new MoveToAbsoluteHeightCommand(Robot::VerticalArmMovmentSubsystem->MaxScaleHeight()));
		AddSequential(new RotateRelativeAngleCommand(3 * QuarterPi, rotateSpeed));
		AddSequential(new MoveToVerticalCubePositionCommand(Robot::VerticalArmMovmentSubsystem->MaxScaleHeight()));
		AddSequential(new DriveStraightCommand(2.0, 0.25));
		// spit cube into scale
		AddSequential(new DeliverCubeCommand());
		AddSequential(new TimedCommand(deliverCubeDelayTime));
		AddParallel(new StopArmWheelsCommand());
		AddSequential(new MoveToVerticalCubePositionCommand(0));
	}
	else if(botOnLeft && scaleSide == Side::Right)
	{
		AddSequential(new TwoWheelDriveCommand(19.5, 1, driveWheels));
		AddSequential(new RotateRelativeAngleCommand(HalfPi, rotateSpeed));
		AddSequential(new TwoWheelDriveCommand(21, 1, driveWheels));
		AddSequential(new RotateRelativeAngleCommand(-HalfPi, rotateSpeed));
		AddParallel(new MoveToAbsoluteHeightCommand(Robot::VerticalArmMovmentSubsystem->MaxScaleHeight()));
		AddSequential(new TwoWheelDriveCommand(8, 1, driveWheels));
		AddParallel(new RotateRelativeAngleCommand(-QuarterPi, rotateSpeed));
		AddSequential(new MoveToVerticalCubePositionCommand(Robot::VerticalArmMovmentSubsystem->MaxScaleHeight()));
		// spit cube into scale
		AddSequential(new DeliverCubeCommand());
		AddSequential(new TimedCommand(deliverCubeDelayTime));
		AddParallel(new StopArmWheelsCommand());
	}
	else if(botOnLeft && scaleSide == Side::Left)
	{
		AddParallel(new MoveToAbsoluteHeightCommand(Robot::VerticalArmMovmentSubsystem->MaxScaleHeight()));
		AddSequential(new TwoWheelDriveCommand(27, 1, driveWheels));
		AddSequential(new RotateRelativeAngleCommand(HalfPi, rotateSpeed));
		AddSequential(new MoveToVerticalCubePositionCommand(Robot::VerticalArmMovmentSubsystem->MaxScaleHeight()));
		AddSequential(new TwoWheelDriveCommand(0.75, 1, driveWheels));
		// spit cube into scale
		AddSequential(new DeliverCubeCommand());
		AddSequential(new TimedCommand(deliverCubeDelayTime));
		AddParallel(new StopArmWheelsCommand());
	}
}

TwScaleOnlyCommandGroup::~TwScaleOnlyCommandGroup()
{
}
