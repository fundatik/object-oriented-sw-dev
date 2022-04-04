#include "GameBase.h"
#include "Util.h"
#include "TicTacToeGame.h"
#include "GomokuGame.h"

GameBase* GameBase::checkArgs(int argc, char* argv[]) {

	// the number of arguments should be 2 for TicTacToeGame; 2, 3, or 4 for GomokuGame
	if (argc > IndexOfGameType && argc <= NumOfArgs) {
		std::string gameType = "";
		gameType = argv[IndexOfGameType];
		// the second argument should be either TicTacToeGame or GomokuGame
		if (argc == IndexOfGameType + 1) {
			if (gameType.compare("TicTacToeGame") == 0) {
				return new TicTacToeGame;
			}
			if (gameType.compare("GomokuGame") == 0) {
				return new GomokuGame;
			}
		}
		else if (gameType.compare("GomokuGame") == 0) {		// only Gomokugame has more than 2 arguments
			// 3rd argument defines Gomoku NxN game board dimension 
			if (argc == IndexOfGomokuDims + 1) {			
				int dimX = atoi(argv[IndexOfGomokuDims]);
				if (dimX > 0) {
					return new GomokuGame(dimX);
				}
			}
			else {	// 4th argument is the number of consecutive pieces needed to win the game										
				int dimX = atoi(argv[IndexOfGomokuDims]);
				int pieces2Win = atoi(argv[IndexOfGomokuRows]);
				if (dimX > 0 && pieces2Win > 0) {
					return new GomokuGame(dimX, pieces2Win);
				}
			}
		}
	}
	// unsuccessful
	GameBase* game = 0;
	return game;
}

// Constructor that sets the game board according to given dimensions
GameBase::GameBase(unsigned int X, unsigned int Y, game_player fPlayer, game_player sPlayer, unsigned int pieces2Win) : dimX_(X), dimY_(Y), firstPlayer_(fPlayer), secondPlayer_(sPlayer), pieces2Win_(pieces2Win) {
	// check if dimensions are in expected bound, if not set them to the default bounds after warning the player
	if (dimX_ < constants::DefaultMinDimX || dimY_ < constants::DefaultMinDimX || dimX_ > constants::DefaultMaxDimX || dimY_ > constants::DefaultMaxDimY) {														// Check if dimensions are in valid bounds
		std::cout << "Dimensions should be equal or larger than " << constants::DefaultMinDimX - 2 << " and less than " << constants::DefaultMaxDimX - 2 << ". ";
		std::cout << "Minimum dimensions (" << constants::DefaultMinDimX - 2 << "x" << constants::DefaultMinDimX - 2 << ") are set." << std::endl;
		dimX_ = constants::DefaultMinDimX;
		dimY_ = constants::DefaultMinDimX;
	}
	for (unsigned int i = 0; i < dimY_; ++i) {
		for (unsigned int j = 0; j < dimX_; ++j) {
			// initially all cells of the game board are empty
			game_piece piece;
			gameBoard_.push_back(piece);
		}
	}
	// update longest dipslay string length
	game_piece piece;
	updateMaxDisplayLength(piece.disp_);
	updateMaxDisplayLength(std::to_string(dimY_));
	updateMaxDisplayLength(std::to_string(dimX_));
}

// Get comma-seperated coordinates from the user 
int GameBase::prompt(unsigned int& x, unsigned int& y) {
	std::string answer;
	bool isValid = true;
	do {
		std::cout << "Enter a comma-seperated coordinates in [1:" << dimX_ - 2 << ",1:" << dimY_ - 2 << "] or type \'quit\'. Column first, then row" << std::endl;
		std::cin >> answer;
		isValid = get_coordinates(answer, x, y);
		if (isValid) {																		// comma-seperated coordinates
			isValid = (x >= 1 && x <= dimX_ - 2 && y >= 1 && y <= dimY_ - 2);
			if (isValid == false) {															// check if coordinates is in valid bounds
				std::cout << "Careful, you entered out of bound. Try again!" << std::endl;
			}
			else if (gameBoard_[index(x, y)].code_ != piece_code::EMPTY) {					// check if the place is empty
				isValid = false;
				std::cout << "Sorry, the place is not empty. Try again!" << std::endl;
			}
		}
		else {
			if (answer.compare("quit") != 0) {
				std::cout << "You entered wrong format. Try again!" << std::endl;
			}
		}
	} while (answer.compare("quit") != 0 && isValid == false);

	// Player quits the game without making a valid move
	if (isValid == false) {																	
		return exit_code::EarlyQuit;
	}
	return exit_code::Success;
}

// play the game in turns until someone wins or draws or quits
int GameBase::play() {
	print();
	int hasNextTurn;
	bool isDone = false;
	bool isDraw = false;
	// main game logic
	do {

		hasNextTurn = turn();
		if (hasNextTurn == exit_code::Success) {
			isDone = done();
		}
		if (!isDone) {
			isDraw = draw();
		}
	} while (!isDone && !isDraw && hasNextTurn == exit_code::Success);

	if (isDone) {
		std::cout << "Won! " << getLastPlayer().name_ << " is the winner! " << countMovesSoFar() << " turns have been played." << std::endl;
		return exit_code::Success;
	}

	if (isDraw) {
		std::cout << "Draw! " << countMovesSoFar() << " turns have been played. No winning moves remained." << std::endl;
		return exit_code::DrawNoWinner;
	}

	// Someone should want to quit the game. Game over! 
	std::cout << getCurrentPlayer().name_ << " quits! " << countMovesSoFar() << " turns have been played. " << std::endl;
	return exit_code::EarlyQuit;
}


// helper functions

// returns the player who has the current turn
game_player GameBase::getCurrentPlayer() {
	if (countMovesSoFar() % 2 == 0) {
		return firstPlayer_;
	}
	else {
		return secondPlayer_;
	}
}

// returns the player who has the last turn
game_player GameBase::getLastPlayer() {
	if (countMovesSoFar() % 2 == 1) {
		return firstPlayer_;
	}
	else {
		return secondPlayer_;
	}
}

// returns true if it successfully gets comma-seperated coordinates, otherwise returns false
bool GameBase::get_coordinates(std::string line, unsigned int& x, unsigned int& y) {

	int index_comma = line.find(","); //return indexOf the first occurance
	if (index_comma == std::string::npos) {
		// not found
		return false;
	}
	line.replace(line.begin() + index_comma, line.begin() + index_comma + 1, " "); // replace it with space
	std::istringstream iss(line);
	if (iss.fail()) {
		return false;
	}
	int sx, sy;
	iss >> sx >> sy;						// read signed integers
	if (iss.fail() || sx < 0 || sy < 0) {
		return false;
	}
	x = static_cast<unsigned int>(sx);
	y = static_cast<unsigned int>(sy);

	return true;
}

unsigned int GameBase::index(int x, int y) const {
	return x + dimX_ * y;
}

void GameBase::updateMaxDisplayLength(std::string nDisp) {
	if (nDisp.length() > maxDisplayLength_) {
		maxDisplayLength_ = nDisp.length();
	}
}
const unsigned int GameBase::getMaxValidMoves() {
	return (dimX_ - 2) * (dimY_ - 2);
};

const unsigned int GameBase::countMovesSoFar() {
	return movesSoFar_.size();
}

// common functions for arithmetic with unsigned integers
unsigned int GameBase::getMax(unsigned int x, unsigned int y) {
	int signedX = static_cast<int>(x);
	int signedY = static_cast<int>(y);
	if (x > y) {
		return x;
	}
	else {
		return y;
	}
}
unsigned int GameBase::getMin(unsigned int x, unsigned int y) {
	int signedX = static_cast<int>(x);
	int signedY = static_cast<int>(y);
	if (x < y) {
		return x;
	}
	else {
		return y;
	}
}

unsigned int GameBase::getSub(unsigned int x, unsigned int y) {
	int signedX = static_cast<int>(x);
	int signedY = static_cast<int>(y);
	int res = signedX - signedY;
	if (res < 0) {
		return 0;
	}
	else {
		return static_cast<unsigned int>(res);
	}
}


// check if there is any line in vertical, horizantal, diagonal directions
bool GameBase::checkUpperDiagonal(unsigned int x, unsigned y, piece_code lastPieceCode, std::vector<game_piece> board) {
	// Second Diagonal direction : check if there are pieces in a row existing in a diagonal line
	// start from upper left, decrement y, increment x
	for (unsigned int i = getMin(getSub(dimY_, 2), y + pieces2Win_); i >= getMax(getSub(y, pieces2Win_), pieces2Win_); --i) {
		for (unsigned int j = getMax(1, getSub(x, pieces2Win_)); j < getMin(x + pieces2Win_ + 1, getSub(dimX_, pieces2Win_)); ++j) {

			bool lastPlayerWon = true;
			for (unsigned int k = 0; k < pieces2Win_; ++k) {						// Check if there are pieces in a row
				if (board[index(j + k, i - k)].code_ != lastPieceCode) {
					lastPlayerWon = false;
					break;
				}
			}
			if (lastPlayerWon) {
				return true;
			}
		}
	}
	return false;
}
bool GameBase::checkBottomDiagonal(unsigned int x, unsigned y, piece_code lastPieceCode, std::vector<game_piece> board) {
	// First diagonal direction: check if there are pieces in a row existing in a diagonal line
	// start from bottom left, increment both x and y
	for (unsigned int i = getMax(1, getSub(y, pieces2Win_)); i < getMin(y + pieces2Win_ + 1, getSub(dimY_, pieces2Win_)); ++i) {
		for (unsigned int j = getMax(1, getSub(x, pieces2Win_)); j < getMin(x + pieces2Win_ + 1, getSub(dimX_, pieces2Win_)); ++j) {
			bool lastPlayerWon = true;
			for (unsigned int k = 0; k < pieces2Win_; ++k) {						// Check if there are pieces in a row
				if (board[index(j + k, i + k)].code_ != lastPieceCode) {
					lastPlayerWon = false;
					break;
				}
			}
			if (lastPlayerWon) {
				return true;
			}
		}
	}
	return false;
}
bool GameBase::checkVertical(unsigned int x, unsigned y, piece_code lastPieceCode, std::vector<game_piece> board) {
	// check if there are pieces in a row existing in a vertical line 
	for (unsigned int i = getMax(1, getSub(y, pieces2Win_)); i < getMin(y + pieces2Win_ + 1, getSub(dimY_, pieces2Win_)); ++i) {
		for (unsigned int j = getMax(1, getSub(x, pieces2Win_)); j < getMin(x + pieces2Win_ + 1, dimX_); ++j) {
			bool lastPlayerWon = true;
			for (unsigned int k = 0; k < pieces2Win_; ++k) {						// Check if there are pieces in a row
				if (board[index(j, i + k)].code_ != lastPieceCode) {
					lastPlayerWon = false;
					break;
				}
			}
			if (lastPlayerWon) {
				return true;
			}
		}
	}
	return false;
}
bool GameBase::checkHorizontal(unsigned int x, unsigned y, piece_code lastPieceCode, std::vector<game_piece> board) {
	// check if there are pieces in a row existing in a horizantal line 
	for (unsigned int i = getMax(1, getSub(y, pieces2Win_)); i < getMin(y + pieces2Win_ + 1, dimY_); ++i) {										// rows
		for (unsigned int j = getMax(1, getSub(x, pieces2Win_)); j < getMin(x + pieces2Win_ + 1, getSub(dimX_, pieces2Win_)); ++j) {					// columns
			bool isWon = true;
			// Check if there are pieces in a row
			for (unsigned int k = 0; k < pieces2Win_; ++k) {
				if (board[index(j + k, i)].code_ != lastPieceCode) {
					isWon = false;
					break;
				}
			}
			if (isWon) {
				return true;
			}
		}
	}
	return false;
}