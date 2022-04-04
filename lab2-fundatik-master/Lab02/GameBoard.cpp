/*
 * File: Game.cpp
 * Author: Funda Atik, E-mail: fatik@wustl.edu
 * This file includes common functions for the game board
 *
 */

#include "Game.h"
#include "Util.h"
#include "GameBoard.h"


 /*
  *	Reads the board game's dimensions where the width is # of cols and the height is # f rows
  *  Returns success or failure
  *	File format
  *		<nr_cols> <nr_rows>
  */
int read_dimensions(std::ifstream& ifs, unsigned int& x, unsigned int& y) {
	std::string line;
	int signed_x, signed_y;
	if (ifs.is_open()) {
		getline(ifs, line);
		if (ifs.fail()) {
			return exit_code::GetLineFailure;
		}
		std::istringstream iss(line);
		if (iss.fail()) {
			return exit_code::IStringStreamFailure;
		}
		// read the game board's width
		iss >> signed_x;
		if (iss.fail() || signed_x < 0) {
			return exit_code::IStringStreamFailure;
		}
		x = static_cast<unsigned int>(signed_x);
		// read the game board's height
		iss >> signed_y;
		if (iss.fail() || signed_y < 0) {
			return exit_code::IStringStreamFailure;
		}
		y = static_cast<unsigned int>(signed_y);

	}
	else {
		std::cout << "Unable to open file\n";
		return exit_code::IOFailure;
	}
	return exit_code::Success;
};

/*
 * Reads game pieces from a file into a vector
 * Returns success or failure
 *	File format for tic-tac-toe.txt
 *		red Xs X 0 0
 *		blue Os O 0 1
 *		...
 *  File format for gumoku.txt
 *		black stone X 0 0
 *		white stone O 5 5
 *		...
 */

int read_pieces(std::ifstream& ifs, std::vector<game_piece>& pieces, unsigned int x, unsigned int y) {
	std::string line;
	bool pieceNotExist = true;
	if (ifs.is_open()) {
		while (getline(ifs, line)) {
			std::istringstream iss(line);
			if (iss.fail()) {
				return exit_code::IStringStreamFailure;
			}

			std::string gp_color, gp_name, gp_display;
			unsigned int gp_x, gp_y;
			int gp_sx, gp_sy; //signed versions

			iss >> gp_color >> gp_name >> gp_display >> gp_sx >> gp_sy;
			if (iss.fail() || gp_sx < 0 || gp_sy < 0 ) {
				continue;//skip bad line
			}
			gp_x = static_cast<unsigned int>(gp_sx);
			gp_y = static_cast<unsigned int>(gp_sy);

			piece_color color = text2color(gp_color);
			if (color == piece_color::InvalidColor || gp_x >= x || gp_y >= y) {
				continue;//skip bad line
			}

			/*
			 * Well-formed line
			 * Calculate the index formula where the lower left corner is [0,0] = v[0]
			 * and the upper right corner is[ width-1,height-1] = v[v.size()-1]
			 * index = width*row+col = width*y + x
			 *
			 **/
			pieceNotExist = false;
			unsigned int index = x * gp_y + gp_x;
			pieces[index].color = color;
			pieces[index].name = gp_name;
			pieces[index].display = gp_display;
		}
		// There is at least one well-formed piece has been read
		if (pieceNotExist) {
			std::cout << "There is not any valid pieces on the game board.\n";
			return exit_code::NoValidPieces;
		}
	}
	else {
		std::cout << "Unable to open file\n";
		return exit_code::IOFailure;
	}
	return exit_code::Success;
}
/*
* Displays the game board where printing out the vertical dimension in descending order
* whereas printing out the horizantal dimension in ascending order
*/
int show_pieces(const std::vector<game_piece>& pieces, unsigned int x, unsigned int y) {
	if (x * y != pieces.size()){
		return exit_code::InvalidDimensions;
	}
	std::stringstream game_ss;
	for (unsigned int i = y; i > 0; --i) {
		for (unsigned int j = 1; j <= x; ++j) {
			unsigned int index = x * (i - 1) + (j - 1);
			game_ss << pieces[index].display;
		}
		game_ss << "\n";
	}
	std::cout << game_ss.str();
	return exit_code::Success;
}

int show_pieces_verbose(const std::vector<game_piece>& pieces, unsigned int x, unsigned int y) {
	if (x * y != pieces.size()) {
		return exit_code::InvalidDimensions;
	}
	std::stringstream game_ss;
	for ( int i = 0; i < y; ++i) {
		for ( int j = 0; j < x; ++j) {
			int index = x * i + j;
			std::stringstream game_ss;
			if (pieces[index].color != piece_color::NoColor) {
				std::cout << j<< "," << i << " " << color2text(pieces[index].color) << " " << pieces[index].name << ": ";
				// bottom: j, i-1
				if (i - 1 >= 0) {
					index = x * (i-1) + j;
					if (pieces[index].color != piece_color::NoColor) {
						game_ss << j << "," << i-1 << " " << color2text(pieces[index].color) << " " << pieces[index].name << "; ";
					}
				}
				// top: j, i+1
				if (i + 1 < y) {
					index = x * (i + 1) + j;
					if (pieces[index].color != piece_color::NoColor) {
						game_ss << j << "," << i+1 << " " << color2text(pieces[index].color) << " " << pieces[index].name << "; ";
					}
				}
				// left: j-1, i
				if (j-1 >= 0) {
					index = x * i + (j-1);
					if (pieces[index].color != piece_color::NoColor) {
						game_ss << j-1 << "," << i << " " << color2text(pieces[index].color) << " " << pieces[index].name << "; ";
					}
				}
				// right: j+1, i
				if (j + 1 < x) {
					index = x * i + (j+1);
					if (pieces[index].color != piece_color::NoColor) {
						game_ss << j+1 << "," << i << " " << color2text(pieces[index].color) << " " << pieces[index].name << "; ";
					}
				}
				// top-left: j-1, i+1
				if (j-1 >= 0 && i + 1 < y) {
					index = x * (i + 1) + (j-1);
					if (pieces[index].color != piece_color::NoColor) {
						game_ss << j-1 << "," << i+1 << " " << color2text(pieces[index].color) << " " << pieces[index].name << "; ";
					}
				}
				// top-right: j+1, i+1
				if (j + 1 < x && i + 1 < y) {
					index = x * (i+1) + (j+1);
					if (pieces[index].color != piece_color::NoColor) {
						game_ss << j+1 << "," << i+1 << " " << color2text(pieces[index].color) << " " << pieces[index].name << "; ";
					}
				}
				// bottom-right: j+1, i-1
				if (j + 1 < x && i-1 >= 0) {
					index = x * (i-1) + (j + 1);
					if (pieces[index].color != piece_color::NoColor) {
						game_ss << j+1 << "," << i-1 << " " << color2text(pieces[index].color) << " " << pieces[index].name << "; ";
					}
				}
				// bottom-left: j-1, i-1
				if (j - 1 >= 0 && i - 1 >= 0) {
					index = x * (i - 1) + (j - 1);
					if (pieces[index].color != piece_color::NoColor) {
						game_ss << j-1 << "," << i-1 << " " << color2text(pieces[index].color) << " " << pieces[index].name << "; ";
					}
				}
				std::cout << game_ss.str() << std::endl;
				//std::cout << std::endl;
			}
		}
	}
	return exit_code::Success;
}



