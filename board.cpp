#include "board.h"
#include <iostream>
#include <string>

Board::Board()
{
    fillTable();
    // TODO: initialize children vector
}

void Board::fillTable()
{

    int num = 0; // placeholder for user input
    int row = 0;
    int col = 0;
    int counter = 0;         // track the number of inputs to terminate the while loop
    vector<int> inputs = {}; // track the numbers that have been inputted to check for duplicates
    cout << "Start entering numbers for the board: " << endl;
    while (counter < 9)
    {
        cin >> num;
        if (num < 0 || num > 8)
        {
            cout << "Invalid input. Please enter a number between 0 and 8." << endl; // eight puzzle can only have numbers ranging from 0 to 8
            fillTable();
        }
        else if (find(inputs.begin(), inputs.end(), num) != inputs.end())
        {
            cout << "Invalid input. Please enter a number that has not been entered before." << endl; // each number can only be entered once
            fillTable();
        }
        else
        {
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

void Board::printPuzzle()
{
    cout << "CURR BOARD " << endl;
    for (int i = 0; i < 3; i++)
    { // Tracks the rows
        for (int j = 0; j < 3; j++)
        { // Prints all columns in the curr row
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}