/**
 * @file Piece.cpp
 * @brief Implementation for the Piece class
 *
 * @author Brody Lee (blee20@georgefox.edu)
 */


#include "Square.h"
#include "Piece.h"


Piece::Color Piece::color() const { return _color; }


Square *Piece::location() const { return _location; }


void Piece::set_location(Square *location) {
   if (this->_location != nullptr) {
      this->_location->_occupant = nullptr;
   }
   
   this->_location = location;
   
   if (location != nullptr) {
      location->_occupant = this;
   }
   
}


bool Piece::is_on_square() const { return this->_location != nullptr; }


bool Piece::move_to(Square &location) {
   bool move_completed = false;
   
   if (this->can_move_to(location)) {
      this->set_location(&location);
      move_completed = true;
   }
   
   return move_completed;
}


void Piece::capture() {
   set_location(nullptr);
}


std::ostream &operator<<(std::ostream &os, const Piece &piece) {
   os << piece.str();
   
   return os;
}