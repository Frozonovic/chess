/**
 * @file Board.h
 * @brief Declarations for the Board class
 *
 * @author Brody Lee (blee20@georgefox.edu)
 */
 

#ifndef BOARD_H
#define BOARD_H


#include <iostream>
#include "Square.h"


/**
 * @class Board
 * @brief Models a game board
 */
class Board {
  public:
    /** Dimensions of the board */
    static const size_t SIZE = 8;
    
    
    /**
     * @brief Initializes the internal state for a new board
     */
    Board();
    
    
    /**
     * @brief Fetches a square on the board given a rank and file
     *
     * @param rank Row the space is in
     * @param file Column the space is in
     * @return Square on the board
     */
    Square& square_at(size_t rank, size_t file) const;
    
    
    /**
     * @brief Fetches a square on the board given an identifier
     *
     * @param identifier String value consisting of a letter and number
     * @return Square on the board
     */
    Square& square_at(const std::string &identifier) const;
    
    
    /**
     * @brief Determines if two squares are in the same rank
     *
     * @param from First square for comparison
     * @param to Second square for comparison
     * @return True if in the same rank, else false
     */
    bool is_valid_rank(const Square& from, const Square& to) const;
    
    
    /**
     * @brief Determines if two squares are in the same file
     *
     * @param from First square for comparison
     * @param to Second square for comparison
     * @return
     */
    bool is_valid_file(const Square& from, const Square& to) const;
    
    
    /**
     * @brief Determines if two squares are in the same diagonal
     *
     * @param from First square for comparison
     * @param to Second square for comparison
     * @return True if in the same diagonal, else false
     */
    bool is_valid_diag(const Square& from, const Square& to) const;
    
    
    /**
     * @brief Determines if there is a piece between the two squares
     *
     * @param from First square for comparison
     * @param to Second square for comparison
     * @return True if nothing obstructs the rank path between the two squares, else false
     */
    bool is_clear_rank(const Square& from, const Square& to) const;
    
    
    /**
     * @brief Determines if there is a piece between the two squares
     *
     * @param from First square for comparison
     * @param to Second square for comparison
     * @return True if nothing obstructs the file path between the two squares, else false
     */
    bool is_clear_file(const Square& from, const Square& to) const;
    
    
    /**
     * @brief Determines if there is a piece between the two squares
     *
     * @param from First square for comparison
     * @param to Second square for comparison
     * @return True if nothing obstructs the diagonal path between the two squares, else false
     */
    bool is_clear_diag(const Square& from, const Square& to) const;
    
    
    /**
     * @brief Deconstructs the board
     */
    ~Board();
  
  private:
    /** List of all squares in the board */
    Square *_squares[SIZE][SIZE] = {};
};


/**
 * @brief Outputs the board contents to a designated stream
 *
 * @param os Stream output
 * @param board Board to output
 * @return Updated stream output
 */
std::ostream &operator<<(std::ostream& os, const Board& board);

#endif
