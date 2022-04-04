#pragma once
#include "AbstractFile.h"
#include <iostream>
class PasswordProxy : public AbstractFile {
public:
	PasswordProxy(AbstractFile*, std::string);
	~PasswordProxy();

	// interface methods
	std::vector<char> read() override;
	int write(std::vector<char>) override;
	int append(std::vector<char>) override;
	unsigned int getSize() override;
	std::string getName() override;
	void accept(AbstractFileVisitor* afv) override;
	virtual AbstractFile* clone(std::string file_name) override;

protected:
	std::string passwordPrompt();
	int checkPasswordMatch(std::string pwd);

private:
	AbstractFile *aFile_;
	std::string pwd_;

};