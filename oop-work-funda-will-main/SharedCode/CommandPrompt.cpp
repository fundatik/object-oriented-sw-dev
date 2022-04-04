#include "CommandPrompt.h"
#include <sstream>

CommandPrompt::CommandPrompt() :afs_(nullptr), aff_(nullptr) {};

void CommandPrompt::setFileSystem(AbstractFileSystem* afs) {
	afs_ = afs;
}

void CommandPrompt::setFileFactory(AbstractFileFactory* aff) {
	aff_ = aff;
}

int  CommandPrompt::addCommand(std::string str, AbstractCommand* ob) {
	auto result = commands_.insert({ str, ob });
	if (result.second) {
		return 0;
	}
	return exit_code::AddCommandFailure;
}

void CommandPrompt::listCommands() {
	for (auto i = commands_.begin(); i != commands_.end(); i++) {
		std::cout << i->first << std::endl;
	}
}

std::string CommandPrompt::prompt() {
	std::string input;
	std::string defaultPrompt = "Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.\n$   ";
	std::cout << defaultPrompt;
	std::getline(std::cin, input);
	return input;
}

int CommandPrompt::run() {
	while (1) {
		std::string input = prompt();
		if (input.compare("q") == 0) {
			return exit_code::UserQuit;
		}
		else if (input.compare("help") == 0) {
			listCommands();
		}
		else {
			std::size_t found = input.find(' ');
			if (found == std::string::npos) { // single word command
				auto it = commands_.find(input);
				if (it == commands_.end()) { 
					std::cout << "The command did not exist.\n";
				}
				else {
					// execute the command with an empty string
					int result = it->second->execute("");
					if (result != 0) {
						std::cout << "The command failed.\n";
					}
				}
				
			}
			else { // multi words
				std::istringstream iss(input);
				std::string first, second;
				iss >> first >> second;
				if (first.compare("help") == 0) {
					
					auto it = commands_.find(second);
					if (it == commands_.end()) {
						std::cout << "The command did not exist.\n";
					}
					else {
						it->second->displayInfo();
					}
				}
				else {
					// search for the command name
					auto it = commands_.find(first); 
					if (it == commands_.end()) {
						std::cout << "The command did not exist.\n";
					}
					else {
						// call the command with the remainder text
						int result = it->second->execute(input.substr(input.find(" ") + 1));
						if (result != 0) {
							std::cout << "The command failed.\n";
						}
					}
				}
			}
		}
	}
}