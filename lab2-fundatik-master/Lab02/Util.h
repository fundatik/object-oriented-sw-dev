#pragma once

#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <string>


enum arg_index { IndexOfProgName, IndexOfInputFileName, NumOfArgs };
enum exit_code { Success, IncorrectNumOfArgs, IOFailure, IStringStreamFailure, NoValidPieces, InvalidDimensions, GetLineFailure};

int usage(const std::string&, const std::string&);
void lowercase(std::string &);

#endif