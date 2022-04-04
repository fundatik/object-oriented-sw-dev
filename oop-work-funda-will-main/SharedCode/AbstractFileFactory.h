#pragma once
// studio 18 - file factory interface declared here

#include <iostream>
#include "AbstractFile.h"

class AbstractFileFactory {
public:
	virtual AbstractFile *createFile(std::string name)=0;
};