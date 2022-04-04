/*
 * File: GameBase.h
 * Authors: Funda Atik, Will Wu
 * E-mails: fatik@wustl.edu, willwu@wustl.edu
 * This file includes is an abstract base class, which defines common actions for playing a game.
 *
 */

#pragma once

#ifndef GAMEBASE_H
#define GAMEBASE_H

#include "Util.h"
#include "Game.h"

#include <string>
#include <iostream>
#include <vector>
#include <iomanip> // setw
#include <sstream>

class GameBase {
public:
	// constructor
	GameBase(unsigned int X, unsigned int Y, game_player firstPlayer, game_player secondPlayer, unsigned int pieces2win);

	// pure virtual functions
	virtual void print() = 0;
	virtual bool done() = 0;
	virtual bool draw() = 0;
	virtual int turn() = 0;

	// get comma-seperated coordinates from the user 
	virtual int prompt(unsigned int& x, unsigned int& y); 
	// Users play the game in turns until someone wins or draws or quits
	int play(); 

	static GameBase* checkArgs(int argc, char* argv[]);

protected:

	// Game board definitions that are common for both tictactoe and gumoku
	std::vector<game_piece> gameBoard_;
	unsigned int dimX_;
	unsigned int dimY_;
	std::vector<std::pair<int, int>> movesSoFar_;
	unsigned int maxDisplayLength_;
	game_player firstPlayer_;
	game_player secondPlayer_;
	unsigned int pieces2Win_;

	// returns true if it successfully gets comma-seperated coordinates, otherwise returns false
	bool get_coordinates(std::string line, unsigned int& x, unsigned int& y);
	// calculate vector index based on x,y coordinates
	unsigned int index(int x, int y) const;
	void updateMaxDisplayLength(std::string display);
	// return the maximum number of valid moves that can be played in a game
	const unsigned int getMaxValidMoves();
	// return the number of turn are played so far
	const unsigned int countMovesSoFar();
	// returns the player who has the next turn
	game_player getCurrentPlayer();
	// returns the player who has played the last time
	game_player getLastPlayer();

	// common functions for arithmetic with unsigned integers
	unsigned int getMax(unsigned int x, unsigned int y);
	unsigned int getMin(unsigned int x, unsigned int y);
	unsigned int getSub(unsigned int x, unsigned int y);

	// check if there is any line in vertical, horizantal, diagonal directions
	bool checkUpperDiagonal(unsigned int x, unsigned y, piece_code lastPieceCode, std::vector<game_piece> board);
	bool checkBottomDiagonal(unsigned int x, unsigned y, piece_code lastPieceCode, std::vector<game_piece> board);
	bool checkVertical(unsigned int x, unsigned y, piece_code lastPieceCode, std::vector<game_piece> board);
	bool checkHorizontal(unsigned int x, unsigned y, piece_code lastPieceCode, std::vector<game_piece> board);

};

#endif
