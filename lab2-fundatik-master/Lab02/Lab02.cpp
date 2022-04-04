/*
 * File: Lab02.cpp
 * Author: Funda Atik, E-mail: fatik@wustl.edu
 * This file includes main function for testing.
 *
 */

#include "Util.h" 
#include "Game.h"
#include "GameBoard.h"
#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
	if (argc != NumOfArgs) {
		return usage(argv[IndexOfProgName], " <input file>\n");
	}

	std::ifstream in_file(argv[1]);
	if (in_file.is_open()) {
		unsigned int colX = 0, rowY = 0;
		int ret;
		do {
			ret = read_dimensions(in_file, colX, rowY);
		} while (ret == IStringStreamFailure);
		if (ret != Success) {
			std::cout << "An error occured when reading dimensions\n";
			return ret;
		}
		std::vector<game_piece> pieces;
		for (unsigned int i = 0; i < colX * rowY; i++) {
			game_piece gp;
			gp.color = piece_color::NoColor;
			gp.name = "";
			gp.display = " ";
			pieces.push_back(gp);
		}

		ret = read_pieces(in_file, pieces, colX, rowY);
		if (ret != Success) {
			std::cout << "An error occured when reading pieces\n";
			return ret;
		}
		in_file.close();


		show_pieces(pieces, colX, rowY);

		std::cout << "show neighbors" << std::endl;
		show_pieces_verbose(pieces, colX, rowY);

	}
	else {
		std::cout << "Unable to open file\n";
		return IOFailure;
	}

	return exit_code::Success;
}
