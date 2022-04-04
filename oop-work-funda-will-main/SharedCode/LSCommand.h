#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"


class LSCommand : public AbstractCommand {
public:
	LSCommand(AbstractFileSystem*);
	int execute(std::string) override;
	void displayInfo() override;
private:
	AbstractFileSystem* afs_;
};