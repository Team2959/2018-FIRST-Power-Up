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
#include <Commands/Auto/DriveStraightCommand.h>
#include "Commands/FoldArmsDownCommand.h"
#include "Commands/FoldArmsUpCommand.h"

TwCenterAutoCommandGroup::TwCenterAutoCommandGroup(Side switchSide, Side scaleSide) :
	frc::CommandGroup("TwCenterAuto")
{
	bool driveWheels = true;
	double rotateSpeed = 0.15;
	double deliverCubeDelayTime = 1.0;
	if(switchSide == Side::Right)
	{
		// Drive to switch.
		AddSequential(new RotateRelativeAngleCommand(QuarterPi, rotateSpeed));
		AddSequential(new TwoWheelDriveCommand(3.0, 1.0, driveWheels));
		AddSequential(new DriveStraightCommand(2.25, 0.3));
		// Deliver cube into switch.
		AddSequential(new DeliverCubeCommand());
		AddSequential(new TimedCommand(deliverCubeDelayTime));
		AddParallel(new StopArmWheelsCommand());
		//Back away from switch and go to cube pyramid.
		AddSequential(new DriveStraightCommand(1.5, -0.3));
		AddSequential(new RotateRelativeAngleCommand(-Pi/4, rotateSpeed));
		AddSequential(new FoldArmsDownCommand());
		AddParallel(new SpinArmWheelsInCommand());
		AddSequential(new TimedCommand(1.25));
		AddSequential(new DriveStraightCommand(1.5, 0.25));




//		AddSequential(new TwoWheelDriveCommand(1, -1, driveWheels));
//		AddSequential(new FoldArmsDownCommand());
//		AddSequential(new RotateRelativeAngleCommand(-QuarterPi, rotateSpeed));
//		AddParallel(new SpinArmWheelsInCommand());
//		AddSequential(new TwoWheelDriveCommand(1, 1, driveWheels));
//		//Go to switch
//		AddSequential(new TwoWheelDriveCommand(-2, -1, driveWheels));
//		AddParallel(new FoldArmsUpCommand());
//		AddSequential(new TimedCommand(0.5));
//		AddSequential(new RotateRelativeAngleCommand(QuarterPi, rotateSpeed));
//		AddSequential(new TwoWheelDriveCommand(1, 1, driveWheels));
//		// Deliver cube into switch.
//		AddSequential(new DeliverCubeCommand());
//		AddSequential(new TimedCommand(deliverCubeDelayTime));
//		AddParallel(new StopArmWheelsCommand());

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
		AddSequential(new TwoWheelDriveCommand(8.5, 1, driveWheels));
		AddSequential(new RotateRelativeAngleCommand(HalfPi, rotateSpeed));
		AddSequential(new DriveStraightCommand(1.5, 0.25));
		// Deliver cube into switch.
		AddSequential(new DeliverCubeCommand());
		AddSequential(new TimedCommand(deliverCubeDelayTime));
		AddParallel(new StopArmWheelsCommand());
		//Back away from switch.
//		AddSequential(new TwoWheelDriveCommand(1, -1, driveWheels));
//		AddSequential(new FoldArmsDownCommand());
//		AddSequential(new RotateRelativeAngleCommand(QuarterPi, rotateSpeed));
//		AddParallel(new SpinArmWheelsInCommand());
//		AddSequential(new TwoWheelDriveCommand(1, 2, driveWheels));
		//Go to switch
//		AddParallel(new FoldArmsUpCommand());
//		AddSequential(new TwoWheelDriveCommand(1, -2, driveWheels));
//		AddSequential(new RotateRelativeAngleCommand(-QuarterPi, rotateSpeed));
//		AddSequential(new TwoWheelDriveCommand(1, -1, driveWheels));
		// Deliver cube into switch.
//		AddSequential(new DeliverCubeCommand());
//		AddSequential(new TimedCommand(deliverCubeDelayTime));
//		AddParallel(new StopArmWheelsCommand());
	}
}
