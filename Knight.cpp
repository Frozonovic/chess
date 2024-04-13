/**
 * @file Knight.cpp
 * @brief Implementation for the Knight class
 *
 * @author Brody Lee (blee20@georgefox.edu)
 */


#include "Knight.h"


piece_value_t Knight::value() const {
   return 3;
}


bool Knight::can_move_to(const Square& location) const {
   // The knight can move exactly 3 spaces in an L-shaped pattern
   double EPSILON = 1E-6;
   double DISTANCE = std::sqrt(5);
   
   Square* current_location = this->location();
   
   size_t current_rank = current_location->rank();
   size_t current_file = current_location->file();
   size_t new_rank = location.rank();
   size_t new_file = location.file();
   
   size_t rank_diff;
   
   if (current_rank > new_rank) {
      rank_diff = current_rank - new_rank;
   } else {
      rank_diff = new_rank - current_rank;
   }
   
   size_t file_diff;
   
   if (current_file > new_file) {
      file_diff = current_file - new_file;
   } else {
      file_diff = new_file - current_file;
   }
   
   double diff_one = std::pow(rank_diff, 2);
   double diff_two = std::pow(file_diff, 2);
   
   // The "distance" between the current location and new location is always sqrt(5)
   bool check_l_shape = (std::sqrt(diff_one + diff_two) - DISTANCE) < EPSILON;
   
   // If new location is occupied, assert that the occupant can be captured
   bool check_color;
   
   if (location.is_occupied()) {
      Piece* maybe_opponent = location.occupant();
      check_color = color() != maybe_opponent->color();
   } else {
      check_color = true;
   }
   
   return check_l_shape && check_color;
}


std::string Knight::str() const {
   std::string symbol;
   
   if (color() == Piece::Color::black) {
      symbol = "♞";
   } else if (color() == Piece::Color::white) {
      symbol = "♘";
   }
   
   return symbol;
}
