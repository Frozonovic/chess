/**
 * @file Piece.cpp
 * @brief Implementation for the Piece class
 *
 * @author Brody Lee (blee20@georgefox.edu)
 */
 

#include "Piece.h"


Piece::Color Piece::color() const { return _color; }


Square* Piece::location() const { return _location; }


void Piece::set_location(Square* location) { _location = location; }


bool Piece::is_on_square() const { _location != nullptr; }


bool Piece::move_to(Square& location) {
  bool move_completed = false;
  
  if (can_move_to(location)) {
    set_location(&location);
    move_completed = true;
  }
  
  return move_completed;
}


void Piece::capture() {
  set_location(nullptr);
}


std::ostream& operator<<(std::ostream& os, const Piece& piece) {
    os << piece.str();
    
    return os;
}