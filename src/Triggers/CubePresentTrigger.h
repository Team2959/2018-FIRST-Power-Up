/*
 * CubePresentTrigger.h
 *
 *  Created on: Feb 20, 2018
 *      Author: Kevin
 */

#ifndef SRC_TRIGGERS_CUBEPRESENTTRIGGER_H_
#define SRC_TRIGGERS_CUBEPRESENTTRIGGER_H_

#include <Buttons/Trigger.h>

class CubePresentTrigger: public frc::Trigger
{
public:
	CubePresentTrigger();

	bool Get() override;
};

#endif /* SRC_TRIGGERS_CUBEPRESENTTRIGGER_H_ */
