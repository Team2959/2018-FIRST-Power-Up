/*
 * FoldArmsUp.h
 *
 *  Created on: Jan 31, 2018
 *      Author: &+(Kangaroo-kanga)
 */

#pragma once

#include <Commands/Command.h>

class FoldArmsUp: public frc::Command
{
public:
	FoldArmsUp();
	~FoldArmsUp() override = default;

	void Initialize() override;
	bool IsFinished() override;
};
