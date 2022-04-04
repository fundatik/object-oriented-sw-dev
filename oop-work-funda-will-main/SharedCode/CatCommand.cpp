#include "CatCommand.h"
#include "PasswordProxy.h"
#include "MetadataDisplayVisitor.h"
#include "BasicDisplayVisitor.h"
#include <sstream>

CatCommand::CatCommand(AbstractFileSystem* afs) :afs_(afs) {
}

int CatCommand::execute(std::string input) {
	AbstractFile* file;
	bool append = false;
	if (input.find(' ') != std::string::npos) { // multi words
		std::istringstream iss(input);
		std::string name, opt;
		iss >> name >> opt;
		if (opt.compare("-a") != 0) { // check if the correct option is given
			return exit_code::WrongCommand;
		}

		file = afs_->openFile(name);
		if (file == nullptr) {
			return exit_code::NullFile;
		}
		AbstractFileVisitor* dv = new BasicDisplayVisitor;
		file->accept(dv); 
		afs_->closeFile(file);
		std::cout << "enter data to append to the existing file. Enter :wq to save the file and exist. Enter :q to exit without saving\n";
		append = true;
	}
	else {
		file = afs_->openFile(input);
		if (file == nullptr) {
			return exit_code::NullFile;
		}
		afs_->closeFile(file);
		std::cout << "enter data to write to the file. Enter :wq to save the file and exist. Enter :q to exit without saving\n";
	}

	std::string line;
	std::string lines;
	bool saveAndExit = true;
	while (1) {
		getline(std::cin, line);
		if (line.compare(":wq") == 0) {
			break;
		}
		else if (line.compare(":q") == 0) {
			saveAndExit = false;
			break;
		}
		lines = lines + line + '\n';
	};

	lines.erase(lines.find_last_not_of("\n") + 1); // rtrim
	if (saveAndExit) {
		std::vector<char> contents;
		for (char ch : lines) {
			contents.push_back(ch);
		}
		if (append) {
			return file->append(contents);	
		}
		return file->write(contents);
	}
	return exit_code::Success;
}

void CatCommand::displayInfo() {
	std::cout << "cat writes data to a file, cat can be invoked with the command: cat <filename> [-a]" << std::endl;
}