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
   size_t turn_counter = 0;
   
   // Create the board
   Board board = Board();
   
   // Create the players
   Player white_player = Player(Piece::Color::white, board);
   Player black_player = Player(Piece::Color::black, board);
   
   while (turn_counter < 20) {
      std::string desired_move;
      std::vector<std::string> tokens;
      bool move_completed;
      
      // Print board
      std::cout << board << std::endl;
      
      if (turn_counter % 2 == 0) {
         // White goes on even numbers
         std::cout << "White's turn! Where would you like to move?" << std::endl;
         getline(std::cin, desired_move);
         
         // Tokenize input
         tokenizer(tokens, desired_move, ' ');
         
         // Attempt to make the move
         move_completed = white_player.make_move(tokens[0], tokens[1]);
         
         if (move_completed) {
            turn_counter++;
         } else {
            std::cout << "Illegal movement. Please try again." << std::endl;
         }
      } else {
         // Black goes on odd numbers
         std::cout << "Black's turn! Where would you like to move?" << std::endl;
         getline(std::cin, desired_move);
         
         // Tokenize input
         tokenizer(tokens, desired_move, ' ');
         
         // Attempt to make the move
         move_completed = black_player.make_move(tokens[0], tokens[1]);
         
         if (move_completed) {
            turn_counter++;
         } else {
            std::cout << "Illegal movement. Please try again." << std::endl;
         }
      }
   }
}


void tokenizer(std::vector<std::string> &buffer, const std::string &s, const char delimiter) {
   std::stringstream ss(s);
   std::string token;
   while (!ss.eof()) {
      getline(ss, token, delimiter);
      buffer.push_back(token);
   }
}
