/*
 * File: constants.h
 * Authors: Funda Atik, Will Wu
 * E-mails: fatik@wustl.edu, willwu@wustl.edu
 * This file includes common constants 
 *
 */

#pragma once
#include <string>

namespace constants {
	const unsigned int DefaultGomokuDim = 21;
	const unsigned int 	DefaultGomokuPieces2Win = 5;

	const unsigned int 	MinGomokuPieces2Win = 3;
	const unsigned int 	BoardPadding = 1;
	const unsigned int 	BoardStartIndex = 1;

	const unsigned int 	DefaultTicTacToeDimX = 5;
	const unsigned int 	DefaultTicTacToeDimY = 5;
	const unsigned int 	DefaultTicTacToePieces2Win = 3;

	const std::string DefaultFirstPlayerName = "The 1st Player";
	const std::string DefaultSecondPlayerName = "The 2nd Player";
	const unsigned int DefaultMinDimX = 5, MinDimY_ = 5;
	const unsigned int DefaultMaxDimX = 30, DefaultMaxDimY = 30;
	const std::string Delim_ = " ";
}