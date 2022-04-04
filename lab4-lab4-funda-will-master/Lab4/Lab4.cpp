/*
 * File: Lab4.cpp
 * Authors: Funda Atik, Will Wu
 * E-mails: fatik@wustl.edu, willwu@wustl.edu
 * This file includes main function for testing.
 *
 */

#include "Util.h"
#include "GameBase.h"
#include "TicTacToeGame.h"

#include <memory>
#include <iostream>

int main(int argc, char* argv[])
{

	try {
		std::shared_ptr<GameBase> game{ GameBase::checkArgs(argc, argv) };
		if (game == 0) {
			return usage(argv[IndexOfProgName], "\"TicTacToeGame\"|\"GomokuGame <nDims> <Pieces2Win>\"");
		}
		int res = game->play();
		return res;

	}
	catch (std::bad_alloc& ba) {
		std::cout << "Error: bad_alloc caught: " << ba.what() << std::endl;
		return exit_code::BadAlloc;
	}

}

