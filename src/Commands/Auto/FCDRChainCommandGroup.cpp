/*
 * FCDRChainCommandGroup.cpp
 *
 *  Created on: Mar 10, 2018
 *      Author: jcopi
 */

#include <Commands/Auto/FCDRChainCommandGroup.h>
#include <COmmands/Auto/DeadReckoningCommand.h>

FCDRChainCommandGroup::FCDRChainCommandGroup(std::string chain) : frc::CommandGroup("FCDRChain")
{
	/*for (std::vector<FCDRObj>::size_type i = 0; i != chain.size(); i++)
	{
		if (chain[i].waitForCompletion)
		{
			AddSequential(chain[i].cmd);
		}

		else {
			AddParallel(chain[i].cmd);
		}
	}*/

	std::vector<std::string> lines = split(chain, "\n");
	for (unsigned i = 0; i < lines.size(); i++)
	{
		std::vector<std::string> words = split(lines[i], " \t");
		if (words.size() < 2)
			continue;
		for (unsigned j = 0; j < words.size(); j++)
		{
			std::vector<double> args;
			for (unsigned i = 2; i < (4 + 2); i++) {
				args.push_back(strtod(words[i].c_str(), NULL));
			}

			if (words[1] == "DeadReckoning") {
				if (words.size() == (4 + 2)) {  // Check if there are enough parameters for the command being called. (number of arguments + 2)
					if (words[0] == "parallel") {
						AddParallel(new DeadReckoningCommand(args[0], args[1], args[2], args[3]));
					} else {
						AddSequential(new DeadReckoningCommand(args[0], args[1], args[2], args[3]));
					}
				}
			}

			else if (words[1] == "TwoWheelDrive") {
				if (words.size() == (3 + 2)) {  // Check if there are enough parameters for the command being called. (number of arguments + 2)
					if (words[0] == "parallel") {
						AddParallel(new DeadReckoningCommand(args[0], args[1], args[2]));
					} else {
						AddSequential(new DeadReckoningCommand(args[0], args[1], args[2]));
					}
				}
			}
		}
	}
}

std::vector<std::string> split (std::string str, std::string delims)
{
	std::vector<std::string> result;
	bool inDelim = false;
	unsigned start = 0;

	for (unsigned i = 0; i < str.length(); i++) {
		if (inDelim) {
			// The last character was a delimiter
			if (str.find(delims, i) != std::string::npos) {
				// This character is not a delimiter.
				start = i;
			}
		} else if (str.find(delims, i) == std::string::npos || i == str.length() - 1) {
			// The last character was not a delim and this one is
			result.push_back(str.substr(start, i - start));
			// The next substring can't start at the curretn delimiter
			start = i + 1;
		}
	}

	return result;
}
