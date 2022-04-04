/*
 * File: Lab3.cpp
 * Author: Funda Atik, E-mail: fatik@wustl.edu
 * This file includes main function for testing.
 *
 */

#include "Util.h"
#include "TicTacToeGame.h"

#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
	std::string gameType = "";
	if (argc == NumOfArgs) {
		gameType = argv[IndexOfGameType];
	}
	if( argc != NumOfArgs || gameType.compare("TicTacToeGame") != 0){
		return usage(argv[IndexOfProgName], "TicTacToeGame");
	}
	
	TicTacToeGame game;
	int res = game.play();

	return res;
}


