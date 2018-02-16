/*
 * FindDriveTarget.cpp
 *
 *  Created on: Feb 16, 2018
 *      Author: Bryce's Omen
 */

#include <Commands/Auto/FindDriveTarget.h>
#include <Robot.h>
#include <Autonomous.h>
FindDriveTarget::FindDriveTarget() {
	// TODO Auto-generated constructor stub
	Requires(Robot::VisionSubsystem.get());


		Requires(Robot::DriveTrainSubsystem.get());
}

FindDriveTarget::~FindDriveTarget() {
	// TODO Auto-generated destructor stub
}

	void FindDriveTarget::Execute() {
		DriveTrain* driveTrain= Robot::DriveTrainSubsystem.get();
		double targetLocation = FindTarget();
		if(( targetLocation<0.5)&&(Autonomous::GetNearSwitchSide() == Autonomous::Side::Left)){
			driveTrain->Drive(0,0,-1);
			return;
		}
		if(( targetLocation>0.5)&&(Autonomous::GetNearSwitchSide() == Autonomous::Side::Right)){
					driveTrain->Drive(0,0,1);
					return;
				}
		m_AtTarget = true;
	}
	bool FindDriveTarget::IsFinished() {
return m_AtTarget;
	}
	void FindDriveTarget::End() {
		DriveTrain* driveTrain= Robot::DriveTrainSubsystem.get();
				driveTrain->Drive(0,0,0);
	}
	double	FindDriveTarget::FindTarget(){
		Vision*	vision = Robot::VisionSubsystem.get();
				std::vector<VisionObject> visionObjects = vision->GetObjects(CubeColor);
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
								return (minX + maxX)/2;
	}
