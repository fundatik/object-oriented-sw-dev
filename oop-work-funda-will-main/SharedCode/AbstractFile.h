#pragma once
// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary
#include "AbstractFileVisitor.h"
#include <iostream>
#include <vector>
#include <string>

enum exit_code { Success, SizeMismatch, UnknownPixel, CopyFailure, NotImplemented, BadAlloc , FileExist, NullFile, UnknownFileExtension, FileIsNotOpen, FileOpen, FileNotExist, PasswordFailure, AddCommandFailure, UserQuit
,AddFileFailure, RemoveCommandFailure, WrongCommand, CopyFileFailure, MacroCommandFailure
};

class AbstractFile {
	public:
		virtual ~AbstractFile() = default;
		// pure virtual functions
		virtual std::vector<char> read() = 0;
		virtual int write(std::vector<char>) = 0;
		virtual int append(std::vector<char>) = 0;
		virtual unsigned int getSize() = 0;
		virtual std::string getName() = 0;
		virtual void accept(AbstractFileVisitor*) = 0;
		virtual AbstractFile* clone (std::string file_name) = 0;
};