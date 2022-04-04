#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "CopyCommand.h"
#include "BasicDisplayVisitor.h"
#include "AbstractFileFactory.h"
#include <ostream>
#include <sstream>
#include <vector>

using namespace std;

CopyCommand::CopyCommand(AbstractFileSystem* afs) : afs_(afs){}

int CopyCommand::execute(string command)
{
	size_t found = command.find(' ');
	if (found != std::string::npos) { // multi words, <filename> <filename_to_copy>
		std::istringstream iss(command);
		std::string name, new_file_name;
		iss >> name >> new_file_name;
		
		std::string new_name = new_file_name + name.substr(name.find_last_of("."));
		AbstractFile* file = afs_->openFile(name);
		afs_->closeFile(file);
		if (file == nullptr) {
			return exit_code::NullFile;
		}
		else
		{
			AbstractFile* copied = file->clone(new_name);
			int result = afs_->addFile(new_name, copied);
			if (result != exit_code::Success) {
				delete copied;
				return exit_code::AddFileFailure;
			}
			return exit_code::Success;
		}
	}
	else
	{
		cout << "not enought arguments" << endl;
		return exit_code::WrongCommand;
	}
}

void CopyCommand::displayInfo()
{
	cout << "cp copies a file's content into another file. cp can be invoked with the command: cp <filename> <output File name>" << endl;
}