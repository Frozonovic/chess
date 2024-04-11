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
    double EPSILON = 1E-6;
    Square* current_location = this->location();
    Piece* location_occupant = location.occupant();
    
    size_t current_rank = current_location->rank();
    size_t current_file = current_location->file();
    size_t new_rank = location.rank();
    size_t new_file = location.file();
    
    auto rank_diff = (double)(current_rank - new_rank);
    auto file_diff = (double)(current_file - new_file);
    
    // If the two ranks are exclusively equivalent, it is a valid move
    bool check_rank = rank_diff < EPSILON;
    
    // If the two files are exclusively equivalent, it is a valid move
    bool check_file = file_diff < EPSILON;
    
    // If new location is occupied, assert that the occupant can be captured
    bool check_color = color() != location_occupant->color();
    
    return (check_rank && !check_file || !check_rank && check_file) && check_color;
}


std::string Rook::str() const {
    std::string symbol = " ";
    
    if (color() == Piece::Color::black) {
        symbol = "♜";
    } else if (color() == Piece::Color::white) {
        symbol = "♖";
    }
    
    return symbol;
}
