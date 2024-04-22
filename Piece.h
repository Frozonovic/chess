/**
 * @file Piece.h
 * @brief Declarations for the Piece class
 *
 * @author Brody Lee (blee20@georgefox.edu)
 */


#ifndef PIECE_H
#define PIECE_H


#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>


class Square;


/** Alias so that piece values are not confused with standard integers */
typedef unsigned int piece_value_t;


/**
 * @class Piece
 * @brief Models a generic chess piece
 */
class Piece {
   public:
      /** Color options for piece teams */
      enum struct Color {
         black, white
      };
      
      
      /**
       * @brief Initializes the internal state for a new piece
       *
       * @param color Color to distinguish between the two teams
       * @param location Default location on the board
       */
      Piece(const Piece::Color color, Square &location) : _color(color) {
         this->set_location(&location);
      }
      
      
      /**
       * @brief Fetches the value of a piece
       *
       * @return Value the piece is worth
       */
      virtual piece_value_t value() const = 0;
      
      
      /**
       * @brief Fetches the color of the piece's team
       *
       * @return Color of the piece's team
       */
      Piece::Color color() const;
      
      
      /**
       * @brief Fetches the current location of the piece
       *
       * @return Current location of the piece
       */
      Square *location() const;
      
      
      /**
       * @brief Moves the piece to a different square
       *
       * @param location Square to move the piece to
       */
      void set_location(Square *location);
      
      
      /**
       * @brief Determines if the piece is currently on a square
       *
       * @return True if on a square, else false
       */
      bool is_on_square() const;
      
      
      /**
       * @brief Determines if the provided location is a viable square
       *
       * @param location Square to consider movement to
       * @return True if location is in the piece's move-set, else false
       */
      virtual bool can_move_to(const Square &location) const = 0;
      
      
      /**
       * @brief Moves the piece to the designated location if possible
       *
       * @param location New square to move to
       * @return True if move is completed, else false
       */
      virtual bool move_to(Square &location);
      
      
      /**
       * @brief Captures a piece and removes it from the board
       */
      void capture();
      
      
      /**
       * @brief Constructs a string to represent a piece
       *
       * @return String representation of a piece
       */
      virtual std::string str() const = 0;
      
      
      /**
       * @brief Deconstructs a piece
       */
      virtual ~Piece() = default;
   
   private:
      /** Color of the team the piece belongs to */
      const Piece::Color _color;
      
      /** Current location of the piece */
      Square *_location = nullptr;
};


/**
 * @brief Outputs the piece's contents to a designated stream
 *
 * @param os Stream output
 * @param piece Piece to output
 * @return Updated stream output
 */
std::ostream &operator<<(std::ostream &os, const Piece &piece);


#endif
