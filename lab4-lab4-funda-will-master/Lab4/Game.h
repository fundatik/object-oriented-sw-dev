/*
 * File: Game.h
 * Authors: Funda Atik, Will Wu
 * E-mails: fatik@wustl.edu, willwu@wustl.edu
 * This file includes fundamental structures for a game such as game pieces and game player
 *
 */

#pragma once

#ifndef GAME_H
#define GAME_H

#include "constants.h"
#include <iostream>
#include <string>

enum class game_type { TypeGomoku, TypeTicTacToe };
enum class player_type { TypeFirstPlayer, TypeSecondPlayer };
enum class piece_code { X, O, EMPTY, B, W, InvalidColor };

std::string code2text(piece_code code);
piece_code text2color(std::string);

// Game piece that are placed on the game board
struct game_piece {
	// default constructor
	game_piece() : code_(piece_code::EMPTY), name_("S"), disp_(" ") {}
	game_piece(piece_code code, std::string name, std::string disp) : code_(code), name_(name), disp_(disp) {}

	void setGamePiece(piece_code code) {
		code_ = code;
		name_ = code2text(code);
		disp_ = code2text(code);
	}

	// member variables
	piece_code code_;
	std::string name_;
	std::string disp_;
};

struct game_player {

	game_player(game_type gType, player_type pType);

	// variables
	std::string name_;
	game_piece piece_;
};

#endif