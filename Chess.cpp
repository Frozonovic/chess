/**
 * @file Chess.cpp
 * @brief Implementation for playing a proper chess game
 *
 * @author Brody Lee (blee20@georgefox.edu)
 */


#include "Chess.h"

int main() {
    Board b = Board();
    Square& s1 = b.square_at("a4");
    Square& s2 = b.square_at(2, 3);
    Pawn p = Pawn(Piece::Color::white, s1);
    
    std::cout << b;
}

