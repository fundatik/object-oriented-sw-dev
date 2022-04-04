/*
 * File: Util.cpp
 * Authors: Funda Atik, Will Wu
 * E-mails: fatik@wustl.edu, willwu@wustl.edu
 * This file defines common functions for each lab
 *
 */


#include "Util.h"


int usage(const std::string& prog_name, const std::string& args) {
	std::cout << "usage: " << prog_name << " " << args;
	return exit_code::IncorrectArguments;
}

void lowercase(std::string& text) {
	for (size_t i = 0; i < text.size(); i++) {
		if (text[i] >= 'A' && text[i] <= 'Z') {
			text[i] = 'a' + (text[i] - 'A');
		}
	}
}
