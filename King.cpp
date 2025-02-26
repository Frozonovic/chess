/**
 * @file King.cpp
 * @brief Implementation for the King class
 *
 * @author Brody Lee (blee20@georgefox.edu)
 */


#include "King.h"


piece_value_t King::value() const {
   return 200;
}


bool King::can_move_to(const Square &location) const {
   // The king can move horizontally, vertically, or diagonally a single space
   int DIAG_DIST = 2;
   
   Square *current_location = this->location();
   
   size_t current_rank = current_location->rank();
   size_t current_file = current_location->file();
   size_t new_rank = location.rank();
   size_t new_file = location.file();
   
   // The king is a queen hybrid, so we take the queen's logic and make a slight tweak to it
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
   
   // For diagonal movement, the difference between ranks and files should add up to 2
   bool check_diag = rank_diff + file_diff == DIAG_DIST;
   
   // For vertical movement, the difference between the two ranks should equal 1
   bool check_rank = rank_diff == 1;
   
   // For horizontal movement, the difference between the two files should equal 1
   bool check_file = file_diff == 1;
   
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


std::string King::str() const {
   std::string symbol;
   
   if (color() == Piece::Color::black) {
      symbol = "♚"; // Should be on e8 at the start
   } else if (color() == Piece::Color::white) {
      symbol = "♔"; // Should be on e1 at the start
   }
   
   return symbol;
}
