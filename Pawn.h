/**
 * @file Pawn.h
 * @brief Declarations for the Pawn class
 */


#ifndef PAWN_H
#define PAWN_H


#include <string>
#include "Square.h"
#include "Piece.h"


/**
 * @class Pawn
 * @brief Models a pawn chess piece
 *
 * @extends Piece
 */
class Pawn : public Piece {
   public:
      /**
       * @brief Initializes the internal state for a new bishop
       *
       * @param color Color to distinguish between the two teams
       * @param location Default location on the board
       */
      Pawn(Piece::Color color, Square& location) : Piece(color, location) {}
      
      
      /**
       * @brief Fetches the value of a pawn
       *
       * @return Value a bishop piece is worth
       */
      piece_value_t value() const override;
      
      
      /**
       * @brief Determines if the provided location is a viable square
       *
       * @param location Square to consider movement to
       * @return True if location is in the pawn's move-set, else false
       */
      bool can_move_to(const Square& location) const override;
      
      
      /**
       * @brief Moves the pawn to the designated location if possible
       *
       * @param location New square to move to
       * @return True if move is completed, else false
       */
      bool move_to(Square& location) override;
      
      
      /**
       * @brief Constructs a string to represent a pawn
       *
       * @return String representation of a pawn
       */
      std::string str() const override;
   
   
   private:
      /** Tracks if a pawn has moved from its starting location */
      bool _moved = false;
};


#endif
