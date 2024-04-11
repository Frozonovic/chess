/**
 * @file Bishop.cpp
 * @brief Implementation for the Bishop class
 *
 * @author Brody Lee (blee20@georgefox.edu)
 */
 

#include "Bishop.h"


piece_value_t Bishop::value() const {
  return 3;
}


bool Bishop::can_move_to(const Square &location) const {
  // The bishop can move diagonally any number of squares
  double EPSILON = 1E-6;
  Square* current_location = this->location();
  Piece* location_occupant = location.occupant();
  
  size_t current_rank = current_location->rank();
  size_t current_file = current_location->file();
  size_t new_rank = location.rank();
  size_t new_file = location.file();
  
  size_t rank_diff = current_rank - new_rank;
  size_t file_diff = current_file - new_file;
  
  // The difference between the two ranks and the two files should be equivalent to each other
  bool check_diag = rank_diff - file_diff < EPSILON;
  
  // If new location is occupied, assert that the occupant can be captured
  bool check_color = color() != location_occupant->color();
  
  return check_diag && check_color;
}


std::string Bishop::str() const {
  std::string symbol = " ";
  
  if (color() == Piece::Color::black) {
    symbol = "♝";
  } else if (color() == Piece::Color::white) {
    symbol = "♗";
  }
  return symbol;
}