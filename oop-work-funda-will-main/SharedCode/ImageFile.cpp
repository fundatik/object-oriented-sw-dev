// definition of ImageFile class here

#include "ImageFile.h"
#include <sstream>
#include <vector>



ImageFile::ImageFile(std::string name) : name_(name), chSize_(0) {}

// return the number of characters in the file
unsigned int ImageFile::getSize() {
    return static_cast<unsigned int>(contents_.size());
}

std::string ImageFile::getName() {
    return name_;
}

// replace the contents of the file with new contents
int ImageFile::write(std::vector<char> contents) {
    
    contents_.clear();
    if (contents.size() == 0) {
        chSize_ = '0';
        return exit_code::SizeMismatch;
    }
    chSize_ = contents[contents.size() - 1]; // get image size which is stored in the last index

    int iSize = chSize_ - '0';
    // check if the image size matches the size of contents
    
    if (iSize * iSize != static_cast<int>(contents.size() - 1) ) {
        chSize_ = '0';
        return exit_code::SizeMismatch;
    }
   


    const char PixelX = 'X';
    const char PixelSpace = ' ';
    for (auto it = contents.begin(); it != contents.end() - 1; ++it) {
        if (*it == PixelX || *it == PixelSpace) {
            contents_.push_back(*it);
        }
        else {
            chSize_ = '0';
            contents_.clear();
            return exit_code::UnknownPixel;
        }
    }

    return exit_code::Success;
}

// not supported 
int ImageFile::append(std::vector<char> contents) {
    return exit_code::NotImplemented;
}

std::vector<char> ImageFile::read() {
    return contents_;
}

unsigned int ImageFile::index(int x, int y) const {
    return x + static_cast<unsigned int>(chSize_ - '0') * y;
}

void ImageFile::accept(AbstractFileVisitor* afv)
{
    afv->visit_ImageFile(this);
}

AbstractFile* ImageFile::clone(std::string file_name)
{

    ImageFile* temp = new ImageFile(file_name);
    //temp->write(this->read());
    temp->contents_ = this->contents_;
    temp->chSize_ = this->chSize_;
    return temp;
}