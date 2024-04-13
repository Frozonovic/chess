/**
 * @file Rook.cpp
 * @brief Implementation for the Rook class
 *
 * @author Brody Lee (blee20@georgefox.edu)
 */


#include "Rook.h"


piece_value_t Rook::value() const {
   return 5;
}


bool Rook::can_move_to(const Square& location) const {
   // The rook can move horizontally or vertically any number of spaces
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
   
   // If the two ranks are exclusively equivalent, it is a valid move
   bool check_rank = rank_diff == 0;
   
   // If the two files are exclusively equivalent, it is a valid move
   bool check_file = file_diff == 0;
   
   // If new location is occupied, assert that the occupant can be captured
   bool check_color;
   
   if (location.is_occupied()) {
      Piece* maybe_opponent = location.occupant();
      check_color = color() != maybe_opponent->color();
   } else {
      check_color = true;
   }
   
   return (check_rank && !check_file || !check_rank && check_file) && check_color;
}


std::string Rook::str() const {
   std::string symbol;
   
   if (color() == Piece::Color::black) {
      symbol = "♜";
   } else if (color() == Piece::Color::white) {
      symbol = "♖";
   }
   
   return symbol;
}
