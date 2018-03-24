/*
 * TwSwitchCubeScaleCommandGroup.cpp
 *
 *  Created on: Mar 23, 2018
 *      Author: Kevin
 */

#include <Commands/Auto/TwSwitchCubeScaleCommandGroup.h>
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


TwSwitchCubeScaleCommandGroup::TwSwitchCubeScaleCommandGroup(bool botOnLeft, Side switchSide, Side scaleSide):
	frc::CommandGroup("TwSwitchCubeScale")
{
	if(botOnLeft && switchSide== Side::Left)
	{
		// drive to switch
		AddSequential(new TwoWheelDriveCommand(10, 1, false));
		// spit cube into switch
		AddSequential(new DeliverCubeCommand());
		AddSequential(new TimedCommand(1.5));
		AddParallel(new StopArmWheelsCommand());
		// back away from switch
		AddSequential(new TwoWheelDriveCommand(1, -1, false));
		// turn 45 left toward outside wall
		AddSequential(new RotateRelativeAngleCommand(-QuarterPi,1));
		// drive toward outside wall
		AddSequential(new TwoWheelDriveCommand(7, 1, false));
		// turn up field
		AddSequential(new RotateRelativeAngleCommand(QuarterPi,1));
		// drive beyond switch
		AddSequential(new TwoWheelDriveCommand(6, 1, false));
		// turn toward cubes behind switch
		AddSequential(new RotateRelativeAngleCommand(HalfPi,1));
		AddParallel(new SpinArmWheelsInCommand());
		// drive to pickup cube
		AddSequential(new TwoWheelDriveCommand(6, 1, false));

		// check to see scale side
		if (scaleSide == Side::Left)
		{
			// turn toward scale, fold in and lift
			AddSequential(new RotateRelativeAngleCommand(-3 * QuarterPi,1));
			AddParallel(new FoldArmsUpCommand());
			AddParallel(new MoveToVerticalCubePositionCommand(VerticalArmMovement::CubeVerticalPlace::Scale));
			// Drive to scale
			AddSequential(new TwoWheelDriveCommand(5, 1, false));
			// spit cube into scale
			AddSequential(new DeliverCubeCommand());
			AddSequential(new TimedCommand(1.5));
			AddParallel(new StopArmWheelsCommand());
		}
		else
		{
			// right side scale
			AddSequential(new RotateRelativeAngleCommand(-QuarterPi,1));
			AddParallel(new FoldArmsUpCommand());
			AddSequential(new TwoWheelDriveCommand(1.5, 1, false));
			AddSequential(new RotateRelativeAngleCommand(QuarterPi,1));
			// cross to far side
			AddSequential(new TwoWheelDriveCommand(14, 1, false));
			AddSequential(new RotateRelativeAngleCommand(-HalfPi,1));
			// drive toward center of scale
			AddSequential(new TwoWheelDriveCommand(8, 1, false));
			AddParallel(new MoveToVerticalCubePositionCommand(VerticalArmMovement::CubeVerticalPlace::Scale));
			AddSequential(new RotateRelativeAngleCommand(-3 * QuarterPi,1));
			AddSequential(new TwoWheelDriveCommand(2, 1, false));
			// spit cube into scale
			AddSequential(new DeliverCubeCommand());
			AddSequential(new TimedCommand(1.5));
			AddParallel(new StopArmWheelsCommand());
		}
	}
	else if (botOnLeft && switchSide == Side::Right)
	{
		AddSequential(new RotateRelativeAngleCommand(-QuarterPi,1));
		AddSequential(new TwoWheelDriveCommand(2, 1, false));
		AddSequential(new RotateRelativeAngleCommand(QuarterPi,1));

		if (scaleSide== Side::Left)
		{
			AddSequential(new TwoWheelDriveCommand(23, 1, false));
			AddSequential(new RotateRelativeAngleCommand(QuarterPi,1));
			AddSequential(new TwoWheelDriveCommand(1, 1, false));
			// spit cube into scale
			AddSequential(new DeliverCubeCommand());
			AddSequential(new TimedCommand(1.5));
			AddParallel(new StopArmWheelsCommand());
		}
		else
		{
			// drive to between platform and switch
			AddSequential(new TwoWheelDriveCommand(15.5, 1, false));
			// turn to right side
			AddSequential(new RotateRelativeAngleCommand(HalfPi,1));
			// drive between platform and switch
			AddSequential(new TwoWheelDriveCommand(20, 1, false));
			// turn up field
			AddSequential(new RotateRelativeAngleCommand(HalfPi,-1));
			// drive toward center of scale
			AddSequential(new TwoWheelDriveCommand(8, 1, false));
			AddParallel(new MoveToVerticalCubePositionCommand(VerticalArmMovement::CubeVerticalPlace::Scale));
			AddSequential(new RotateRelativeAngleCommand(-3 * QuarterPi,1));
			AddSequential(new TwoWheelDriveCommand(2, 1, false));
			// spit cube into scale
			AddSequential(new DeliverCubeCommand());
			AddSequential(new TimedCommand(1.5));
			AddParallel(new StopArmWheelsCommand());
		}
	}
	else if (!botOnLeft && switchSide== Side::Right)
	{
		AddSequential(new TwoWheelDriveCommand(10, 1, false));
		AddSequential(new RotateRelativeAngleCommand(-HalfPi,1));
		AddSequential(new TwoWheelDriveCommand(2, 1, false));
		// spit cube into switch
		AddSequential(new DeliverCubeCommand());
		AddSequential(new TimedCommand(1.5));
		AddParallel(new StopArmWheelsCommand());
		//Backwards from the switch
		AddSequential(new TwoWheelDriveCommand(2, -1, false));
		AddSequential(new RotateRelativeAngleCommand(HalfPi,-1));
		AddSequential(new TwoWheelDriveCommand(9, -1, false));
		AddSequential(new RotateRelativeAngleCommand(-HalfPi,1));
		AddSequential(new TwoWheelDriveCommand(4, -1, false));
		AddParallel(new FoldArmsDownCommand());
		AddSequential(new RotateRelativeAngleCommand(QuarterPi,1));
		AddSequential(new TwoWheelDriveCommand(1.5, 1, false));

		if (scaleSide== Side::Left)
		{
			AddSequential(new TwoWheelDriveCommand(2, -1, false));
			AddParallel(new FoldArmsUpCommand());
			AddSequential(new RotateRelativeAngleCommand(3 * QuarterPi,1));
			AddSequential(new TwoWheelDriveCommand(11, -1, false));
			AddSequential(new RotateRelativeAngleCommand(HalfPi,1));
			AddParallel(new MoveToVerticalCubePositionCommand(VerticalArmMovement::CubeVerticalPlace::Scale));
			AddSequential(new TwoWheelDriveCommand(6, 1, false));
			AddSequential(new RotateRelativeAngleCommand(QuarterPi,1));
			AddSequential(new TwoWheelDriveCommand(0.5, 1, false));
			// spit cube into scale
			AddSequential(new DeliverCubeCommand());
			AddSequential(new TimedCommand(1.5));
			AddParallel(new StopArmWheelsCommand());

		}

		else
		{
			AddSequential(new RotateRelativeAngleCommand(-HalfPi,1));
			AddSequential(new TwoWheelDriveCommand(10, 1, false));
			AddParallel(new FoldArmsUpCommand());
			AddSequential(new RotateRelativeAngleCommand(3 * QuarterPi,-1));
			AddParallel(new MoveToVerticalCubePositionCommand(VerticalArmMovement::CubeVerticalPlace::Scale));
			AddSequential(new TwoWheelDriveCommand(3, 1, false));
			// spit cube into scale
			AddSequential(new DeliverCubeCommand());
			AddSequential(new TimedCommand(1.5));
			AddParallel(new StopArmWheelsCommand());

		}

	}
	else //if(!botOnLeft && switchSide== Side::Left)
	{
		if (scaleSide== Side::Left)
		{

		}

		else
		{

		}
	}
}
