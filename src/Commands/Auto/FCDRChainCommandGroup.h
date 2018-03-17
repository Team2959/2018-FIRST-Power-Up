/*
 * FCDRChainCommandGroup.h
 *
 *  Created on: Mar 10, 2018
 *      Author: jcopi
 */

#ifndef SRC_COMMANDS_AUTO_FCDRCHAINCOMMANDGROUP_H_
#define SRC_COMMANDS_AUTO_FCDRCHAINCOMMANDGROUP_H_

#include <Commands/CommandGroup.h>
#include <vector>

typedef struct _FCDRObj {
	frc::Command* cmd;
	bool waitForCompletion;
} FCDRObj;

class FCDRChainCommandGroup: public frc::CommandGroup {
public:
	FCDRChainCommandGroup(std::vector<FCDRObj>);

};

#endif /* SRC_COMMANDS_AUTO_FCDRCHAINCOMMANDGROUP_H_ */
