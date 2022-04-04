/*
 * File: Game.cpp
 * Author: Funda Atik, E-mail: fatik@wustl.edu
 * This file includes common functions for game pieces
 *
 */

#include "Game.h"
#include "Util.h"
#include <algorithm> 


std::string color2text(piece_color color) {
	switch (color)
	{
	case piece_color::Red: return "red";
	case piece_color::Black: return "black";
	case piece_color::White: return "white";
	case piece_color::NoColor: return "";
	default:return "lilac";
	}
};

piece_color text2color(std::string text) {
	lowercase(text);

	if (text.compare("red") == 0) {
		return piece_color::Red;
	}
	else if (text.compare("black") == 0) {
		return piece_color::Black;
	}
	else if (text.compare("white") == 0) {
		return piece_color::White;
	}
	else if (std::all_of(text.begin(), text.end(), isspace)) {
		return piece_color::NoColor;
	}
	else {
		return piece_color::InvalidColor;
	}
}