#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "AbstractFile.h"
#include "GrepCommand.h"
#include "SearchVisitor.h"
using namespace std;

GrepCommand::GrepCommand(AbstractFileSystem* afs) : afs_(afs) {}

int GrepCommand::execute(std::string keyword) 
{
	SearchVisitor* sv = new SearchVisitor(keyword);
	AbstractFile* file;
	std::set<std::string> names = afs_->getFileNames();
	for (auto const& name : names) 
	{
		file = afs_->openFile(name);
		file->accept(sv);
		afs_->closeFile(file);
	}
	return exit_code::Success;

}
void GrepCommand::displayInfo()
{
	cout << "grep searches all text files for a string. grep can be invoked with the command: grep <keyword> " << endl;
}
