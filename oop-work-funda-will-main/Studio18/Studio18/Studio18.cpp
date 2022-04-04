// Studio18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cassert>
#include "..\..\\SharedCode\AbstractFileSystem.h"
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include "..\..\\SharedCode\AbstractFileFactory.h"
#include "..\..\\SharedCode\SimpleFileFactory.h"
#include "..\..\\SharedCode\ImageFile.h"
#include "..\..\\SharedCode\TextFile.h"
  
using namespace std;

int main()
{
	AbstractFileSystem *fs = new SimpleFileSystem;
	AbstractFileFactory *ff = new SimpleFileFactory;

	string name1 = "file1.img";
	cout << "test: create an image" << endl;
	AbstractFile* img1 = ff->createFile(name1);
	std::vector<char> contents1 = { ' ','X',' ', 'X','2' };
	cout << "test: write a content to an image" << endl;
	img1->write(contents1);
	cout << "test: read from an image" << endl;
	img1->read();
	
	string name2 = "file2.txt";
	cout << "test: create an text" << endl;
	AbstractFile* txt1 = ff->createFile(name2);
	std::vector<char> contents3 = { 'X','O' };
	std::vector<char> contents4 = { ' ','s','u','n','d','a','y',' ','f','u','n','d','a','y' };
	cout << "test: write a content to a text" << endl;
	txt1->write(contents3);
	cout << "test: append a text" << endl;
	txt1->append(contents4);
	cout << "test: read from a text" << endl;
	txt1->read();
	
	
	fs->addFile(img1->getName(), img1);
	fs->addFile(txt1->getName(), txt1);

	cout << "test: open an image" << endl;
	AbstractFile *opImg1 = fs->openFile(img1->getName());
	assert(opImg1 != nullptr);
	cout << "test: open a text" << endl;
	AbstractFile* optxt1 = fs->openFile(txt1->getName());
	assert(optxt1 != nullptr);
	cout << "test: open a text that is already open" << endl;
	AbstractFile* optxt2 = fs->openFile(txt1->getName());
	assert(optxt2 == nullptr);
	

	return 0;
}
