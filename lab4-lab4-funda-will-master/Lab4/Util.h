 /*
  * File: Util.h
  * Authors: Funda Atik, Will Wu
  * E-mails: fatik@wustl.edu, willwu@wustl.edu
  * This file includes declarations of common functions for each lab
  */

#pragma once

#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <string>
#include <sstream>

enum arg_index { IndexOfProgName, IndexOfGameType, IndexOfGomokuDims, IndexOfGomokuRows, NumOfArgs };
enum exit_code { Success, IncorrectArguments, IOFailure, EarlyQuit, DrawNoWinner, NotImplemented, BadAlloc };

// prints the usage of the program
int usage(const std::string&, const std::string&);	
// convert a given string to a lowercase string
void lowercase(std::string&);						
#endif