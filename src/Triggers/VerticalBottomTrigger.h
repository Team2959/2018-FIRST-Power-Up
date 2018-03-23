/*
 * VerticalBottomTrigger.h
 *
 *  Created on: Mar 10, 2018
 *      Author: CW
 */

#ifndef SRC_TRIGGERS_VERTICALBOTTOMTRIGGER_H_
#define SRC_TRIGGERS_VERTICALBOTTOMTRIGGER_H_

#include <Buttons/Trigger.h>

class VerticalBottomTrigger: public frc::Trigger
{
public:
	VerticalBottomTrigger();

	bool Get() override;
};

#endif /* SRC_TRIGGERS_VERTICALBOTTOMTRIGGER_H_ */
