#pragma once
// declaration of SimpleFileSystem class goes here

#include "AbstractFileSystem.h"
#include <string>
#include <map>
#include <set>

class SimpleFileSystem : public AbstractFileSystem {
public:

	int addFile(std::string filename, AbstractFile* aFile) override;
	int deleteFile(std::string filename) override;
	AbstractFile* openFile(std::string filename) override;
	int closeFile(AbstractFile* aFile) override;
	std::set<std::string>getFileNames() override;

private:
	
	std::map<std::string, AbstractFile *> allFiles_;
	std::set<AbstractFile*> openFiles_;
};