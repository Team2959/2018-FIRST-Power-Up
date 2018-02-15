/*
 * DriveToVisionTargetCommand.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: Tracy
 */

#include <Commands/Auto/DriveToVisionTargetCommand.h>
#include <robot.h>

DriveToVisionTargetCommand::DriveToVisionTargetCommand()
{
	Requires(Robot::VisionSubsystem.get());


	Requires(Robot::DriveTrainSubsystem.get());

}

void DriveToVisionTargetCommand::Execute()
{

}


bool DriveToVisionTargetCommand::IsFinished()
{
	return false;
}

void DriveToVisionTargetCommand::End()
{
}
double	DriveToVisionTargetCommand::FindTarget()
{
	Vision*	vision = Robot::VisionSubsystem.get();
	std::vector<VisionObject> visionObjects = vision->GetObjects(TapeColor);
	if(visionObjects.size() == 0)
		return NoTarget;
	double minX = 100;
	double maxX = -100;
	for (unsigned i = 0;i!=visionObjects.size();i++){
		double	left = visionObjects[i].Left();
		double right = left + visionObjects[i].Width();
		if (left<minX){
			minX = left;

		}
		if (right>maxX){
			maxX = right;
		}
	}
	if (maxX - minX>= TargetSize){
		return AtTarget;
	}
	return (minX + maxX)/2;

}
