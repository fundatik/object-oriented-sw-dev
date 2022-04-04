// Studio20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cassert>  
#include <string>
#include "..\..\\SharedCode\ImageFile.h"
#include "..\..\\SharedCode\TextFile.h"
#include "..\..\\SharedCode\PasswordProxy.h"
#include "..\..\\SharedCode\BasicDisplayVisitor.h"
#include "..\..\\SharedCode\MetadataDisplayVisitor.h"
using namespace std;

int main()
{
	string name = "file.txt";
	AbstractFile* txt = new TextFile(name);


	string pwd = "studio20";
	PasswordProxy * password = new PasswordProxy(txt, pwd);

	vector<char> contents = { 'a','l','l' };
	txt->write(contents);
	cout << "Before Password Protected Write" << endl;

	AbstractFileVisitor* bdv = new BasicDisplayVisitor;
	txt->accept(bdv);

	contents[0] = 'b';
	password->write(contents);
	password->accept(bdv);

	return 0;
}

