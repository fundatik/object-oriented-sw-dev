#pragma once
// declaration of the interface all file systems provide goes here

#include "AbstractFile.h"
#include <iostream>
#include <set>

class AbstractFileSystem {
public:
	//methods
	virtual int addFile(std::string , AbstractFile * )=0;
	virtual int deleteFile(std::string filename)=0;
	virtual AbstractFile* openFile(std::string filename)=0;
	virtual int closeFile( AbstractFile* aFile)=0;
	virtual std::set<std::string>getFileNames()=0;
};
