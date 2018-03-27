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

TwScaleOnlyCommandGroup::TwScaleOnlyCommandGroup(bool botOnLeft, Side scaleSide) :
frc::CommandGroup("TwScaleOnly")
{

	if(botOnLeft && scaleSide == Side::Left)
	{
		AddParallel(new MoveToAbsoluteHeightCommand(Robot::VerticalArmMovmentSubsystem->MaxScaleHeight()));
		AddSequential(new TwoWheelDriveCommand(25, 1, false));
		AddSequential(new MoveToVerticalCubePositionCommand(Robot::VerticalArmMovmentSubsystem->MaxScaleHeight()));
		// spit cube into scale
		AddSequential(new DeliverCubeCommand());
		AddSequential(new TimedCommand(1.5));
		AddParallel(new StopArmWheelsCommand());
	}
	if(botOnLeft && scaleSide == Side::Right)
	{
		AddSequential(new TwoWheelDriveCommand(19.5, 1, false));
		AddSequential(new RotateRelativeAngleCommand(.90 * HalfPi, 0.3));
		AddSequential(new TwoWheelDriveCommand(23.75, 1, false));
		AddSequential(new RotateRelativeAngleCommand(-0.95 * HalfPi, 0.3));
		AddParallel(new MoveToAbsoluteHeightCommand(Robot::VerticalArmMovmentSubsystem->MaxScaleHeight()));
		AddSequential(new TwoWheelDriveCommand(8, 1, false));
		AddParallel(new RotateRelativeAngleCommand(-3 * QuarterPi, 0.3));
		AddSequential(new MoveToVerticalCubePositionCommand(Robot::VerticalArmMovmentSubsystem->MaxScaleHeight()));
		// spit cube into scale
		AddSequential(new DeliverCubeCommand());
		AddSequential(new TimedCommand(1.5));
		AddParallel(new StopArmWheelsCommand());
	}
	if(!botOnLeft && scaleSide == Side::Left)
	{
		AddSequential(new TwoWheelDriveCommand(19.5, 1, false));
				AddSequential(new RotateRelativeAngleCommand(-0.90 * HalfPi, 0.3));
				AddSequential(new TwoWheelDriveCommand(21, 1, false));
				AddSequential(new RotateRelativeAngleCommand(0.95 * HalfPi, 0.3));
				AddParallel(new MoveToAbsoluteHeightCommand(Robot::VerticalArmMovmentSubsystem->MaxScaleHeight()));
				AddSequential(new TwoWheelDriveCommand(8, 1, false));
				AddParallel(new RotateRelativeAngleCommand(QuarterPi, 0.3));
				AddSequential(new MoveToVerticalCubePositionCommand(Robot::VerticalArmMovmentSubsystem->MaxScaleHeight()));
				// spit cube into scale
				AddSequential(new DeliverCubeCommand());
				AddSequential(new TimedCommand(1.5));
				AddParallel(new StopArmWheelsCommand());
	}
	if(!botOnLeft && scaleSide == Side::Right)
	{
		AddSequential(new TwoWheelDriveCommand(27, 1, false));
		AddParallel(new RotateRelativeAngleCommand(-HalfPi, 0.3));
		AddSequential(new MoveToAbsoluteHeightCommand(Robot::VerticalArmMovmentSubsystem->MaxScaleHeight()));
		AddSequential(new TwoWheelDriveCommand(0.75, 1, false));
		// spit cube into scale
		AddSequential(new DeliverCubeCommand());
		AddSequential(new TimedCommand(1.5));
		AddParallel(new StopArmWheelsCommand());

	}
}

TwScaleOnlyCommandGroup::~TwScaleOnlyCommandGroup()
{

}

