#include "TouchCommand.h"
#include "PasswordProxy.h"
#include <sstream>

TouchCommand::TouchCommand(AbstractFileSystem *afs, AbstractFileFactory *aff):afs_(afs),aff_(aff) {
}

int TouchCommand::execute(std::string input) {
	std::size_t found = input.find(' ');
	if (found != std::string::npos) { // multi words
		std::istringstream iss(input);
		std::string name, opt;
		iss >> name >> opt;
		if (opt.compare("-p") != 0) {
			return exit_code::WrongCommand;
		}
		AbstractFile * file = aff_->createFile(name);
		std::string pwd;
		std::cout << "enter a password string: ";
		getline(std::cin, pwd);
		PasswordProxy* proxyFile = new PasswordProxy(file, pwd);
		int result = afs_->addFile(name, proxyFile);
		if (result != exit_code::Success) {
			delete proxyFile;
			return exit_code::AddFileFailure;
		}
	}
	else {
		AbstractFile* file = aff_->createFile(input);
		if (file == nullptr) {
			return exit_code::NullFile;
		}
		int result = afs_->addFile(input, file);
		if (result != exit_code::Success) {
			delete file;
			return exit_code::AddFileFailure;
		}
		
	}
	return exit_code::Success;
	
	
}

void TouchCommand::displayInfo() {
	std::cout << "touch creates a file, touch can be invoked with the command: touch <filename>"<<std::endl;
}