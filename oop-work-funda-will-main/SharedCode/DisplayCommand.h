#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class DisplayCommand : public AbstractCommand {
public:
	DisplayCommand(AbstractFileSystem*);
	int execute(std::string) override;
	void displayInfo() override;
private:
	AbstractFileSystem* afs_;
};