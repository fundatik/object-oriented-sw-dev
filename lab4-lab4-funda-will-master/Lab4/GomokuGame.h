/*
 * File: GomokuGame.h
 * Authors: Funda Atik, Will Wu
 * E-mails: fatik@wustl.edu, willwu@wustl.edu
 * GomokuGame game is 2 player where each player try to get five stones in a row, diagonal and column. 
 * The default game board size is 19x19, whereas the minimum board size is 3x3
 */

#pragma once

#ifndef GomokuGAME_H
#define GomokuGAME_H

#include "GameBase.h"

class GomokuGame : public GameBase {

	// overload insertion operator to print out the game board 
	friend std::ostream& operator<< (std::ostream& ost, const GomokuGame& game);
public:
	// constructors
	GomokuGame();
	GomokuGame(unsigned int X);
	GomokuGame(unsigned int X, int countInArow);

	// override methdos 
	virtual void print() override;
	virtual bool done() override;
	virtual bool draw() override;
	virtual int turn() override;
};
std::ostream& operator<< (std::ostream& ost, const GomokuGame& game);

#endif
