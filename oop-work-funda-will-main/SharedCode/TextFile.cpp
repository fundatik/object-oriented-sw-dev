//  Define the TextFile class here

#include <algorithm>
#include "TextFile.h"

using namespace std;


TextFile::TextFile() : name_("") {}
TextFile::TextFile(std::string name) : name_(name) {}

// get the number of characters in the file
unsigned int TextFile::getSize() {
	return static_cast<unsigned int>(contents_.size());
}

// get the name of the file
std::string TextFile::getName() {
	return name_;
}

// replace the contents of the file with new contents
int TextFile::write(std::vector<char> contents) {

	// overwrite the previous content
	contents_.clear();
	// copy the content
	for (auto e : contents) {
		contents_.push_back(e);
	}

	return exit_code::Success;
}

// add new contents to the end of the contents of the file 
int TextFile::append(std::vector<char> contents) {

	for (auto e : contents) {
		contents_.push_back(e);
	}

	return exit_code::Success;
}

// inserts each of char of the contents of the file to cout
std::vector<char> TextFile::read() {
	return contents_;
}

void TextFile::accept(AbstractFileVisitor* afv) 
{
	afv->visit_TextFile(this);
}

AbstractFile* TextFile::clone(std::string file_name)
{
	TextFile *temp = new TextFile(file_name);
	//temp->write(this->read());
	temp->contents_ = this->contents_;
	return temp;
}