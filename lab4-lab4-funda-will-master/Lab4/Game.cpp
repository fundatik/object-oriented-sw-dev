/*
 * File: Game.cpp
 * Authors: Funda Atik, Will Wu
 * E-mails: fatik@wustl.edu, willwu@wustl.edu
 * GomokuGame game is 2 player where each player try to get five stones in a row, diagonal and column.
 * This file defines fundamental operations for game agents such as game pieces and game player
 */


#include "Game.h"
#include "Util.h"
#include <algorithm> 

// convert the code of piece to string
std::string code2text(piece_code code) {
	switch (code)
	{
	case piece_code::X: return "X";
	case piece_code::O: return "O";
	case piece_code::B: return "B";
	case piece_code::W: return "W";
	case piece_code::EMPTY: return " ";
	default:return "$";
	}
}

piece_code text2color(std::string text) {
	lowercase(text);

	if (text.compare("X") == 0) {
		return piece_code::X;
	}
	else if (text.compare("O") == 0) {
		return piece_code::O;
	}
	else if (text.compare("B") == 0) {
		return piece_code::B;
	}
	else if (text.compare("W") == 0) {
		return piece_code::W;
	}
	else if (std::all_of(text.begin(), text.end(), isspace)) {
		return piece_code::EMPTY;
	}
	else {
		return piece_code::InvalidColor;
	}
}

// Player can be either the first player and the second player, and update their piece based on the game
game_player::game_player(game_type gType, player_type pType) {
	if (gType == game_type::TypeGomoku && pType == player_type::TypeFirstPlayer) {
		name_ = constants::DefaultFirstPlayerName;
		piece_.setGamePiece(piece_code::B);
	}
	else if (gType == game_type::TypeGomoku && pType == player_type::TypeSecondPlayer) {
		name_ = constants::DefaultSecondPlayerName;
		piece_.setGamePiece(piece_code::W);
	}
	else if (gType == game_type::TypeTicTacToe && pType == player_type::TypeFirstPlayer) {
		name_ = constants::DefaultFirstPlayerName;
		piece_.setGamePiece(piece_code::X);
	}
	else {
		name_ = constants::DefaultSecondPlayerName;
		piece_.setGamePiece(piece_code::O);
	}
}