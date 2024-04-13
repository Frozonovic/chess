/**
 * @file Rook.h
 * @brief Declarations for the Rook class
 *
 * @author Brody Lee (blee20@georgefox.edu)
 */


#ifndef ROOK_H
#define ROOK_H


#include <iostream>
#include "Square.h"
#include "Piece.h"


/**
 * @class Rook
 * @brief Models a rook chess piece
 *
 * @extends Piece
 */
class Rook : public Piece {
   public:
      /**
       * @brief Initializes the internal state for a new rook
       *
       * @param color Color to distinguish between the two teams
       * @param location Default location on the board
       */
      Rook(Piece::Color color, Square& location) : Piece(color, location) {}
      
      
      /**
       * @brief Fetches the value of a rook
       *
       * @return Value a rook piece is worth
       */
      piece_value_t value() const override;
      
      
      /**
       * @brief Determines if the provided location is a viable square
       *
       * @param location Square to consider movement to
       * @return True if location is in the rook's move-set, else false
       */
      bool can_move_to(const Square& location) const override;
      
      
      /**
       * @brief Constructs a string to represent a rook
       *
       * @return String representation of a rook
       */
      std::string str() const override;
};


#endif
