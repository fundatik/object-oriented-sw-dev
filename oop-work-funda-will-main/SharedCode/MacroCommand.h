#pragma once
#include "AbstractFileSystem.h"
#include "AbstractCommand.h"
#include "AbstractParsingStrategy.h"
#include <vector>

class MacroCommand : public AbstractCommand{
public:
	MacroCommand(AbstractFileSystem*);
	virtual int execute(std::string) override;
	virtual void displayInfo() override;

	void addCommand(AbstractCommand *);
	void setParseStrategy(AbstractParsingStrategy*);
private:
	std::vector<AbstractCommand*> commands_;
	AbstractParsingStrategy *strategy_;
	AbstractFileSystem* afs_;
};
