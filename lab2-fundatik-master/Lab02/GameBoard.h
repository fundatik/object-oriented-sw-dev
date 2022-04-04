#pragma once

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <fstream>
#include <sstream>
#include <vector>
#include <utility> 

int read_dimensions(std::ifstream& ifs, unsigned int& x, unsigned int& y);
int read_pieces(std::ifstream& ifs, std::vector<game_piece>& pieces, unsigned int x, unsigned int y);
int show_pieces(const std::vector<game_piece>& pieces, unsigned int x, unsigned int y);
// Extra credit
int show_pieces_verbose(const std::vector<game_piece>& pieces, unsigned int x, unsigned int y);

#endif