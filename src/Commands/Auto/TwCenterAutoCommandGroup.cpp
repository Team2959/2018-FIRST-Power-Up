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
#include <Commands/Auto/AutoStopWheelSpinCommand.h>

TwCenterAutoCommandGroup::TwCenterAutoCommandGroup(Side switchSide) :
	frc::CommandGroup("TwCenterAuto")
{
	bool driveWheels = true;
	double rotateSpeed = 0.15;
	double deliverCubeDelayTime = 1.0;
	double foldArmsTime = 1.25;
	if (switchSide == Side::Right)
	{
		// Drive to right switch from center.
		AddSequential(new RotateRelativeAngleCommand(QuarterPi, rotateSpeed));
		AddSequential(new TwoWheelDriveCommand(3.0, 1.0, driveWheels));
		AddSequential(new DriveStraightCommand(2.25, 0.3));
		// Deliver cube into switch.
		AddParallel(new DeliverCubeCommand());
		AddSequential(new TimedCommand(deliverCubeDelayTime));
		AddParallel(new StopArmWheelsCommand());
		//Back away from switch and go to cube pyramid.
		AddSequential(new DriveStraightCommand(1.5, -0.3));
		AddSequential(new RotateRelativeAngleCommand(-QuarterPi, rotateSpeed));
		AddParallel(new FoldArmsDownCommand());
		AddSequential(new TimedCommand(foldArmsTime));
		AddParallel(new SpinArmWheelsInCommand());
		AddSequential(new DriveStraightCommand(1.5, 0.25));
		AddSequential(new AutoStopWheelSpinCommand());
		// reverse drive back to switch
		AddSequential(new DriveStraightCommand(1.5, -0.25));
		AddParallel(new FoldArmsUpCommand());
		AddSequential(new TimedCommand(foldArmsTime));
		AddSequential(new RotateRelativeAngleCommand(QuarterPi, rotateSpeed));
		AddSequential(new DriveStraightCommand(1.5, 0.3));
		// Deliver cube into switch.
		AddParallel(new DeliverCubeCommand());
		AddSequential(new TimedCommand(deliverCubeDelayTime));
		AddParallel(new StopArmWheelsCommand());
	}
	else //if (switchSide == Side::Left)
	{
		// Drive to left switch from center.
		AddSequential(new RotateRelativeAngleCommand(-QuarterPi, rotateSpeed));
		AddSequential(new TwoWheelDriveCommand(8.5, 1, driveWheels));
		AddSequential(new RotateRelativeAngleCommand(HalfPi, rotateSpeed));
		AddSequential(new DriveStraightCommand(1.5, 0.25));
		// Deliver cube into switch.
		AddParallel(new DeliverCubeCommand());
		AddSequential(new TimedCommand(deliverCubeDelayTime));
		AddParallel(new StopArmWheelsCommand());
		//Back away from switch.
		AddSequential(new TwoWheelDriveCommand(1.5, -1, driveWheels));
		AddSequential(new RotateRelativeAngleCommand(QuarterPi, rotateSpeed));
		AddParallel(new FoldArmsDownCommand());
		AddSequential(new TimedCommand(foldArmsTime));
		AddParallel(new SpinArmWheelsInCommand());
		AddSequential(new TwoWheelDriveCommand(2.35, 1, driveWheels));
		AddSequential(new AutoStopWheelSpinCommand());
		//Go to switch
		AddSequential(new TwoWheelDriveCommand(2.35, -1, driveWheels));
		AddParallel(new FoldArmsUpCommand());
		AddSequential(new TimedCommand(foldArmsTime));
		AddSequential(new RotateRelativeAngleCommand(-QuarterPi, rotateSpeed));
		AddSequential(new TwoWheelDriveCommand(1.75, 1, driveWheels));
		// Deliver cube into switch.
		AddParallel(new DeliverCubeCommand());
		AddSequential(new TimedCommand(deliverCubeDelayTime));
		AddParallel(new StopArmWheelsCommand());
	}
}
