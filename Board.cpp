/**
 * @file Board.cpp
 * @brief Implementation for the Board class
 *
 * @author Brody Lee (blee20@georgefox.edu)
 */


#include "Board.h"
#include "Piece.h"


Board::Board() {
  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      Square square = Square(i, j);
      
      _squares[i][j] = &square;
    }
  }
}


Square& Board::square_at(size_t rank, size_t file) const {
  bool valid_rank = 0 < rank && rank <= SIZE;
  bool valid_file = 0 < rank && rank <= SIZE;
  
  if (valid_rank && valid_file) {
    return *(_squares[file - 1][rank - 1]);
  }
}


Square& Board::square_at(const std::string& identifier) const {
  const char *chars = identifier.c_str();
  
  size_t rank = int(toupper(chars[0]) - int('A') + 1);
  size_t file = ((int('1') - int(chars[1])) + 7) + 1;
  
  return square_at(rank, file);
}


bool Board::is_valid_rank(const Square& from, const Square& to) const {
  bool valid_from = 0 < from.rank() && from.rank() <= SIZE;
  bool valid_to = 0 < to.rank() && to.rank() <= SIZE;
  bool valid_rank = from.rank() == to.rank();
  
  return valid_from && valid_to && valid_rank;
}


bool Board::is_valid_file(const Square& from, const Square& to) const {
  bool valid_from = 0 < from.file() && from.file() <= SIZE;
  bool valid_to = 0 < to.file() && to.file() <= SIZE;
  bool valid_file = from.file() == to.file();
  
  return valid_from && valid_to && valid_file;
}


bool Board::is_valid_diag(const Square& from, const Square& to) const {
  size_t from_rank = from.rank();
  size_t to_rank = to.rank();
  size_t from_file = from.file();
  size_t to_file = from.file();
  
  bool valid_from = 0 < from.file() && from.file() <= SIZE;
  bool valid_to = 0 < to.file() && to.file() <= SIZE;
  bool valid_diag = (from_rank + from_file) - (to_rank + to_file) == 0;
  
  return valid_from && valid_to && valid_diag;
}


bool Board::is_clear_rank(const Square& from, const Square& to) const {
  return is_valid_rank(from, to) && !from.is_occupied() && !from.is_occupied();
}


bool Board::is_clear_file(const Square& from, const Square& to) const {
  return is_valid_file(from, to) && !from.is_occupied() && !to.is_occupied();
}


bool Board::is_clear_diag(const Square& from, const Square& to) const {
  return is_valid_diag(from, to) && !to.is_occupied();
}


Board::~Board() {
  for (auto& section : _squares) {
    for (auto subsect : section) {
      delete subsect;
    }
  }
}


std::ostream& operator<<(std::ostream& os, const Board& board) {
  os << "   a   b   c   d   e   f   g   h\n";
  os << "  ┌───┬───┬───┬───┬───┬───┬───┬───┐\n";
  
  for (int i = 0; i < Board::SIZE; ++i) {
    os << std::to_string(Board::SIZE - i);
    for (int j = 0; j < Board::SIZE; ++j) {
      Square& square = board.square_at(j, i);
      
      os << "  │";
      os << square;
    }
    os << "│ ";
    os << std::to_string(Board::SIZE - i);
    os << "\n";
    if (i != 7) {
      os << "├───┼───┼───┼───┼───┼───┼───┼───┤\n";
    } else {
      os << "└───┴───┴───┴───┴───┴───┴───┴───┘\n";
    }
  }
  
  return os;
}