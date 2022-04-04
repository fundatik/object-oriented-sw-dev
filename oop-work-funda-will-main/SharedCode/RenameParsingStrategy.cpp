#include "RenameParsingStrategy.h"
#include <sstream>

std::vector<std::string> RenameParsingStrategy::parse(std::string input) {
	
	std::istringstream iss(input);
	std::string name, newNameNoExt;
	iss >> name >> newNameNoExt;

	std::vector<std::string> inputs;
	inputs.push_back(input);
	inputs.push_back(name);
	return inputs;

}