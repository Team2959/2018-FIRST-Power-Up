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
#include <iostream>
#include <Commands/Auto/DeliverCubeUntilNotPresentCommand.h>

TwSwitchCubeScaleCommandGroup::TwSwitchCubeScaleCommandGroup(bool botOnLeft, Side switchSide, Side scaleSide):
	frc::CommandGroup("TwSwitchCubeScale")
{
	bool driveWheels = true;
	double rotateSpeed = 0.15;
	double deliverCubeDelayTime = 1.0;
	if(!botOnLeft && switchSide == Side::Right)
	{
		std::cout << "Starting -- Right side switch from right \n";
		// drive to switch
		AddSequential(new TwoWheelDriveCommand(9.5, 1, driveWheels));
		// spit cube into switch
//		AddSequential(new DeliverCubeUntilNotPresentCommand(), deliverCubeDelayTime);
		AddParallel(new DeliverCubeCommand());
		AddSequential(new TimedCommand(deliverCubeDelayTime));
		AddParallel(new StopArmWheelsCommand());
		// back away from switch
		AddSequential(new TwoWheelDriveCommand(1, -1, driveWheels));
		// turn 45 left toward outside wall
		AddSequential(new RotateRelativeAngleCommand(QuarterPi,1));
		// drive toward outside wall
//		AddSequential(new TwoWheelDriveCommand(5, 1, driveWheels));
		// turn up field
//		AddSequential(new RotateRelativeAngleCommand(-QuarterPi,1));
		// drive beyond switch
//		AddSequential(new TwoWheelDriveCommand(7, 1, driveWheels));
//		// turn toward cubes behind switch
//		AddSequential(new RotateRelativeAngleCommand(-QuarterPi,1));
//		AddParallel(new FoldArmsDownCommand());
//		AddParallel(new SpinArmWheelsInCommand());
//		// drive to pickup cube
//		AddSequential(new TwoWheelDriveCommand(6, 1, driveWheels));

		// check to see scale side
		if (scaleSide == Side::Left)
		{
			// turn toward scale, fold in and lift
			//AddSequential(new RotateRelativeAngleCommand(-3 * QuarterPi,rotateSpeed));
			//AddParallel(new FoldArmsUpCommand());
			//AddParallel(new MoveToVerticalCubePositionCommand(VerticalArmMovement::CubeVerticalPlace::Scale));
			// Drive to scale
			//AddSequential(new TwoWheelDriveCommand(5, 1, driveWheels));
			// spit cube into scale
			//AddSequential(new DeliverCubeCommand());
			//AddSequential(new TimedCommand(deliverCubeDelayTime));
			//AddParallel(new StopArmWheelsCommand());
		}
		else
		{
			// right side scale
			//AddSequential(new RotateRelativeAngleCommand(-QuarterPi,rotateSpeed));
			//AddParallel(new FoldArmsUpCommand());
			//AddSequential(new TwoWheelDriveCommand(1.5, 1, driveWheels));
			//AddSequential(new RotateRelativeAngleCommand(QuarterPi,rotateSpeed));
			// cross to far side
			//AddSequential(new TwoWheelDriveCommand(14, 1, driveWheels));
			//AddSequential(new RotateRelativeAngleCommand(-HalfPi,rotateSpeed));
			// drive toward center of scale
			//AddSequential(new TwoWheelDriveCommand(8, 1, driveWheels));
			//AddParallel(new MoveToVerticalCubePositionCommand(VerticalArmMovement::CubeVerticalPlace::Scale));
			//AddSequential(new RotateRelativeAngleCommand(-3 * QuarterPi,rotateSpeed));
			//AddSequential(new TwoWheelDriveCommand(2, 1, driveWheels));
			// spit cube into scale
			//AddSequential(new DeliverCubeCommand());
			//AddSequential(new TimedCommand(deliverCubeDelayTime));
			//AddParallel(new StopArmWheelsCommand());
		}
	}
	else if (!botOnLeft && switchSide == Side::Left)
	{
		std::cout << "Starting -- Left side switch from right \n";
		AddSequential(new TwoWheelDriveCommand(9, 1, driveWheels));
//		AddSequential(new RotateRelativeAngleCommand(QuarterPi, rotateSpeed));
//		AddSequential(new TwoWheelDriveCommand(2, 1, driveWheels));
//		AddSequential(new RotateRelativeAngleCommand(-QuarterPi, rotateSpeed));

		if (scaleSide== Side::Right)
		{
//			AddSequential(new TwoWheelDriveCommand(23, 1, driveWheels));
//			AddSequential(new RotateRelativeAngleCommand(-QuarterPi, rotateSpeed));
//			AddSequential(new TwoWheelDriveCommand(1, 1, driveWheels));
//			// spit cube into scale
//			AddSequential(new DeliverCubeCommand());
//			AddSequential(new TimedCommand(deliverCubeDelayTime));
//			AddParallel(new StopArmWheelsCommand());
		}
		else
		{
			// drive to between platform and switch
//			AddSequential(new TwoWheelDriveCommand(15.5, 1, driveWheels));
//			// turn to right side
//			AddSequential(new RotateRelativeAngleCommand(-HalfPi, rotateSpeed));
//			// drive between platform and switch
//			AddSequential(new TwoWheelDriveCommand(20, 1, driveWheels));
//			// turn up field
//			AddSequential(new RotateRelativeAngleCommand(HalfPi, rotateSpeed));
			// drive toward center of scale
//			AddSequential(new TwoWheelDriveCommand(8, 1, driveWheels));
//			AddParallel(new MoveToVerticalCubePositionCommand(VerticalArmMovement::CubeVerticalPlace::Scale));
//			AddSequential(new RotateRelativeAngleCommand(3 * QuarterPi, rotateSpeed));
//			AddSequential(new TwoWheelDriveCommand(2, 1, driveWheels));
			// spit cube into scale
//			AddSequential(new DeliverCubeCommand());
//			AddSequential(new TimedCommand(deliverCubeDelayTime));
//			AddParallel(new StopArmWheelsCommand());
		}
	}
	else if (botOnLeft && switchSide== Side::Left)
	{
		std::cout << "Starting -- Left side switch from left \n";
		AddSequential(new TwoWheelDriveCommand(10.5, 1, driveWheels));
		AddSequential(new RotateRelativeAngleCommand(HalfPi, rotateSpeed));
		AddSequential(new TwoWheelDriveCommand(2, 1, driveWheels));
		// spit cube into switch
//		AddSequential(new DeliverCubeUntilNotPresentCommand(), deliverCubeDelayTime);
		AddParallel(new DeliverCubeCommand());
		AddSequential(new TimedCommand(deliverCubeDelayTime));
		AddParallel(new StopArmWheelsCommand());
		//Backwards from the switch
		AddSequential(new TwoWheelDriveCommand(2, -1, driveWheels));
		AddSequential(new RotateRelativeAngleCommand(-HalfPi, rotateSpeed));
//		AddSequential(new TwoWheelDriveCommand(9, -1, driveWheels));
//		AddSequential(new RotateRelativeAngleCommand(-HalfPi, rotateSpeed));
//		AddSequential(new TwoWheelDriveCommand(4, -1, driveWheels));
//		AddParallel(new FoldArmsDownCommand());
//		AddSequential(new RotateRelativeAngleCommand(QuarterPi, rotateSpeed));
//		AddSequential(new TwoWheelDriveCommand(1.5, 1, driveWheels));

		if (scaleSide== Side::Right)
		{
//			AddSequential(new TwoWheelDriveCommand(2, -1, driveWheels));
//			AddParallel(new FoldArmsUpCommand());
//			AddSequential(new RotateRelativeAngleCommand(3 * QuarterPi, rotateSpeed));
//			AddSequential(new TwoWheelDriveCommand(11, -1, driveWheels));
//			AddSequential(new RotateRelativeAngleCommand(HalfPi, rotateSpeed));
//			AddParallel(new MoveToVerticalCubePositionCommand(VerticalArmMovement::CubeVerticalPlace::Scale));
//			AddSequential(new TwoWheelDriveCommand(6, 1, driveWheels));
//			AddSequential(new RotateRelativeAngleCommand(QuarterPi, rotateSpeed));
//			AddSequential(new TwoWheelDriveCommand(0.5, 1, driveWheels));
//			// spit cube into scale
//			AddSequential(new DeliverCubeCommand());
//			AddSequential(new TimedCommand(deliverCubeDelayTime));
//			AddParallel(new StopArmWheelsCommand());
       	}
		else
		{
//			AddSequential(new RotateRelativeAngleCommand(-HalfPi, rotateSpeed));
//			AddSequential(new TwoWheelDriveCommand(10, 1, driveWheels));
//			AddParallel(new FoldArmsUpCommand());
//			AddSequential(new RotateRelativeAngleCommand(3 * QuarterPi, rotateSpeed));
//			AddParallel(new MoveToVerticalCubePositionCommand(VerticalArmMovement::CubeVerticalPlace::Scale));
//			AddSequential(new TwoWheelDriveCommand(3, 1, driveWheels));
//			// spit cube into scale
//			AddSequential(new DeliverCubeCommand());
//			AddSequential(new TimedCommand(deliverCubeDelayTime));
//			AddParallel(new StopArmWheelsCommand());
		}
	}
	else //if(botOnLeft && switchSide== Side::Right)
	{
		std::cout << "Starting -- Right side switch from left \n";
		AddSequential(new TwoWheelDriveCommand(9, 1, driveWheels));
		if (scaleSide== Side::Left)
		{

		}
		else
		{

		}
	}
}
