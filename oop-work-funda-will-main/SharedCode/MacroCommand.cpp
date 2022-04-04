#include "MacroCommand.h"
#include "AbstractFile.h"

MacroCommand::MacroCommand(AbstractFileSystem* afs) :afs_(afs) {
}

int MacroCommand::execute(std::string input) {
	std::vector<std::string>  inputs = strategy_->parse(input);
	int index = 0;
	for (auto const& cm : commands_) {
		int result = cm->execute(inputs[index]);
		if (result != 0) {
			return exit_code::MacroCommandFailure;
		}
		++index;
	}
	return exit_code::Success;
}

void MacroCommand::displayInfo() {
	std::cout << "macro commands construct commands out of other commands, a macro command can be invoked with the command: <command> <inputs>" << std::endl;
}


void MacroCommand::addCommand(AbstractCommand* command) {
	commands_.push_back(command);
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* strategy) {
	strategy_ = strategy;
}
