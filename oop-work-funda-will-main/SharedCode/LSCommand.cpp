#include "LSCommand.h"
#include "MetadataDisplayVisitor.h"

#include <iostream>
#include <string>
#include <iomanip> // setw

LSCommand::LSCommand(AbstractFileSystem* afs) :afs_(afs) {
}

int LSCommand::execute(std::string input) {
	
	std::set<std::string> names = afs_->getFileNames();
	if (input.compare("-m") == 0) {
		AbstractFileVisitor* mdv = new MetadataDisplayVisitor;
		for (auto const& name : names) {
			AbstractFile* file = afs_->openFile(name);
			file->accept(mdv);
			afs_->closeFile(file);
		}
	}
	else {
		bool even = true;
		const int MaxFileSize = 20;
		for (auto const& name : names) {
			if (even) {
				std::cout << name << std::setw(static_cast<__int64>(MaxFileSize - name.length()) + 1) << " ";
				even = false;
			}
			else {
				std::cout << name << std::setw(static_cast<__int64>(MaxFileSize - name.length()) + 1)  << " " << std::endl;
				even = true;
			}
		}
		if (!even) {
			std::cout<<std::endl;
		}
	}
	
	return exit_code::Success;
}

void LSCommand::displayInfo() {
	std::cout << "ls displays the names of all files currently in the file system, ls can be invoked with the command: \"ls\" or \"ls -m\" (display also the file's metadata)" << std::endl;
}