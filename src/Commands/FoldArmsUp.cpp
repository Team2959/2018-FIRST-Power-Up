/*
 * FoldArmsUp.cpp
 *
 *  Created on: Jan 31, 2018
 *      Author: Andrew
 */

#include <Commands/FoldArmsUp.h>

FoldArmsUp::FoldArmsUp() : Command("FoldArmsUp")
{
	Requires(Robot::CubeArmsSubsystem.get());
}
void FoldArmsUp::Execute()

{
		//make Solenoids go out
}



	bool FoldArmsUp::IsFinished()
	{
return true;
}
