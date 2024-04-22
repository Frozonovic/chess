/**
 * @file Chess.h
 * @brief Declarations for the Chess.cpp file
 *
 * @author Brody Lee (blee20@georgefox.edu)
 */


#ifndef CHESS_H
#define CHESS_H


#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Player.h"
#include "Board.h"
#include "Square.h"
#include "Piece.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"


/**
 * @brief Splits a string into individual pieces and stores it in the provided buffer
 *
 * @param buffer Object to store each piece
 * @param s String to split
 * @param delimiter Character to distinguish between each piece
 */
void tokenizer(std::vector<std::string> &buffer, const std::string &s, char delimiter);

#endif
