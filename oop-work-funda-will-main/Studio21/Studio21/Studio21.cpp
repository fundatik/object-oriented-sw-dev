// Studio21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cassert>
#include "..\..\\SharedCode\CommandPrompt.h"
#include "..\..\\SharedCode\TouchCommand.h"
#include "..\..\\SharedCode\SimpleFileFactory.h"
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include "..\..\\SharedCode\ImageFile.h"
#include "..\..\\SharedCode\TextFile.h"

using namespace std;


int main()
{
	AbstractFileSystem* sfs = new SimpleFileSystem;
	AbstractFileFactory* sff = new SimpleFileFactory;
	TouchCommand* tc = new TouchCommand(sfs, sff);

	CommandPrompt cp;
	cp.setFileSystem(sfs);
	cp.setFileFactory(sff);

	string commandname = "touch";
	assert(cp.addCommand(commandname, tc) ==0);
	int result = cp.run();
	if (result == exit_code::UserQuit) { cout << "User quits" << endl; }
	AbstractFile * file = sfs->openFile("file1.txt");
	if (file == nullptr) {
		cout << "\nCannot open the file" << endl;
	}
	else {
		cout << "\nSuccessfully open the file" << endl;
	}

	return 0;
}

