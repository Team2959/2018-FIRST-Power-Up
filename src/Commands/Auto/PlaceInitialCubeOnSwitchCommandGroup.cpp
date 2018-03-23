/*
 * AutoPlaceInitialCubeOnSwitch.cpp
 *
 *  Created on: Feb 7, 2018
 *      Author: JWB
 */

#include "Commands/Auto/PlaceInitialCubeOnSwitchCommandGroup.h"
#include <Commands/DeliverCubeCommand.h>
#include <Commands/Auto/MoveToVerticalCubePositionCommand.h>
#include <Commands/FoldArmsDownCommand.h>
#include <Subsystems/VerticalArmMovement.h>
#include <Commands/Auto/FindDriveTarget.h>
#include <Commands/Auto/DriveToVisionTargetCommand.h>
#include <Commands/Auto/DriveStraightCommand.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Commands/TimedCommand.h>
#include <Commands/StopArmWheelsCommand.h>

PlaceInitialCubeOnSwitchCommandGroup::PlaceInitialCubeOnSwitchCommandGroup(Side nearSwitchSide) :
  frc::CommandGroup("PlaceInitialCubeOnSwitch")
{
	double duration = frc::SmartDashboard::GetNumber("Auton Straight To Switch Time", 1.0);
	AddSequential(new FindDriveTarget(nearSwitchSide));
	AddSequential(new DriveToVisionTargetCommand());
	//AddSequential(new MoveToVerticalCubePositionCommand(VerticalArmMovement::Switch));
	//AddSequential(new FoldArmsDownCommand());
	AddSequential(new DriveStraightCommand(duration));
	AddSequential(new DeliverCubeCommand());
	AddSequential(new TimedCommand(1.5));
	AddSequential(new StopArmWheelsCommand());
}
