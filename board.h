#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <array>
#include <iostream>
using namespace std;

class Board
{
private:
    array<array<int, 3>, 3> board;
    vector<Board> children;
    int numInversions;

public:
    Board();
    /**
     * Fills the 8-puzzle board with user input.
     */
    bool fillTable();
    /**
     * Prints the current state of the 8-puzzle board.
     */
    void printPuzzle();

    int getBoardValue(int row, int col)
    {
        return board[row][col];
    }

    const array<array<int, 3>, 3> &getBoard() const
    {
        return board;
    }

    void setBoardValue(int row, int col, int value)
    {
        board[row][col] = value;
    }

    vector<Board> getChildren()
    {
        return children;
    }

    void setChildren();

    void printChildren();

    string toString();

    bool isValid(vector<int> inputs);
};

#endif