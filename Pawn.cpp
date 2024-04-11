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
    double EPSILON = 1E-6;
    int RANK_DIFF = 1;
    int FILE_DIFF = 0;
    
    Square* current_location = this->location();
    Piece* location_occupant = location.occupant();
    
    size_t current_rank = current_location->rank();
    size_t current_file = current_location->file();
    size_t new_rank = location.rank();
    size_t new_file = location.file();
    
    // Because of the pawn's normal move-set, the difference between the two ranks should equal 1
    bool check_rank;
    
    if (current_rank >= new_rank) {
      check_rank = (double)(current_rank - new_rank) - RANK_DIFF < EPSILON;
    } else {
      check_rank = (double)(new_rank - current_rank) - RANK_DIFF < EPSILON;
    }
    
    // Because of the pawn's normal move-set, file is a constant value
    bool check_file;
    if (current_file >= new_file) {
      check_file = (double)(current_file - new_file) - FILE_DIFF < EPSILON;
    } else {
      check_file = (double)(new_file - current_file) - FILE_DIFF < EPSILON;
    }
    
    
    // If new location is occupied, assert that the occupant can be captured
    bool check_color = color() != location_occupant->color();
    
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
    std::string symbol = " ";
    
    if (color() == Piece::Color::black) {
        symbol = "♟";
    } else if (color() == Piece::Color::white) {
        symbol = "♙";
    }
    
    return symbol;
}
