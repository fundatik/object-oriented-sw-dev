#pragma once

#ifndef GAME_H
#define GAME_H


#include <iostream>
#include <string>

enum class piece_color { Red, Black, White, InvalidColor, NoColor };
enum piece_stat {valid,empty};

std::string color2text(piece_color);
piece_color text2color(std::string);

struct game_piece {
	piece_color color;
	std::string name;
	std::string display;
};

#endif