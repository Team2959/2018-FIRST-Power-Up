/*
 * PlaceCubeOurSideOnlyPlaceCubeOurSideOnlyCommandGroup.cpp
 *
 *  Created on: Mar 5, 2018
 *      Author: Aria
 */

#include <Commands/Auto/PlaceCubeOurSideOnlyCommandGroup.h>
#include "Commands/Auto/PlaceInitialCubeOnSwitchCommandGroup.h"
#include <Commands/Auto/DeadReckoningCommand.h>
#include <Commands/Auto/MoveToVerticalCubePositionCommand.h>
#include <Commands/DeliverCubeCommand.h>
#include <Subsystems/VerticalArmMovement.h>
#include <Commands/Auto/DriveStraightCommand.h>
#include <SmartDashboard/SmartDashboard.h>
#include "RobotMap.h"
#include <Commands/StopArmWheelsCommand.h>
#include <Commands/Auto/DeliverCubeUntilNotPresentCommand.h>

PlaceCubeOurSideOnlyCommandGroup::PlaceCubeOurSideOnlyCommandGroup(Side nearSwitchSide):
	frc::CommandGroup("PlaceCubeOurSideOnly")
{
	bool startLeft = frc::SmartDashboard::GetBoolean("Is Auton Starting Left?", true);

	if ((startLeft && nearSwitchSide == Side::Left) ||
		(startLeft == false && nearSwitchSide == Side::Right))
	{
//		AddSequential(new PlaceInitialCubeOnSwitchCommandGroup(nearSwitchSide));
		double time = frc::SmartDashboard::GetNumber("Auton Straight Time", 4.0);

		AddSequential(new DriveStraightCommand(time));
		AddSequential(new DeliverCubeUntilNotPresentCommand(), 2.5);
//		AddParallel(new DeliverCubeCommand());
//		AddSequential(new TimedCommand(2.5));
//		AddParallel(new StopArmWheelsCommand());
	}
	else
	{
		AddSequential(new DriveStraightCommand(3.5));
//		double angle = QuarterPi;
//		double rotation = -1;
//		if (startLeft)
//		{
//			angle = 3 * QuarterPi;
//			rotation = 1;
//		}
//		// angle to wall
//		AddSequential(new DeadReckoningCommand(2.0, 1.0, angle, 0.0));
//		// straight along wall
//		AddSequential(new DeadReckoningCommand(3.0, 1.0, HalfPi, 0.0));
//		// rotate towards scale
//		AddSequential(new DeadReckoningCommand(0.5, 0.5, 0, rotation));
//		// move closer to scale
//		AddSequential(new DeadReckoningCommand(0.5, 0.5, HalfPi, 0.0));
		// raise arm to scale height
//		AddSequential(new MoveToVerticalCubePositionCommand(VerticalArmMovement::Scale, VerticalArmMovement::ScaleHeightMaximum));
//		AddSequential(new DeliverCubeCommand());
	}
}
