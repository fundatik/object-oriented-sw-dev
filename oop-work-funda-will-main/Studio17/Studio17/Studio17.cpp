// Studio17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cassert>  
#include "..\..\\SharedCode\ImageFile.h"
#include "..\..\\SharedCode\TextFile.h"
#include "..\..\\SharedCode\SimpleFileSystem.h"

using namespace std;


int main()
{
	/*
	// part 2: test the functionality of the ImageFile class
	string name = "file.img";
	ImageFile img(name);
	std::vector<char> contents = { 'X',' ','X', ' ','2' };
	img.write(contents);
	img.read();

	// test1: check if the member filename matches the given filename
	assert(img.getName().compare(name) == 0);
	// test2: check if the size of the contents is less than one the given contents, where the last index keeps the file size
	assert(img.getSize() == contents.size()-1);
	// test3: check if storing the correct size of the contents
	assert((contents[contents.size() - 1] - '0')* (contents[contents.size() - 1] - '0') == img.getSize());
	
	// test4: size mismatch occurs
	string name2 = "file2.img";
	ImageFile img2(name);
	std::vector<char> contents2 = { 'X',' ','X', ' ','1' };
	int result = img2.write(contents2);
	assert(result == exit_code::SizeMismatch);
	assert(img2.getSize() == 0);

	// test5: unknown pixel in the contents
	string name3 = "file3.img";
	ImageFile img3(name3);
	std::vector<char> contents3 = { 'S',' ','X', ' ','2' };
	result = img3.write(contents3);
	assert(result == exit_code::UnknownPixel);
	assert(img3.getSize() == 0);

	// test6: calling not supported method
	string name4 = "file4.img";
	ImageFile img4(name4);
	std::vector<char> contents4 = { 'S',' ','X', ' ','2' };
	result = img4.append(contents4);
	assert(result == exit_code::NotImplemented);

	*/

	// part 4
	string name1 = "file1.img";
	ImageFile *img1 = new ImageFile(name1);
	std::vector<char> contents1 = { ' ','X',' ', 'X','2' };
	AbstractFile* file1 = img1;
	file1->write(contents1);
	file1->read();

	string name2 = "file2.img";
	ImageFile *img2 = new ImageFile(name2);
	std::vector<char> contents2 = { 'X','X','X', 'X','2' };
	AbstractFile* file2 = img2;
	file2->write(contents2);
	file2->read();

	string name3 = "file3.txt";
	TextFile *txt1 = new TextFile(name3);
	std::vector<char> contents3 = { 'X','O' };
	AbstractFile* file3 = txt1;
	file3->write(contents3);
	file3->read();

	SimpleFileSystem fs;
	
	int result = fs.addFile(file1->getName(), nullptr);
	std::cout << "test adding null file\n";
	assert(result == exit_code::NullFile);

	fs.addFile(file1->getName(), file1);
	result = fs.addFile(file1->getName(), file1);
	std::cout << "test adding existing file\n";
	assert(result == exit_code::FileExist);
	result = fs.addFile(file2->getName(), file2);
	std::cout << "test adding file\n";
	assert(result == exit_code::Success);
	fs.addFile(file3->getName(), file3);

	fs.createFile("file4.img");
	fs.createFile("file5.txt");
	fs.createFile("file6.txt");
	result = fs.createFile("xfile.pdf");
	std::cout << "test creating file with unknown filename extension\n";
	assert(result == exit_code::UnknownFileExtension);
	


	AbstractFile* ofile = fs.openFile(file1->getName());
	assert(ofile->getName() == file1->getName());
	std::cout << "test opening a file\n";
	ofile = fs.openFile(file1->getName());
	std::cout << "test opening the file that is already opened\n";
	assert(ofile == nullptr);
	ofile = fs.openFile("photo.pdf");
	std::cout << "test opening null file\n";
	assert(ofile == nullptr);
	

	result = fs.deleteFile("file3.txt");
	std::cout << "test deleting a file\n";
	assert(result == exit_code::Success);
	result = fs.deleteFile(file1->getName());
	std::cout << "test deleting an open file\n";
	assert(result == exit_code::FileOpen);

	result = fs.closeFile(file2);
	std::cout << "test closing a close file\n";
	assert(result == exit_code::FileIsNotOpen);
	result = fs.closeFile(file1);
	std::cout << "test closing an open file\n";
	assert(result == exit_code::Success);
	
	
	return 0;
}

