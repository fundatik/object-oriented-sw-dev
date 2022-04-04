// Studio16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\\SharedCode\TextFile.h"

#include <iostream>

#include <cassert>  

using namespace std;

int main()
{
	// part 4
	string fileName = "tfile1";
	TextFile txt1(fileName);
	std::vector<char> contents = { 'f','u','n', 'w', 'u' };
	
	cout << "Write to the 1st file\n";
	txt1.write(contents);

	cout << "Read from the 1st file\n";
	txt1.read();

	assert(txt1.getName().compare(fileName) == 0);
	assert(txt1.getSize() == contents.size());

	// part 5
	TextFile txt2;
	AbstractFile* file = &txt2;

	cout << "Write to the 2nd file\n";
	file->write(contents);

	cout << "Read from the 2nd file\n";
	file->read();

	return 0;
}


