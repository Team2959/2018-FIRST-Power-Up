/*
 * PlaceCubeOurSideOnly.cpp
 *
 *  Created on: Mar 5, 2018
 *      Author: Kevin
 */

#include <Commands/Auto/PlaceCubeOurSideOnly.h>
#include <Commands/DeliverCubeCommand.h>
#include <Commands/Auto/MoveToVerticalCubePositionCommand.h>
#include <Commands/FoldArmsDownCommand.h>
#include <Subsystems/VerticalArmMovement.h>
#include <Commands/Auto/FindDriveTarget.h>
#include <Commands/Auto/DriveToVisionTargetCommand.h>
#include <Commands/Auto/DriveStraightCommand.h>
#include <SmartDashboard/SmartDashboard.h>
#include "Commands/Auto/PlaceInitialCubeOnSwitchCommandGroup.h"
#include <Commands/Auto/DeadReckoningCommand.h>


PlaceCubeOurSideOnly::PlaceCubeOurSideOnly(Side nearSwitchSide):
	frc::CommandGroup("PlaceCubeOurSideOnly")
{
	bool startLeft = frc::SmartDashboard::GetBoolean("Is Auton Starting Left?", true);

	if ((startLeft && nearSwitchSide == Side::Left) ||
			(startLeft == false && nearSwitchSide == Side::Right))
	{
		AddSequential(new PlaceInitialCubeOnSwitchCommandGroup(nearSwitchSide));
	}
	else
	{
		AddSequential(new DeadReckoningCommand);
	}
}
