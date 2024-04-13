/**
 * @file Player.h
 * @brief Declarations for the Player class
 *
 * @author Brody Lee (blee20@georgefox.edu)
 */


#ifndef PLAYER_H
#define PLAYER_H


#include <cstdlib>
#include <vector>
#include <string>
#include "Board.h"
#include "Piece.h"
#include "King.h"


/**
 * @class Player
 * @brief Models a player of a board game
 */
class Player {
   public:
      /**
       * @brief Initializes the internal state of the player
       *
       * @param color Color of the player's team
       * @param board Board the player will use
       */
      Player(Piece::Color color, const Board& board);
      
      
      /**
       * @brief Fetches the team color for the player
       *
       * @return Team color of the player
       */
      Piece::Color color() const;
      
      
      /**
       * @brief Proposes a move from one square to another
       *
       * @param from Departure square
       * @param to Arrival square
       * @return True if move is possible, else false
       */
      bool make_move(const std::string& from, const std::string& to);
      
      
      /**
       * @brief Fetches the value of a piece
       *
       * @return Value of the given piece
       */
      piece_value_t piece_value() const;
      
      
      /**
       * @brief Deconstructs a player object
       */
      ~Player();
   
   private:
      /** Team color of the player */
      const Piece::Color _color;
      
      
      /** Board the game is taking place on */
      const Board& _board;
      
      
      /** List of the player's pieces */
      std::vector<Piece*> _pieces;
      
      
      /** The player's King */
      King* _king;
};


#endif

