#pragma once
// Image file class declaration here


#include "AbstractFile.h"

class ImageFile : public AbstractFile {
public:
	// Constructor
	ImageFile(std::string name);

	// interface methods
	std::vector<char> read() override;
	int write(std::vector<char>) override;
	int append(std::vector<char>) override;
	unsigned int getSize() override;
	std::string getName() override;
	void accept(AbstractFileVisitor* afv) override;
	AbstractFile* clone(std::string file_name) override;

	unsigned int index(int, int) const;

private:
	std::vector<char> contents_;
	std::string name_;
	char chSize_;
};