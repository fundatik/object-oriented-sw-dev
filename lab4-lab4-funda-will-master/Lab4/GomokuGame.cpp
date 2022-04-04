/*
 * File: GomokuGame.h
 * Authors: Funda Atik, Will Wu
 * E-mails: fatik@wustl.edu, willwu@wustl.edu
 * GomokuGame game is 2 player where each player try to get five stones in a row, diagonal and column.
 * This file defines overrides the base class operations based on the requirements of Gomoku game
 */

#include "GomokuGame.h"
#include "Util.h"
#include <algorithm>    // std::max

GomokuGame::GomokuGame() : GameBase(constants::DefaultGomokuDim, constants::DefaultGomokuDim, game_player(game_type::TypeGomoku, player_type::TypeFirstPlayer), game_player(game_type::TypeGomoku, player_type::TypeSecondPlayer), constants::DefaultGomokuPieces2Win) {}

// constructor parameters: given x dimension
GomokuGame::GomokuGame(unsigned int X) : GameBase(X + 2, X + 2, game_player(game_type::TypeGomoku, player_type::TypeFirstPlayer), game_player(game_type::TypeGomoku, player_type::TypeSecondPlayer), constants::DefaultGomokuPieces2Win) {
	// Check if dimensions are in valid bounds, if not set default values
	if (pieces2Win_ < constants::MinGomokuPieces2Win || pieces2Win_ > dimX_ - 2) {
		std::cout << "The number of connecting pieces should be >=  " << constants::MinGomokuPieces2Win;
		std::cout << " and shouldn't be larger than dimensions (" << dimX_ - 2 << "x" << dimX_ - 2 << "). \n";
		std::cout << "The number of pieces to win is set to " << constants::MinGomokuPieces2Win << std::endl;
		pieces2Win_ = constants::MinGomokuPieces2Win;
	}
}

// constructor parameters: given x dimension, the number of adjacent pieces to win the game
GomokuGame::GomokuGame(unsigned int X, int pieces2Win) : GameBase(X + 2, X + 2, game_player(game_type::TypeGomoku, player_type::TypeFirstPlayer), game_player(game_type::TypeGomoku, player_type::TypeSecondPlayer), pieces2Win) {
	// Check if dimensions are in valid bounds, if not set default values
	if (pieces2Win_ < constants::MinGomokuPieces2Win || pieces2Win_ > dimX_ - 2) {
		std::cout << "The number of connecting pieces should be >=  " << constants::MinGomokuPieces2Win;
		std::cout << " and shouldn't be larger than dimensions (" << dimX_ - 2 << "x" << dimX_ - 2 << "). ";
		std::cout << "The number of pieces to win is set to " << constants::MinGomokuPieces2Win << std::endl;
		pieces2Win_ = constants::MinGomokuPieces2Win;
	}
}

// overload the insertion operator for displaying the game board
std::ostream& operator<< (std::ostream& ost, const GomokuGame& game)
{
	// The game board's (0,0) coordinates are at the bottom left corner
	// Print also row and column indices, the dimension of game board is DIM_Y x DIM_X
	// the dimension of area that a user can put a game piece is (DIM_Y-2) x (DIM_X-2)
	// "padding" determines the how many game pieces are skipped when displaying the game board
	// Also, adjust the widths of the squares to keep columns aligned

	std::string disp;
	const unsigned int padding = constants::BoardPadding;
	const unsigned int startIndex = constants::BoardStartIndex;
	ost << "\n";
	for (unsigned int i = game.dimY_ - padding; i >= startIndex + padding; --i) { // row indices
		for (unsigned int j = startIndex + padding; j <= game.dimX_ - padding; ++j) { // column indices
			if (j == 1 + padding) {
				disp = std::to_string(i - 1);
				// adjust the width of each column display by adding spaces at the end
				ost << (i - 1) << std::setw(static_cast<__int64>(game.maxDisplayLength_ - disp.length()) + 1) << constants::Delim_;										// print row index
			}
			// get the display of th piece on this location
			disp = game.gameBoard_[game.index(j - 1, i - 1)].disp_;
			// print game piece by adjusting its colummn width by adding spaces at the end
			ost << disp << std::setw(static_cast<__int64>(game.maxDisplayLength_ - disp.length()) + 1) << constants::Delim_;
		}
		ost << "\n"; // Print new line after each row
	}

	// show column indices, starting from the bottom left corner, and goes right
	disp = 'X'; //adjust the initial spaces before printing column indices
	ost << disp << std::setw(static_cast<__int64>(game.maxDisplayLength_ - disp.length()) + 1) << constants::Delim_;
	for (unsigned int j = padding; j < game.dimX_ - padding; ++j) {
		disp = std::to_string(j);
		// print game piece by adjusting its colummn width
		ost << j << std::setw(static_cast<__int64>(game.maxDisplayLength_ - disp.length()) + 1) << constants::Delim_;													// print column index 
	}
	ost << "\n";

	return ost;
}

// print the game board by using the insertion operartor
void GomokuGame::print() {
	std::cout << *this;
}


// It returns true there is a winner vertical, horizontal or diagonal line, otherwise returns false
// it checks all possible lines based on the coordinates of the last piece that has been played
bool GomokuGame::done() {
	piece_code lastPieceCode = getLastPlayer().piece_.code_;
	// get coordinates of the last piece that has been played
	unsigned int x = movesSoFar_.back().first;
	unsigned int y = movesSoFar_.back().second;

	return checkHorizontal(x, y, lastPieceCode, gameBoard_) || checkVertical(x, y, lastPieceCode, gameBoard_) || checkUpperDiagonal(x, y, lastPieceCode, gameBoard_) || checkBottomDiagonal(x, y, lastPieceCode, gameBoard_);

}

// It is draw if it no valid moves remains
bool GomokuGame::draw()
{
	if ( countMovesSoFar() == getMaxValidMoves()) {
		return true;
	}
		bool isDraw = false;
		// make two copies, one fill empty with black, the other with white
		std::vector<game_piece> boardCopy1;
		std::vector<game_piece> boardCopy2;
		boardCopy1 = gameBoard_;
		boardCopy2 = gameBoard_;

		// fill two board with one colored pieces
		for (unsigned int i = 1; i < dimY_ - 1; ++i)
		{
			for (unsigned int j = 1; j < dimX_ - 1; ++j)
			{
				if (gameBoard_[index(j, i)].code_ == piece_code::EMPTY)
				{
					boardCopy1[index(j, i)].setGamePiece(firstPlayer_.piece_.code_); // set that piece to 1
					boardCopy2[index(j, i)].setGamePiece(secondPlayer_.piece_.code_); // set that piece to 2
				}
			}
		}

		// check if any player can still win
		for (unsigned int i = 1; i < dimY_ - 1; ++i)
		{
			for (unsigned int j = 1; j < dimX_ - 1; ++j)
			{
				isDraw = !(checkHorizontal(j, i, firstPlayer_.piece_.code_, boardCopy1) || checkVertical(j, i, firstPlayer_.piece_.code_, boardCopy1) || checkUpperDiagonal(j, i, firstPlayer_.piece_.code_, boardCopy1) || checkBottomDiagonal(j, i, firstPlayer_.piece_.code_, boardCopy1)) && !(checkHorizontal(j, i, secondPlayer_.piece_.code_, boardCopy2) || checkVertical(j, i, secondPlayer_.piece_.code_, boardCopy2) || checkUpperDiagonal(j, i, secondPlayer_.piece_.code_, boardCopy2) || checkBottomDiagonal(j, i, secondPlayer_.piece_.code_, boardCopy2));
				if (!isDraw) {
					return false;
				}
			}
		}

	return true;

}

// remember whose turn it is: even moveSoFar indicates that the turn is B's, whereas odd evenSoFar W's 
// Black stone always goes first.
int GomokuGame::turn() {
	unsigned int x, y;
	int res;

	game_player currentPlayer = getCurrentPlayer();
	std::cout << "\n$ Turn #  " << countMovesSoFar() + 1 << ", " << currentPlayer.piece_.name_ << "'s turn..." << std::endl;

	res = prompt(x, y);								// Get coordinates of a valid move
	if (res != exit_code::Success) {				// Player quits the game without making a valid move
		return exit_code::EarlyQuit;				// Someone wants to quit, no valid move
	}

	// Update game status 
	movesSoFar_.push_back(std::make_pair(x, y));	// Store valid move
	gameBoard_[index(x, y)] = currentPlayer.piece_;	// Place the piece on the game board
	updateMaxDisplayLength(currentPlayer.piece_.disp_);

	print();										// Print game board
	std::cout << "\nPlayer " << currentPlayer.piece_.name_ << " : ";// Print username

	// Print which moves are played so far by a player who has the current turn;
	// even indices for the 1st player, odd indices for 2nd player 
	for (unsigned int i = (countMovesSoFar() - 1) % 2; i < countMovesSoFar(); i = i + 2) {
		std::cout << movesSoFar_[i].first << ", " << movesSoFar_[i].second << "; ";
	}
	std::cout << std::endl;

	return exit_code::Success;
}
