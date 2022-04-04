/*
 * File: Lab1.cpp
 * Author: Funda Atik, E-mail: fatik@wustl.edu
 * This file includes Lab 1 definitions for the main program
 *
 */

#include "Lab1.h"

int main(int argc, char *argv[])
{
	
	if (argc != NumOfArgs) {
		return usage(argv[IndexOfProgName]);
	}

	std::vector<std::string> words;
	int res = readFile(words, argv[IndexOfInputFileName]);
	if (res != Success) {
		return res;
	}
	
	std::vector<int> numbers;
	for (size_t i = 0; i < words.size(); ++i) {
		std::string word = words[i];
		// Find strings that contains only digit numeric digit characters
		bool isNumeric = true;
		for (size_t j = 0; j < word.size(); ++j) {
			unsigned char ch = word[j];
			if (!isdigit(ch)) {
				isNumeric = false;
				break;
			}
		}
		
		// Convert string word containing only numeric chracters into an integer
		if (isNumeric) {
			std::istringstream iss(word);
			int number;
			iss >> number;
			// Check if a logical error on I/O operation occurs
			if (iss.fail()) {
				// A very large number so keep it as string since string can be of any length
				iss.clear();
				std::string dummy;
				iss >> dummy;
				std::cout << word << std::endl;
				continue;
				//std::cout << "String to integer conversion error\n";
				//return StrToIntConversionFailure;
			}
			numbers.push_back(number);
		}
		else {
			std::cout << word << std::endl;
		}
	
		
	}
	// Display integers
	for (size_t i = 0; i < numbers.size(); ++i) {
		std::cout << numbers[i] << std::endl;
	}
	return Success;
}

int readFile(std::vector<std::string>& words, const char* filename) {
	
	// Open file
	std::ifstream ifs(filename);
	if (ifs.is_open()) {
		std::string line, word;

		while (getline(ifs, line)) {
			std::istringstream iss(line);
			while (iss >> word) {
				words.push_back(word);
			}
		}
		ifs.close();
	}
	else {
		std::cout << "Unable to open file\n";
		std::cout << "Filename you entered: " << filename << std::endl;
		return IOFailure;
	}
	
	return Success;
}

int usage(const std::string& prog_name) {
	std::cout << prog_name << " requires 1 argument.\n";
	std::cout << "usage: " << prog_name << " <input_file_name>\n";
	return IncorrectNumOfArgs;
}
