/*
 * FoldArmsUp.h
 *
 *  Created on: Jan 31, 2018
 *      Author: &+(Kangaroo-kanga)
 */

#ifndef SRC_FOLD_ARMS_UP_H_
#define SRC_FOLD_ARMS_UP_H_

#include <Commands/Command.h>

class FoldArmsUpCommand: public frc::Command
{
public:
	FoldArmsUpCommand();
	virtual void Initialize() override;
	virtual bool IsFinished() override;
};

#endif /* SRC_FOLD_ARMS_UP_H_ */
