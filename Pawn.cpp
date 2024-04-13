/**
 * @file Pawn.cpp
 * @brief Implementation for the Pawn class
 */


#include "Pawn.h"


piece_value_t Pawn::value() const {
    return 1;
}


bool Pawn::can_move_to(const Square& location) const {
    // A pawn can move exactly one space forward
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
    
    // Because of the pawn's normal move-set, the difference between the two ranks should equal 1
    bool check_rank = rank_diff == 1;
    
    // Because of the pawn's normal move-set, file is a constant value
    bool check_file = file_diff == 0;
   
   // If new location is occupied, assert that the occupant can be captured
   bool check_color;
   
   if (location.is_occupied()) {
      Piece* maybe_opponent = location.occupant();
      check_color = color() != maybe_opponent->color();
   } else {
      check_color = true;
   }
    
    return check_rank && check_file && check_color;
}


bool Pawn::move_to(Square& location) {
  bool move_completed = false;
  
  if (can_move_to(location)) {
    set_location(&location);
    move_completed = true;
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
