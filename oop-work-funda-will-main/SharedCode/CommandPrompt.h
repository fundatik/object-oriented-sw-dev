#pragma once
// define an invoker in the command pattern
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

#include <map>
#include <sstream>
#include <iostream>

class CommandPrompt {
public:
	CommandPrompt();
	void setFileSystem(AbstractFileSystem* afs);
	void setFileFactory(AbstractFileFactory *aff);
	int addCommand(std::string, AbstractCommand*);
	int run();
protected:
	void listCommands();
	std::string prompt();
private:
	std::map<std::string, AbstractCommand*> commands_;
	AbstractFileSystem * afs_;
	AbstractFileFactory * aff_;
};