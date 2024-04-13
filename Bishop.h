/**
 * @file Bishop.h
 * @brief Declarations for the Bishop class
 *
 * @author Brody Lee (blee20@georgefox.edu)
 */


#ifndef BISHOP_H
#define BISHOP_H


#include <string>
#include "Square.h"
#include "Piece.h"


/**
 * @class Bishop
 * @brief Models a bishop chess piece
 *
 * @extends Piece
 */
class Bishop : public Piece {
   public:
      /**
       * @brief Initializes the internal state for a new bishop
       *
       * @param color Color to distinguish between the two teams
       * @param location Default location on the board
       */
      Bishop(Piece::Color color, Square& location) : Piece(color, location) {}
      
      
      /**
       * @brief Fetches the value of a bishop
       *
       * @return Value a bishop piece is worth
       */
      piece_value_t value() const override;
      
      
      /**
       * @brief Determines if the provided location is a viable square
       *
       * @param location Square to consider movement to
       * @return True if location is in the bishop's move-set, else false
       */
      bool can_move_to(const Square& location) const override;
      
      
      /**
       * @brief Constructs a string to represent a bishop
       *
       * @return String representation of a bishop
       */
      std::string str() const override;
};


#endif
