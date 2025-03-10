/**
 * @file Queen.cpp
 * @brief Implementation for the Queen class
 *
 * @author Brody Lee (blee20@georgefox.edu)
 */


#include "Queen.h"


piece_value_t Queen::value() const {
   return 9;
}


bool Queen::can_move_to(const Square &location) const {
   // The queen can move horizontally, vertically, or diagonally any number of spaces
   Square *current_location = this->location();
   
   size_t current_rank = current_location->rank();
   size_t current_file = current_location->file();
   size_t new_rank = location.rank();
   size_t new_file = location.file();
   
   // The queen is a rook and bishop hybrid, so we merge the logic together for both pieces
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
   
   // Like the bishop, the rank and file differences are equivalent for diagonal movement
   bool check_diag = rank_diff - file_diff == 0;
   
   // Like the rook, the two ranks are exclusively equal or the two files are exclusively equal
   bool check_rank = rank_diff == 0;
   bool check_file = file_diff == 0;
   
   // If new location is occupied, assert that the occupant can be captured
   bool check_color;
   
   if (location.is_occupied()) {
      Piece *maybe_opponent = location.occupant();
      check_color = color() != maybe_opponent->color();
   } else {
      check_color = true;
   }
   
   // NOTE: If this fails, it is possible we need an exclusive or between rook and bishop checks
   return check_diag || ((check_rank && !check_file) || (!check_rank && check_file)) && check_color;
}


std::string Queen::str() const {
   std::string symbol;
   
   if (color() == Piece::Color::black) {
      symbol = "♛";
   } else if (color() == Piece::Color::white) {
      symbol = "♕";
   }
   
   return symbol;
}
