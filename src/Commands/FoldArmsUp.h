/*
 * FoldArmsUp.h
 *
 *  Created on: Jan 31, 2018
 *      Author: &+(Kangaroo-kanga)
 */

#ifndef SRC_FOLD_ARMS_UP_H_
#define SRC_FOLD_ARMS_UP_H_

#include <Commands/Command.h>

class FoldArmsUp: public frc::Command
{
public:
	FoldArmsUp();
	~FoldArmsUp() override = default;

	void Initialize() override;
	bool IsFinished() override;
};

#endif /* SRC_FOLD_ARMS_UP_H_ */
