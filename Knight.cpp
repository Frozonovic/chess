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
    Piece* location_occupant = location.occupant();
    
    size_t current_rank = current_location->rank();
    size_t current_file = current_location->file();
    size_t new_rank = location.rank();
    size_t new_file = location.file();
    
    double diff_one = std::pow(current_rank - new_rank, 2);
    double diff_two = std::pow(current_file - new_file, 2);
    
    // The "distance" between the current location and new location is always sqrt(5)
    bool check_l_shape = (std::sqrt(diff_one + diff_two) - DISTANCE) < EPSILON;
    
    // If new location is occupied, assert that the occupant can be captured
    bool check_color = color() != location_occupant->color();
    
    return check_l_shape && check_color;
}


std::string Knight::str() const {
    std::string symbol = " ";
    
    if (color() == Piece::Color::black) {
        symbol = "♞";
    } else if (color() == Piece::Color::white) {
        symbol = "♘";
    }
    
    return symbol;
}
