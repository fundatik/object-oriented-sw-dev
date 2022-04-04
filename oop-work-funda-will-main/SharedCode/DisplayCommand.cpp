#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "DisplayCommand.h"
#include "BasicDisplayVisitor.h"
#include <ostream>
#include <sstream>
#include <vector>

using namespace::std;

DisplayCommand::DisplayCommand(AbstractFileSystem* afs) : afs_(afs) {}

int DisplayCommand::execute(std::string command)
{
	std::size_t found = command.find(' ');
	if (found != std::string::npos) { // multi words, <filename> <option>
		std::istringstream iss(command);
		std::string name, opt;
		iss >> name >> opt;
		if (opt.compare("-d") != 0) {
			return exit_code::WrongCommand;
		}
		else
		{

			AbstractFile* file = afs_->openFile(name);
			if (file == nullptr) {
				return exit_code::NullFile;
			}


			vector<char> contents = file->read();
			for (auto e : contents)
			{
				cout << e ;
			}
			cout << endl;
			afs_->closeFile(file);

		}
	}
	else {
		AbstractFileVisitor* bdv = new BasicDisplayVisitor;
		AbstractFile* file = afs_->openFile(command);
		if (file == nullptr) {
			return exit_code::NullFile;
		}
		file->accept(bdv);
		afs_->closeFile(file);
	}
	return exit_code::Success;
}

void DisplayCommand::displayInfo()
{
	cout << "ds displays a file's content, ds can be invoked with the command: ds <filename> [-d]. Specify \"-d\" to display unformated file." << endl;
}

