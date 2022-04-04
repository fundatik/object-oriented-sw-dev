#include "SearchVisitor.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

SearchVisitor::SearchVisitor() : keyword_("") {};
SearchVisitor::SearchVisitor(string input) : keyword_(input) {};


void SearchVisitor::visit_TextFile(TextFile* txtfile) 
{
	if (txtfile)
	{
		if (keyword_.compare("") == 0)
		{
			//end program if file the keyword is empty
			cout << "No keyword provided" << endl;
			return;
		}
		else
		{
			//prints the filename if the keyword is found
			vector<char> content = txtfile->read();
			string content_str(content.begin(), content.end());
			string file_name = txtfile->getName();
			auto index = content_str.find( keyword_);
			if (index != string::npos)
			{
				cout << file_name << endl;
			}
			
		}
	}
	else 
	{
		cout << "File Unreadable" << endl;
	}
}

void SearchVisitor::visit_ImageFile(ImageFile* imgFile) 
{
	//does nothing 
	return;
}