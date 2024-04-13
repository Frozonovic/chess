/**
 * @file Chess.cpp
 * @brief Implementation for playing a proper chess game
 *
 * @author Brody Lee (blee20@georgefox.edu)
 */


#include "Chess.h"


/**
 * @brief Simulates a chess game
 *
 * @return 0 on success, else non-zero on failure
 */
int main() {
   Board b = Board();
   Square& a4 = b.square_at("a4");
   Square& a5 = b.square_at("a5");
   Square& b4 = b.square_at("b4");
   Square& c6 = b.square_at("c6");
   
   Pawn p = Pawn(Piece::Color::white, a4);
   Queen q = Queen(Piece::Color::white, c6);
   
   std::ostream& o = std::cout;
   o << b << std::endl;
   o << b.is_valid_rank(a4, b4) << std::endl;
   o << b.is_valid_file(a4, a5) << std::endl;
   o << b.is_valid_diag(a4, c6) << std::endl;
}

