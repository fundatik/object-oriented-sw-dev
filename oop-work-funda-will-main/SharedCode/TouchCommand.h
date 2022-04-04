#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class TouchCommand: public AbstractCommand {
public:
	TouchCommand(AbstractFileSystem*, AbstractFileFactory*);
	int execute(std::string) override;
	void displayInfo() override;
private:
	AbstractFileSystem* afs_;
	AbstractFileFactory* aff_;
};