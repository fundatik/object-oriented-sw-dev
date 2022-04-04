// Studio19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cassert>  
#include <string>
#include "..\..\\SharedCode\ImageFile.h"
#include "..\..\\SharedCode\TextFile.h"
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include "..\..\\SharedCode\BasicDisplayVisitor.h"
#include "..\..\\SharedCode\MetadataDisplayVisitor.h"

using namespace std;
int main()
{
	{
		// Part II
		string name1 = "file1.img";
		AbstractFile* file1 = new ImageFile(name1);
		vector<char> contents1 = { ' ','X',' ', 'X','2' };

		file1->write(contents1);
		vector<char> c1 = file1->read();
		cout << "Image content" << endl;
		for (auto& ch : c1) {
			cout << ch;
		}
		cout << endl;

		contents1[0] = 'X';
		file1->write(contents1);
		c1 = file1->read();
		cout << "Image content after modification" << endl;
		for (auto ch : c1) {
			cout << ch;
		}
		cout << endl;

		string name2 = "file2.txt";
		AbstractFile* file2 = new TextFile(name2);
		vector<char> contents2 = { 'f','u','n' };
		file2->write(contents2);
		vector<char> c2 = file2->read();
		cout << "text content" << endl;
		for (auto& ch : c2) {
			cout << ch;
		}
		cout << endl;

		contents2.push_back('w');
		contents2.push_back('i');
		contents2.push_back('l');
		contents2.push_back('l');
		file2->write(contents2);
		c2 = file2->read();
		cout << "text content after modification" << endl;
		for (auto& ch : c2) {
			cout << ch;
		}
		cout << endl;
	}

	{
		// Part IV
		string name1 = "file1.img";
		ImageFile img1(name1);
		vector<char> contents1 = { 'X','X','X','X','2' };
		int result = img1.write(contents1);
		assert(result == 0);
		vector<char> c1 = img1.read();
		cout << "test: print image 1's content \n";
		for (auto& ch : c1) {
			cout << ch;
		}
		cout << endl;

		string name2 = "file2.txt";
		TextFile txt1(name2);
		vector<char> contents2 = { 'm','o','o','n','l','i','g','h','t' };
		result = txt1.write(contents2);
		assert(result == 0);
		vector<char> c2 = txt1.read();
		cout << "test: print text 1's content \n";
		for (auto& ch : c2) {
			cout << ch;
		}
		cout << endl;

		AbstractFileVisitor* bdv = new BasicDisplayVisitor;
		cout << "test: BasicDisplayVisitor for image" << endl;
		img1.accept(bdv);
		cout << "test: BasicDisplayVisitor for text" << endl;
		txt1.accept(bdv);

		AbstractFileVisitor* mdv = new MetadataDisplayVisitor;
		cout << "test: MetadataDisplayVisitor for image" << endl;
		img1.accept(mdv);
		cout << "test: MetadataDisplayVisitor for text" << endl;
		txt1.accept(mdv);

	}


	return 0;
}
