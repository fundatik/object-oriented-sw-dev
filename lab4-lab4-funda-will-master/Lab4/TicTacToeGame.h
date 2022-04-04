/*
 * File: TicTacToeGame.h
 * Authors: Funda Atik, Will Wu
 * E-mails: fatik@wustl.edu, willwu@wustl.edu
 * TicTacToeGame game is 2 player where each player try to get 3 pieces in a row, diagonal and column.
 * The default game board size is 3x3
 */

#pragma once

#ifndef TICTACTOEGAME_H
#define TICTACTOEGAME_H

#include "GameBase.h"

class TicTacToeGame : public GameBase {

	// overload insertion operator to print out the game board 
	friend std::ostream& operator<< (std::ostream& ost, const TicTacToeGame& game);
public:
	// constructors
	TicTacToeGame();
	TicTacToeGame(unsigned int X, unsigned int Y);

	// override methdos 
	virtual void print() override;
	virtual bool done() override;
	virtual bool draw() override;
	virtual int turn() override;

};

#endif
