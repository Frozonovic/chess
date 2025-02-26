/**
 * @file Pawn.cpp
 * @brief Implementation for the Pawn class
 */


#include "Pawn.h"


piece_value_t Pawn::value() const {
   return 1;
}


bool Pawn::can_move_to(const Square &location) const {
   // A pawn can move exactly one space forward
   Square *current_location = this->location();
   
   size_t current_rank = current_location->rank();
   size_t current_file = current_location->file();
   size_t new_rank = location.rank();
   size_t new_file = location.file();
   
   // Pawn moves toward the other team, so we have to adjust accordingly
   size_t rank_diff;
   if (Piece::Color::black == this->color()) {
      rank_diff = new_rank - current_rank;
   } else {
      rank_diff = current_rank - new_rank;
   }
   
   // Pawn moves horizontally for capturing, so we have to adjust accordingly
   size_t file_diff;
   if (new_file > current_file) {
      file_diff = new_file - current_file;
   } else {
      file_diff = current_file - new_file;
   }
   
   // Because of the pawn's normal move-set, there are two cases to check for valid movement
   bool check_rank = rank_diff == 1 || (rank_diff == 2 && !_moved);
   
   // Because of the pawn's normal move-set, file is a constant value
   bool check_file = file_diff == 0;
   
   // Pawns only capture diagonally, so normal movement spaces must be unoccupied
   bool check_occupation = !location.is_occupied();
   
   // All three need to be true for a normal move to happen
   bool check_for_movement = check_rank && check_file && check_occupation;
   
   // For capturing, the difference between ranks should still be one
   check_rank = rank_diff == 1;
   
   // For capturing, the difference between files should be one
   check_file = file_diff == 1;
   
   // For capturing, the square must be occupied and the pieces must be on different teams
   if (location.is_occupied()) {
      Piece *maybe_opponent = location.occupant();
      check_occupation = maybe_opponent->color() != this->color();
   } else {
      check_occupation = false;
   }

   // All three need to be true for a capture to happen
   bool check_for_capture = check_rank && check_file && check_occupation;
   
   return check_for_movement || check_for_capture;
}


bool Pawn::move_to(Square &location) {
   bool move_completed = false;
   
   if (can_move_to(location)) {
      if (location.is_occupied()) {
         location.occupant()->capture();
      }
      
      set_location(&location);
      move_completed = true;
      
      if (!(this->_moved)) {
         this->_moved = true;
      }
   }
   
   return move_completed;
}


std::string Pawn::str() const {
   std::string symbol;
   
   if (color() == Piece::Color::black) {
      symbol = "♟";
   } else if (color() == Piece::Color::white) {
      symbol = "♙";
   }
   
   return symbol;
}
