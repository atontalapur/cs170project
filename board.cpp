#include "board.h"
#include <iostream>
#include <string>
using namespace std;
Board::Board()
{
    children = {};
}

void Board::fillTable()
{

    int num = 0; // placeholder for user input
    int row = 0;
    int col = 0;
    int counter = 0; // track the number of inputs to terminate the while loop
    int numInversions = 0;
    vector<int> inputs = {}; // track the numbers that have been inputted to check for duplicates
    cout << "Start entering numbers for the board: " << endl;
    while (counter < 9)
    {
        cin >> num;
        if ((num < 0 || num > 8) || !num)
        {
            cout << "Invalid input. Please enter a number between 0 and 8." << endl; // eight puzzle can only have numbers ranging from 0 to 8
            exit(1);
        }
        else if (find(inputs.begin(), inputs.end(), num) != inputs.end())
        {
            cout << "Invalid input. Please enter a number that has not been entered before." << endl; // each number can only be entered once
            exit(1);
        }
        else

        {
            if (counter > 0 && (inputs[counter] < inputs[counter - 1]))
            {
                this->numInversions++;
            }
            board[row][col] = num; // fill the respective position with the user input
            inputs.push_back(num);
            col++;
            if (col == 3)
            { // If the column index reaches 3 (furthest right), reset it to 0 to start filling from the left in the next row again.
                col = 0;
                row++; // Move to the next row
            }
            counter++;
        }
    }
}
// void Board::printPuzzle()
// {
//     for (int i = 0; i < 3; i++)
//     { // Tracks the rows
//         for (int j = 0; j < 3; j++)
//         { // Prints all columns in the curr row
//             cout << board[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

void Board::setChildren()
{
    int blankRow = 0;
    int blankCol = 0;
    // board[blankRow][blankCol] == 0, so we find the position of the blank(0) tile.
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == 0)
            {
                blankRow = i;
                blankCol = j;
            }
        }
    }

    // If increasing one row of the location of '0' does not exceed the bounds, there is a
    // valid move down.
    if (blankRow + 1 < 3)
    {
        Board child = *this;
        swap(child.board[blankRow][blankCol], child.board[blankRow + 1][blankCol]);
        children.push_back(child);
    }
    // If decreasing one row of the location of '0' does not exceed the bounds, there is a
    // valid move up.
    if (blankRow - 1 >= 0)
    {
        Board child = *this;
        swap(child.board[blankRow][blankCol], child.board[blankRow - 1][blankCol]);
        children.push_back(child);
    }
    // If increasing one column of the location of '0' does not exceed the bounds, there is a
    // valid move right.
    if (blankCol + 1 < 3)
    {
        Board child = *this;
        swap(child.board[blankRow][blankCol], child.board[blankRow][blankCol + 1]);
        children.push_back(child);
    }
    // If decreasing one column of the location of '0' does not exceed the bounds, there is a
    // valid move left.
    if (blankCol - 1 >= 0)
    {
        Board child = *this;
        swap(child.board[blankRow][blankCol], child.board[blankRow][blankCol - 1]);
        children.push_back(child);
    }
}

// void Board::printChildren()
// {
//     int count = 1;
//     for (Board& child : children)
//     {
//         cout << "Child " << count << ":" << endl;
//         child.printPuzzle();
//         count++;
//     }
// }

string Board::toString()
{
    string boardString = "";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            boardString += to_string(board[i][j]) + " ";
        }
    }
    return boardString;
}

bool Board::isValid()
{
    return this->numInversions % 2 == 0;
}