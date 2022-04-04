/*
 * File: Lab1.h
 * Author: Funda Atik, E-mail: fatik@wustl.edu
 * This file includes Lab 1 definitions for the main program
 *
 */

#pragma once

#ifndef LAB1_H
#define LAB1_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctype.h>

enum arg_indices { IndexOfProgName=0, IndexOfInputFileName=1, NumOfArgs=2 };
enum exit_codes { Success, IncorrectNumOfArgs, IOFailure };

int readFile(std::vector<std::string>& words, const char* filename);
int usage(const std::string&);

#endif