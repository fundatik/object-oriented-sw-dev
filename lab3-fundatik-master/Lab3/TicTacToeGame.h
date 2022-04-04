/*
 * File: TicTacToeGame.h
 * Author: Funda Atik, E-mail: fatik@wustl.edu
 * This file includes various declarations which are necessarry for playing a TicTacToeGame
 * Declarations: TicTacToeGame class, game_piece struct, and the enumaration of piece_code class
 *
 */

#pragma once

#ifndef TICTACTOEGAME_H
#define TICTACTOEGAME_H

#include <iostream>
#include <vector>
#include <iostream>
#include <sstream>
#include <utility>  

// A game piece can be one of three types: valid moves such as X and O, without any moves: EMPTY
enum class piece_code { X, O, EMPTY };

// Game piece that are on the game board
struct game_piece {
	// default constructor
	game_piece() : code_(piece_code::EMPTY), name_("S"), disp_(" ") {}
	// constructor
	game_piece(piece_code code, std::string name, std::string disp) : code_(code), name_(name), disp_(disp) {}

	// member variables
	piece_code code_;
	std::string name_;
	std::string disp_;
};

class TicTacToeGame {
	// overload insertion operator to print out the game board 
	friend std::ostream& operator<< (std::ostream& ost, const TicTacToeGame& game);
public:
	// constructors
	TicTacToeGame();
	TicTacToeGame(unsigned int X, unsigned int Y);

	// methods
	bool done(); // return true 3-Xs or Os are a vertical, horizontal or diagonal line, ot. return false
	bool draw(); // returns false if empty spaces exist or if done() return true, ot. return true
	int prompt(unsigned int &x, unsigned int &y); // get comma-seperated coordinates from the user 
	int turn(); // return 1 if one of the user quits the game, otherwise it return 0 for a succesfull move
	int play();	// 
	
private:

	/* Game board definitions */
	std::vector<game_piece> gameBoard_;
	unsigned int DIM_X_;
	unsigned int DIM_Y_;
	const std::string DELIM_ = " ";
	std::vector<std::pair<int,int>> movesSoFar_;

	//methods
	// Returns true if a line starts with comma-separated two unsigned integers 
	bool get_coordinates(std::string line, unsigned int& x, unsigned int& y);
	// Calculate vector index based on x,y coordinates
	unsigned int index(int x, int y) const { return x + DIM_X_ * y; }
	// Return maximum number of valid moves that can be played in a game
	const unsigned int getMaxMoves() { return (DIM_X_ - 2) * (DIM_Y_ - 2); }
	// Return the number of turn are played so far
	const unsigned int getNumOfTurns() { return movesSoFar_.size();}
};



#endif
