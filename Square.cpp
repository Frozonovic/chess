/**
 * @file Square.cpp
 * @brief Implementation for the Square class
 *
 * @author Brody Lee (blee20@georgefox.edu)
 */


#include "Square.h"


size_t Square::rank() const { return _rank; }


size_t Square::file() const { return _file; }


bool Square::is_occupied() const { return _occupant != nullptr; }


Piece* Square::occupant() const { return _occupant; }


void Square::set_occupant(Piece* occupant) { _occupant = occupant; }


std::ostream& operator<<(std::ostream& os, const Square& square) {
    os << " ";
    
    return os;
}