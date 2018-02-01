/*
 * FoldArmsUp.h
 *
 *  Created on: Jan 31, 2018
 *      Author: &+(Kangaroo-kanga)
 */
#pragma once


#ifndef SRC_SUBSYSTEMS_FOLDARMSUP_H_
#define SRC_SUBSYSTEMS_FOLDARMSUP_H_
#endif /* SRC_SUBSYSTEMS_FOLDARMSUP_H_ */
#include <Commands/Command.h>

class FoldArmsUp: public frc::Command {
public:
	FoldArmsUp();
	virtual ~FoldArmsUp();

void Execute() override;
void End() override;
void Interrupted() override;
bool IsFinished() override;
};
