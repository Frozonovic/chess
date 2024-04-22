/**
 * @file Player.cpp
 * @brief Implementation for the Player class
 *
 * @author Brody Lee (blee20@georgefox.edu)
 */


#include "Player.h"


Player::Player(Piece::Color color, const Board &board) : _color(color), _board(board) {
   King *king;
   std::vector<Piece *> pieces;
   
   if (color == Piece::Color::black) {
      Square &black_king_square = board.square_at("e8");
      king = new King(color, black_king_square);
      
      for (int i = 0; i < 2; ++i) {
         for (int j = 0; j < Board::SIZE; ++j) {
            Square &square = board.square_at(i, j);
            Piece *piece;
            
            if (square.rank() == 0 && (square.file() == 0 || square.file() == 7)) {
               piece = new Rook(color, square);
            } else if (square.rank() == 0 && (square.file() == 1 || square.file() == 6)) {
               piece = new Knight(color, square);
            } else if (square.rank() == 0 && (square.file() == 2 || square.file() == 5)) {
               piece = new Bishop(color, square);
            } else if (square.rank() == 0 && square.file() == 3) {
               piece = new Queen(color, square);
            } else if (square.rank() == 0 && square.file() == 4) {
               piece = king;
            } else {
               piece = new Pawn(color, square);
            }
            
            piece->set_location(&square);
            pieces.push_back(piece);
         }
      }
   } else {
      Square &white_king_square = board.square_at("e1");
      king = new King(color, white_king_square);
      
      for (int i = 6; i < Board::SIZE; ++i) {
         for (int j = 0; j < Board::SIZE; ++j) {
            Square &square = board.square_at(i, j);
            Piece *piece;
            
            if (square.rank() == 7 && (square.file() == 0 || square.file() == 7)) {
               piece = new Rook(color, square);
            } else if (square.rank() == 7 && (square.file() == 1 || square.file() == 6)) {
               piece = new Knight(color, square);
            } else if (square.rank() == 7 && (square.file() == 2 || square.file() == 5)) {
               piece = new Bishop(color, square);
            } else if (square.rank() == 7 && square.file() == 3) {
               piece = new Queen(color, square);
            } else if (square.rank() == 7 && square.file() == 4) {
               piece = king;
            } else {
               piece = new Pawn(color, square);
            }
            
            piece->set_location(&square);
            pieces.push_back(piece);
         }
      }
   }
   
   this->_king = king;
   this->_pieces = pieces;
}


Piece::Color Player::color() const { return this->_color; }


bool Player::make_move(const std::string &from, const std::string &to) {
   bool move_completed;
   
   Square &from_square = this->_board.square_at(from);
   Square &to_square = this->_board.square_at(to);
   
   if (from_square.is_occupied()) {
      Piece *from_occupant = from_square.occupant();
      if (from_occupant->color() == this->_color) {
         if (to_square.is_occupied()) {
            Piece *to_occupant = to_square.occupant();
            
            if (to_occupant->color() != this->_color) {
               if (from_occupant->can_move_to(to_square)) {
                  if (_board.is_clear_rank(from_square, to_square) ||
                      _board.is_clear_file(from_square, to_square) ||
                      _board.is_clear_diag(from_square, to_square) ||
                      from_occupant->str() == "♞" || from_occupant->str() == "♘") {
                     move_completed = from_occupant->move_to(to_square);
                  } else {
                     // There is a piece blocking the path
                     move_completed = false;
                  }
               } else {
                  // This piece can't move to this location
                  move_completed = false;
               }
            } else {
               // Can't capture your own piece
               move_completed = false;
            }
         } else {
            if (from_occupant->can_move_to(to_square)) {
               move_completed = from_occupant->move_to(to_square);
            } else {
               // This piece can't move to this location
               move_completed = false;
            }
         }
      } else {
         // This piece does not belong to your team
         move_completed = false;
      }
   } else {
      // The chosen square does not have a piece on it
      move_completed = false;
   }
   
   return move_completed;
}


piece_value_t Player::piece_value() const {
   piece_value_t total = 0;
   
   for (auto piece: this->_pieces) {
      if (piece->is_on_square()) {
         total += piece->value();
      }
   }
   
   return total;
}


Player::~Player() {
   for (auto &_piece: _pieces) {
      delete _piece;
   }
}
