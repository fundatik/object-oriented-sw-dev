/*
 * File: TicTacToeGame.h
 * Author: Funda Atik, E-mail: fatik@wustl.edu
 * This file includes various implementattions which are necessarry for playing a TicTacToeGame
 * 
 */

#include "TicTacToeGame.h"
#include "Util.h"

#include <sstream>


// Default constructor
TicTacToeGame::TicTacToeGame() : DIM_X_(5), DIM_Y_(5) {
	// 
	for (unsigned int i = 0; i < DIM_Y_; ++i) {
		for (unsigned int j = 0; j < DIM_X_; ++j) {
			game_piece piece;
			gameBoard_.push_back(piece);										// initially all cells of the game board are empty
		}
	}
}
// another constructor
TicTacToeGame::TicTacToeGame(unsigned int X, unsigned int Y) : DIM_X_(X), DIM_Y_(Y) {

	if (X < 5 || Y < 5) {														// Check if dimensions are in valid bounds
		std::cout << "Dimensions should be equal or larger than 5. Default dimensions (5x5) are set." << std::endl;
		DIM_X_ = 5;
		DIM_Y_ = 5;
	}
	for (unsigned int i = 0; i < DIM_Y_; ++i) {
		for (unsigned int j = 0; j < DIM_X_; ++j) {
			game_piece piece;
			gameBoard_.push_back(piece);										// initially all cells of the game board are empty
		}
	}
}

// method 1: prints out current game board
std::ostream& operator<< (std::ostream& ost, const TicTacToeGame& game)
{
	std::stringstream game_ss;															// Game content which is initially empty
	game_ss << "\n";																	// Place a new line before printing each game
	/*
	 * Print the game board by starting upper left corner (DIM_Y,DIM_X), go right and bottom
	 * the game board's (0,0) coordinates are at the bottom left corner
	 * Print also row and column indices, the dimension of game board is DIM_Y x DIM_X
	 * the dimension of area that a user can put a game piece is (DIM_Y-2) x (DIM_X), only inner cells are valid
	 */
	for (unsigned int i = game.DIM_Y_; i > 0; --i) {
		for (unsigned int j = 1; j <= game.DIM_X_; ++j) {
			if (j == 1) {
				game_ss << (i - 1) << game.DELIM_;										// print row index
			}
			game_ss << game.gameBoard_[game.index(i - 1, j - 1)].disp_ << game.DELIM_;	// print game piece
		}
		game_ss << "\n";																// Print new line after each row
	}
	// print column indices, starting from bottom left corner, go right
	game_ss << game.DELIM_ << game.DELIM_;
	for (unsigned int j = 0; j < game.DIM_X_; ++j) {
		game_ss << j << game.DELIM_;													// print column index 
	}
	game_ss << "\n";
	std::cout << game_ss.str();															// print tthe final game board that are stored in stream object

	return ost;
}

// method 2: Check if there is a winner. It returns true 3-Xs or Os are a vertical, horizontal or diagonal line, otherwise returns false
bool TicTacToeGame::done() { 
	const int line_size = 3;
	bool is_line_Xs = true, is_line_Os = true;
																				// check if 3-Xs exist in a vertical line 
	for (unsigned int i = 1; i < DIM_Y_; ++i) {									// rows
		for (unsigned int j = 1; j < DIM_X_ - line_size; ++j) {					// columns
			is_line_Xs = true; 
			is_line_Os = true;
			for (unsigned int k = 0; k < line_size; ++k) {						// Check if there are 3Xs or 3Os
				if (gameBoard_[index(i, j+k)].code_ != piece_code::X) {
					is_line_Xs = false;
				}
				if(gameBoard_[index(i, j+k)].code_ != piece_code::O) {
					is_line_Os = false;
				}
			}
			if(is_line_Xs || is_line_Os){
				return true;
			}
		}		
	}
	// check if 3-Xs exist in a horizontal line 
	for (unsigned int i = 1; i < DIM_Y_ - line_size; ++i) {
		for (unsigned int j = 1; j < DIM_X_ ; ++j) {
			is_line_Xs = true;
			is_line_Os = true;
			for (unsigned int k = 0; k < line_size; ++k) {						// Check if there are 3Xs or 3Os
				if (gameBoard_[index(i+k, j)].code_ != piece_code::X) {
					is_line_Xs = false;
				}
				if (gameBoard_[index(i+k, j)].code_ != piece_code::O) {
					is_line_Os = false;
				}
			}
			if (is_line_Xs || is_line_Os) {
				return true;
			}
		}
	}
	/* There are two diagonals which are orthogonal to each other 
	 * One that starts from the bottom-left corner to the upper-right corner
	 * Other one that starts from the uppe-left corner to the bottom right corner
	 */
	// First diagonal direction: check if 3-Xs exist in a diagonal line , start from bottom left, increment both x and y
	for (unsigned int i = 1; i < DIM_Y_ - line_size ; ++i) {
		for (unsigned int j = 1; j < DIM_X_ - line_size; ++j) {
			is_line_Xs = true;
			is_line_Os = true;
			for (unsigned int k = 0; k < line_size; ++k) {						// Check if there are 3Xs or 3Os
				if (gameBoard_[index(i+k, j+k)].code_ != piece_code::X) {
					is_line_Xs = false;
				}
				if (gameBoard_[index(i+k, j+k)].code_ != piece_code::O) {
					is_line_Os = false;
				}
			}
			if (is_line_Xs || is_line_Os) {
				return true;
			}
		}
	}

	// Second Diagonal direction: check if 3-Xs exist in a diagonal line,  start from upper left, decrement y, increment x
	for (unsigned int i = DIM_Y_ - 2; i >= line_size; --i) {
		for (unsigned int j = 1; j < DIM_X_ - line_size; ++j) {
			is_line_Xs = true;
			is_line_Os = true;
			for (unsigned int k = 0; k < line_size; ++k) {						// Check if there are 3Xs or 3Os
				if (gameBoard_[index(i - k, j + k)].code_ != piece_code::X) {
					is_line_Xs = false;
				}
				if (gameBoard_[index(i - k, j + k)].code_ != piece_code::O) {
					is_line_Os = false;
				}
			}
			if (is_line_Xs || is_line_Os) {
				return true;
			}
		}
	}
	return false;
}

// Method 3: Check if it is a draw. It return false if empty spaces exist or if done() return true, otherwise return true
bool TicTacToeGame::draw() {
	std::cout << "is it draw? # moves: " <<movesSoFar_.size() << ", max: " << getMaxMoves() << std::endl;
	if (done() || movesSoFar_.size() < getMaxMoves()) {
		return false;
	}

	return true; 
}

// Helper method for method 4: return true if it successfully gets comma-seperated coordinates, otherwise returns false
bool TicTacToeGame::get_coordinates(std::string line, unsigned int& x, unsigned int& y) {

	int index_comma = line.find(",");
	if (index_comma == std::string::npos) {
		// not found
		return false;
	}
	line.replace(line.begin() + index_comma, line.begin() + index_comma + 1, " ");
	std::istringstream iss(line);			// wrap string in istringstream
	if (iss.fail()) {
		return false;
	}
	int sx, sy;								//signed versions
	iss >> sx >> sy;						// read signed integers
	if (iss.fail() || sx < 0 || sy < 0) {
		return false;
	}
	x = static_cast<unsigned int>(sx);		// cast non-negative integers as unsigned intergers
	y = static_cast<unsigned int>(sy);

	return true;
}

// Method 4: Get comma-seperated coordinates from the user 
int TicTacToeGame::prompt(unsigned int &x, unsigned int &y) { 
	std::string answer;
	bool isValid = false;
	do {
		std::cout << "Please enter a comma-seperated coordinate in [1:"<<DIM_X_-2<<",1:"<<DIM_Y_-2<<"] or type \'quit\'" <<std::endl;
		std::cin >> answer;
		std::cout << "You entered: " << answer << std::endl;
		isValid = get_coordinates(answer, x, y);
		if (isValid) {																		// comma-seperated coordinates
			isValid = (x >= 1 && x <= DIM_X_ - 2 && y >= 1 && y <= DIM_Y_ - 2);
			if (isValid == false) {															// check if coordinates is in valid bounds
				std::cout << "Careful, you entered out of bound. Try again!" << std::endl;
			}
			else if (gameBoard_[index(x, y)].code_ != piece_code::EMPTY) {					// check if the place is empty
				isValid = false;
				std::cout << "Sorry, the place is not empty. Try again!" << std::endl;
			}

		}
	} while (answer.compare("quit") != 0 && isValid == false);
	
	if (isValid == false) {																	// Player quits the game without making a valid move
		std::cout << "someone wants to quit the game."<<std::endl;
		return exit_code::EarlyQuit;
	}
	return exit_code::Success; 
}

// Method 5: remember whose turn it is: even moveSoFar indicates that the rurn is X's, whereas odd evenSoFar Os 
int TicTacToeGame::turn() { 
										
	unsigned int x, y;
	game_piece piece;
	std::string playerName;
	int playerTurn = movesSoFar_.size() % 2;		// finds out which player's turn it is

	/* Update game piece and player name based on who has the current turn: either X or Y */
	if (playerTurn == 0) {
		playerName = "X";
		piece.code_ = piece_code::X;
		piece.name_ = "X";
		piece.disp_ = "X";
	}
	else {
		playerName = "Y";
		piece.code_ = piece_code::O;
		piece.name_ = "O";
		piece.disp_ = "O";
	}
	std::cout << "Player "<< playerName <<"'s turn..." << std::endl;
	
	int res = prompt(x, y);							// Get coordinates of a valid move
	if (res != exit_code::Success) {										// Player quits the game without making a valid move
		return exit_code::EarlyQuit;				// Someone wants to quit, no valid move
	}
	/* Update game status */
	movesSoFar_.push_back(std::make_pair(x, y));	// Store valid move
	gameBoard_[index(x, y)] = piece;				// Place the piece on the game board
	std::cout << *this << std::endl;				// Print game board
	std::cout << std::endl;							
	std::cout << "Player "<<playerName<< " : ";		// Print username
	// Print which moves are played so far by a player who has the current turn;
	// even indices for player X, odd indices for player O
	for (unsigned int i = playerTurn; i < movesSoFar_.size(); i=i+2) {
		std::cout << movesSoFar_[i].first << ", " << movesSoFar_[i].second << "; ";
	}
	std::cout << std::endl;
	
	return exit_code::Success; 
}

// Method 6: Users play the game in turns until someone wins or draws
int TicTacToeGame::play() { 
	std::cout <<*this << std::endl;				// Print the game board
	int hasNextTurn;							// Player X starts first
	bool isDone = false;						// Initially nobody has same pieces 3 times in a row
	bool isDraw = false;						// All valid locations are empty
	std::string playerName;
	unsigned int numOfTurns;
	do {
		hasNextTurn = turn();					// A player who has turn plays
		isDone = done();						// Check if any player has same pieces 3 times in a row
		if (isDone == false) {
			isDraw = draw();					// Check if any winning move remained
		}
	} while (!isDone && !isDraw && hasNextTurn == exit_code::Success);

	/* Get the game's status */
	numOfTurns = getNumOfTurns();				// calculate the number of turns played
	if (numOfTurns % 2 == 1) {					// Find out which player's turn
		playerName = "X";
	}
	else {
		playerName = "O";
	}

	if (isDone) {
		std::cout << "Won! Player " << playerName << " is the winner!" << std::endl;
		return exit_code::Success;
	}

	if (isDraw) {
		std::cout << "Draw! " << numOfTurns << " turns have been played. No winning moves remained." << std::endl;
		return exit_code::DrawNoWinner;
	}

	/* Someone should want to quit the game. Game over! */
	std::cout << "Player "<<playerName<<" quits! "<<numOfTurns<<" turns have been played. " << std::endl;
	
	return exit_code::EarlyQuit;
}




