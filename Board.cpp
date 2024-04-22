/**
 * @file Board.cpp
 * @brief Implementation for the Board class
 *
 * @author Brody Lee (blee20@georgefox.edu)
 */


#include "Board.h"


Board::Board() {
   for (int i = 0; i < SIZE; ++i) {
      for (int j = 0; j < SIZE; ++j) {
         _squares[i][j] = new Square(i, j);
      }
   }
}


Square& Board::square_at(size_t rank, size_t file) const {
   return *(_squares[rank][file]);
}


Square& Board::square_at(const std::string& identifier) const {
   const char *chars = identifier.c_str();
   
   size_t rank = int('8') - int(chars[1]);
   size_t file = int(toupper(chars[0]) - int('A'));
   
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
   size_t to_file = to.file();
   
   size_t rank_diff;
   size_t file_diff;
   
   if (from_rank > to_rank) {
      rank_diff = from_rank - to_rank;
   } else {
      rank_diff = to_rank - from_rank;
   }
   
   if (from_file > to_file) {
      file_diff = from_file - to_file;
   } else {
      file_diff = to_file - from_file;
   }
   
   bool valid_from = 0 < from.file() && from.file() <= SIZE;
   bool valid_to = 0 < to.file() && to.file() <= SIZE;
   bool valid_diag = rank_diff == file_diff;
   
   return valid_from && valid_to && valid_diag;
}


bool Board::is_clear_rank(const Square& from, const Square& to) const {
   size_t start;
   size_t end;
   size_t rank = from.rank();
   
   if (from.file() > to.file()) {
      start = to.file() + 1;
      end = from.file();
   } else {
      start = from.file() + 1;
      end = to.file();
   }
   
   bool no_obstructions = true;
   
   while (start < end && no_obstructions) {
      Square& square = square_at(rank, start);
      
      if (square.is_occupied()) {
         no_obstructions = false;
      }
      
      start++;
   }
   
   return no_obstructions;
}


bool Board::is_clear_file(const Square& from, const Square& to) const {
   size_t start;
   size_t end;
   size_t file = from.file();
   
   if (from.rank() > to.rank()) {
      start = to.rank() + 1;
      end = from.rank();
   } else {
      start = from.rank() + 1;
      end = to.rank();
   }
   
   bool no_obstructions = true;
   
   while (start < end && no_obstructions) {
      Square& square = square_at(start, file);
      
      if (square.is_occupied()) {
         no_obstructions = false;
      }
      
      start++;
   }
   
   return no_obstructions;
}


bool Board::is_clear_diag(const Square& from, const Square& to) const {
   size_t rank_start = from.rank();
   size_t rank_end = to.rank();
   size_t file_start = from.file();
   size_t file_end = to.file();
   
   bool no_obstructions = true;
   
   if (from.rank() > to.rank() && from.file() > to.file()) {
      rank_start--;
      file_start--;
      
      while (rank_start > rank_end && file_start > file_end && no_obstructions) {
         Square& square = square_at(rank_start, file_start);
         
         if (square.is_occupied()) {
            no_obstructions = false;
         }
         
         rank_start--;
         file_start--;
      }
   } else if (from.rank() > to.rank() && from.file() < to.rank()) {
      rank_start--;
      file_start++;
      
      while (rank_start > rank_end && file_start < file_end && no_obstructions) {
         Square& square = square_at(rank_start, file_start);
         
         if (square.is_occupied()) {
            no_obstructions = false;
         }
         
         rank_start--;
         file_start++;
      }
   } else if (from.rank() < to.rank() && from.file() > to.file()) {
      rank_start++;
      file_start--;
      
      while (rank_start < rank_end && file_start > file_end && no_obstructions) {
         Square& square = square_at(rank_start, file_end);
         
         if (square.is_occupied()) {
            no_obstructions = false;
         }
         
         rank_start++;
         file_end--;
      }
   } else if (from.rank() < to.rank() && from.file() < to.file()) {
      rank_start++;
      file_end++;
      
      while (rank_start < rank_end && file_start < file_end && no_obstructions) {
         Square& square = square_at(rank_start, file_end);
         
         if (square.is_occupied()) {
            no_obstructions = false;
         }
         
         rank_start++;
         file_end++;
      }
   }
   
   return no_obstructions;
}


Board::~Board() {
   for (int i = 0; i < SIZE; ++i) {
      for (int j = 0; j < SIZE; ++j) {
         delete _squares[i][j];
         _squares[i][j] = nullptr;
      }
   }
}


std::ostream& operator<<(std::ostream& os, const Board &board) {
   char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
   
   os << " ";
   
   for (auto letter : letters) {
      os << "   " << letter;
   }
   
   os << "\n  ┌───┬───┬───┬───┬───┬───┬───┬───┐\n";
   
   for (int i = 0; i < (Board::SIZE * 2) - 1; ++i) {
      if (i % 2 != 0) {
         os << "  ├───┼───┼───┼───┼───┼───┼───┼───┤\n";
      } else {
         os << std::to_string(Board::SIZE - (i / 2)) << " │";
      }
      for (int j = 0; j < Board::SIZE; ++j) {
         if (i % 2 == 0 && i < (Board::SIZE * 2) + 1) {
            Square& square = board.square_at(i / 2, j);
            
            os << square << "│";
         }
      }
      
      if (i % 2 == 0) {
         os << " " << std::to_string(Board::SIZE - (i / 2)) << "\n";
      }
   }
   
   os << "  └───┴───┴───┴───┴───┴───┴───┴───┘\n ";
   
   for (auto letter : letters) {
      os << "   " << letter;
   }
   
   os << std::endl;
   
   return os;
}