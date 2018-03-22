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
#include <stdlib.h>
#include <iostream>

typedef struct _FCDRObj {
	frc::Command* cmd;
	bool waitForCompletion;
} FCDRObj;

class FCDRChainCommandGroup: public frc::CommandGroup {
public:
	FCDRChainCommandGroup(std::string chain);

};

std::vector<std::string> split(std::string str, std::string delims);

#endif /* SRC_COMMANDS_AUTO_FCDRCHAINCOMMANDGROUP_H_ */
