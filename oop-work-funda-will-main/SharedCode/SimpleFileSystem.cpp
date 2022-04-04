// define methods of SimpleFileSystem class here

#include "SimpleFileSystem.h"


int SimpleFileSystem::addFile(std::string filename, AbstractFile* aFile){
	// check if the file does not already exist	
	if (allFiles_.find(filename) != allFiles_.end()){
		return exit_code::FileExist;
	}
	
	// check if the file is allocated
	if (aFile == nullptr){
		return exit_code::NullFile;
	}

	// insert the pair contaning the file name and the pointer to the file 
	allFiles_.insert(std::pair<std::string, AbstractFile*>(filename, aFile));

	return exit_code::Success;
}

AbstractFile* SimpleFileSystem::openFile(std::string filename) {
	// find the pointer to the file according to given filename
	auto it = allFiles_.find(filename);
	// check if the file already exist
	if (it != allFiles_.end()) {
		// check if it is not open
		if (openFiles_.find(it->second) == openFiles_.end()) {
			// add the file to the set of open files
			openFiles_.insert(it->second);
			// return a pointer to the file
			return it->second;
		}
	}
	return nullptr;
}

int SimpleFileSystem::closeFile(AbstractFile* aFile) {
	// check if it is currently open
	if (openFiles_.find(aFile) != openFiles_.end()) {
		// remove it from the set of open files
		openFiles_.erase(aFile);
		return exit_code::Success;
	}

	return exit_code::FileIsNotOpen;
}

int SimpleFileSystem::deleteFile(std::string filename) {
	// find the pointer to the file according to given filename
	auto it = allFiles_.find(filename);
	// the file should exist
	if (it == allFiles_.end()) {
		return exit_code::FileNotExist;
	}

	// the file shouldn't be open
	if (openFiles_.find(it->second) != openFiles_.end()) {
		return exit_code::FileOpen;
	}

	delete it->second;
	allFiles_.erase(it);

	return exit_code::Success;
}

std::set<std::string> SimpleFileSystem::getFileNames() {
	std::set<std::string> names;
	for (auto const& e : allFiles_){
		names.insert(e.first);
	}
	return names;
}
