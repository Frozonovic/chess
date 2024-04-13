/**
 * @file Knight.h
 * @brief Declarations for the Knight class
 */

#ifndef KNIGHT_H
#define KNIGHT_H


#include <cstdlib>
#include <cmath>
#include <string>
#include "Square.h"
#include "Piece.h"


/**
 * @class Knight
 * @brief Models a knight chess piece
 *
 * @extends Piece
 */
class Knight : public Piece {
   public:
      /**
       * @brief Initializes the internal state for a new knight
       *
       * @param color Color to distinguish between the two teams
       * @param location Default location on the board
       */
      Knight(Piece::Color color, Square& location) : Piece(color, location) {}
      
      
      /**
       * @brief Fetches the value of a knight
       *
       * @return Value a knight piece is worth
       */
      piece_value_t value() const override;
      
      
      /**
       * @brief Determines if the provided location is a viable square
       *
       * @param location Square to consider movement to
       * @return True if location is in the knight's move-set, else false
       */
      bool can_move_to(const Square& location) const override;
      
      
      /**
       * @brief Constructs a string to represent a knight
       *
       * @return String representation of a knight
       */
      std::string str() const override;
};


#endif
