#include "RemoveCommand.h"

RemoveCommand::RemoveCommand(AbstractFileSystem* afs) :afs_(afs) {
}

int RemoveCommand::execute(std::string input) {
	
	int result = afs_->deleteFile(input);
	if (result != exit_code::Success) {
		return exit_code::RemoveCommandFailure;
	}
	return exit_code::Success;
}

void RemoveCommand::displayInfo() {
	std::cout << "remove deletes a file, remove can be invoked with the command: rm <filename>" << std::endl;
}