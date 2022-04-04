#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"


class CopyCommand : public AbstractCommand {
public:
	CopyCommand(AbstractFileSystem*);
	int execute(std::string) override;
	void displayInfo() override;
private:
	AbstractFileSystem* afs_;
};