/*
 * VerticleMovementCommand.cpp
 *
 *  Created on: Feb 9, 2018
 *      Author: Andrew
 */

#include <Commands/VerticalMovementCommand.h>

VerticalMovementCommand::VerticalMovementCommand()
{

}
void VerticalMovementCommand::InitDefaultCommand()
{

}
void Execute()
{
	double autoAxis = Robot::oi->GetButtonBox()->GetRawAxis(2);
}
bool IsFinished()
{
	return false;
}



