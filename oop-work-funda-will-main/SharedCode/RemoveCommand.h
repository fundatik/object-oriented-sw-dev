#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class RemoveCommand : public AbstractCommand {
public:
	RemoveCommand(AbstractFileSystem*);
	int execute(std::string) override;
	void displayInfo() override;
private:
	AbstractFileSystem* afs_;
};