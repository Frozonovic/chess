/**
 * @file Queen.h
 * @brief Declarations for the Queen class
 *
 * @author Brody Lee (blee20@georgefox.edu)
 */


#ifndef QUEEN_H
#define QUEEN_H


#include <string>
#include "Square.h"
#include "Piece.h"


/**
 * @class Queen
 * @brief Models a queen chess piece
 *
 * @extends Piece
 */
class Queen : public Piece {
   public:
      /**
       * @brief Initializes the internal state for a new queen
       *
       * @param color Color to distinguish between the two teams
       * @param location Default location on the board
       */
      Queen(Piece::Color color, Square& location) : Piece(color, location) {}
      
      
      /**
       * @brief Fetches the value of a queen
       *
       * @return Value a queen piece is worth
       */
      piece_value_t value() const override;
      
      
      /**
       * @brief Determines if the provided location is a viable square
       *
       * @param location Square to consider movement to
       * @return True if location is in the queen's move-set, else false
       */
      bool can_move_to(const Square& location) const override;
      
      
      /**
       * @brief Constructs a string to represent a queen
       *
       * @return String representation of a queen
       */
      std::string str() const override;
};


#endif
