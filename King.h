/**
 * @file King.h
 * @brief Declarations for the King class
 *
 * @author Brody Lee (blee20@goergefox.edu)
 */


#ifndef KING_H
#define KING_H


#include <string>
#include "Square.h"
#include "Piece.h"


/**
 * @class King
 * @brief Models a king chess piece
 *
 * @extends Piece
 */
class King : public Piece {
   public:
      /**
       * @brief Initializes the internal state for a new king
       *
       * @param color Color to distinguish between the two teams
       * @param location Default location on the board
       */
      explicit King(Piece::Color color, Square& location) : Piece(color, location) {}
      
      
      /**
       * @brief Fetches the value of a king
       *
       * @return Value a king piece is worth
       */
      piece_value_t value() const override;
      
      
      /**
       * @brief Determines if the provided location is a viable square
       *
       * @param location Square to consider movement to
       * @return True if location is in the king's move-set, else false
       */
      bool can_move_to(const Square& location) const override;
      
      
      /**
       * @brief Constructs a string to represent a king
       *
       * @return String representation of a king
       */
      std::string str() const override;
};


#endif
