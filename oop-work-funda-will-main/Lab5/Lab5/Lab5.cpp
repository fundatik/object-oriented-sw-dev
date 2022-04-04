// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <vector>
#include <cassert>
#include "..\..\\SharedCode\CommandPrompt.h"
#include "..\..\\SharedCode\TouchCommand.h"
#include "..\..\\SharedCode\LSCommand.h"
#include "..\..\\SharedCode\CatCommand.h"
#include "..\..\\SharedCode\RemoveCommand.h"
#include "..\..\\SharedCode\MacroCommand.h"
#include "..\..\\SharedCode\DisplayCommand.h"
#include "..\..\\SharedCode\CopyCommand.h"
#include "..\..\\SharedCode\SimpleFileFactory.h"
#include "..\..\\SharedCode\RenameParsingStrategy.h"
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include "..\..\\SharedCode\ImageFile.h"
#include "..\..\\SharedCode\TextFile.h"
#include "..\..\\SharedCode\BasicDisplayVisitor.h"
#include "..\..\\SharedCode\GrepCommand.h"

using namespace std;
int main()
{
		AbstractFileSystem* sfs = new SimpleFileSystem;
		AbstractFileFactory* sff = new SimpleFileFactory;
		TouchCommand* tc = new TouchCommand(sfs, sff);
		LSCommand* lsc = new LSCommand(sfs);
		CatCommand* cc = new CatCommand(sfs);
		DisplayCommand* dsc = new DisplayCommand(sfs);
		CopyCommand* cpc = new CopyCommand(sfs);
		RemoveCommand* rmc = new RemoveCommand(sfs);
		GrepCommand* gpc = new GrepCommand(sfs);

		CommandPrompt cp;
		cp.setFileSystem(sfs);
		cp.setFileFactory(sff);

		string lsCommand = "ls";
		string touchCommand = "touch";
		string catCommand = "cat";
		string dsCommand = "ds";
		string cpCommand = "cp";
		string rmCommand = "rm";
		string rnCommand = "rn";
		string grepCommand = "grep";
		assert(cp.addCommand(lsCommand, lsc) == 0);
		assert(cp.addCommand(touchCommand, tc) == 0);
		assert(cp.addCommand(catCommand, cc) == 0);
		assert(cp.addCommand(dsCommand, dsc) == 0);
		assert(cp.addCommand(cpCommand, cpc) == 0);
		assert(cp.addCommand(rmCommand, rmc) == 0);
		assert(cp.addCommand(grepCommand, gpc) == 0);

		// create a macro command with rename parsing strategy
		MacroCommand* mc = new MacroCommand(sfs);
		AbstractParsingStrategy* aps = new RenameParsingStrategy;
		mc->setParseStrategy(aps);
		mc->addCommand(cpc);
		mc->addCommand(rmc);
		cp.addCommand(rnCommand, mc);

		string name = "x.img";
		sfs->addFile(name, sff->createFile(name));
		AbstractFile* f = sfs->openFile(name);
		vector<char> v = { 'X',' ','X',' ','X',' ','X', 'X','X','3' };
		f->write(v);
		sfs->closeFile(f);
		
		cp.run();


		//delete sfs, sff, tc, lsc, cc, dsc, cpc, rmc, gpc;
	
	return 0;
}


