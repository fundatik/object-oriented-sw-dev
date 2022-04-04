/*
 * File: Util.h
 * Author: Funda Atik, E-mail: fatik@wustl.edu
 * This file includes declarations of common functions for each lab
 *
 */

#pragma once

#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <string>
#include <sstream>


enum arg_index { IndexOfProgName, IndexOfGameType, NumOfArgs };
enum exit_code { Success, IncorrectArguments, IOFailure, EarlyQuit, DrawNoWinner};

int usage(const std::string&, const std::string&);	// prints the usage of the program
void lowercase(std::string&);						// convert a given string to a lowercase string
#endif