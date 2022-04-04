/*
 * File: Util.cpp
 * Author: Funda Atik, E-mail: fatik@wustl.edu
 * This file includes common functions for each lab
 *
 */

#include "Util.h"


int usage(const std::string& prog_name, const std::string& args) {
	std::cout << prog_name << " requires 1 argument.\n";
	std::cout << "usage: " << prog_name << args;
	return exit_code::IncorrectNumOfArgs;
}

void lowercase(std::string& text) {
	for (auto i = 0; i < text.size(); i++) {
		if (text[i] >= 'A' && text[i] <= 'Z') {
			text[i] = 'a' + (text[i] - 'A');
		}
	}
}