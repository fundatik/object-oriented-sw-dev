// studio 18 - simple file factory definitions

#include "SimpleFileFactory.h"
#include "TextFile.h"
#include "ImageFile.h"

AbstractFile* SimpleFileFactory::createFile(std::string filename) {
	
	// determine the file extension where filename.txt is TextFile and filename.img is ImageFile
	const std::string FileExtentionTXT = "txt";
	const std::string FileExtentionIMG = "img";
	size_t foundDot = filename.find_last_of('.');

	if (filename.find(FileExtentionTXT, foundDot + 1) != std::string::npos) {
		return new TextFile(filename);
	}
	else if (filename.find(FileExtentionIMG, foundDot + 1) != std::string::npos) {
		return new ImageFile(filename);
	}

	return nullptr;
}