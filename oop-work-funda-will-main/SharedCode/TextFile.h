#pragma once
// TextFile declaration goes here
#include "AbstractFile.h"

class TextFile : public AbstractFile {
public:
	// Constructor
	TextFile();
	TextFile(std::string name);

	// interface methods
	std::vector<char> read() override;
	int write(std::vector<char>) override;
	int append(std::vector<char>) override;
	unsigned int getSize() override;
	std::string getName() override;
	void accept(AbstractFileVisitor* afv) override;
	AbstractFile* clone(std::string file_name) override;


private:
	std::vector<char> contents_;
	std::string name_;
};