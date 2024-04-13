/**
 * @file Square.h
 * @brief Declarations for the Square class
 *
 * @author Brody Lee (blee20@georgefox.edu)
 */


#ifndef SQUARE_H
#define SQUARE_H


#include <cstdlib>
#include <iostream>
#include "Piece.h"


/**
 * @class Square
 * @brief Models a square on a chess board
 */
class Square {
   public:
      /**
       * @brief Initializes the internal state for a new square
       *
       * @param rank Row number the square is in
       * @param file Column number the square is in
       */
      Square(size_t rank, size_t file) : _rank(rank), _file(file) {}
      
      
      /**
       * @brief Fetches the row number of the square
       *
       * @return Row number of the square
       */
      size_t rank() const;
      
      
      /**
       * @brief Fetches the column number of the square
       *
       * @return Column number of the square
       */
      size_t file() const;
      
      
      /**
       * @brief Determines if the square has an occupant
       *
       * @return True if an occupant is present, else false
       */
      bool is_occupied() const;
      
      
      /**
       * @brief Fetches the occupant of the square if possible
       *
       * @return Occupant of the square
       */
      Piece* occupant() const;
   
      
   private:
      /** Changes the occupant of the square */
      void set_occupant(Piece* occupant);
      
      
      /** Row the square is in on the board */
      const size_t _rank;
      
      
      /** Column the square is in on the board */
      const size_t _file;
      
      
      /** Current occupant of the square */
      Piece* _occupant = nullptr;
      
      
      /** Method from Piece class that changes the square a piece is assigned to */
      friend void Piece::set_location(Square* location);
      
      
      /** Method from Piece class that captures a piece and removes it from the board */
      friend void Piece::capture();
};


/**
 * @brief Outputs the square contents to a designated stream
 *
 * @param os Stream output
 * @param square Square to output
 * @return Updated stream output
 */
std::ostream& operator<<(std::ostream& os, const Square& square);


#endif
