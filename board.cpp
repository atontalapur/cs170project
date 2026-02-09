#include "board.h"
#include <iostream>
#include <string>

Board::Board() {
    fillTable();
}

void Board::fillTable() {
    int num = 0; // placeholder for user input
    int row = 0;
    int col = 0;
    int counter = 0; // track the number of inputs to terminate the while loop
    cout << "Start entering numbers for the board: " << endl;
    while (counter < 9) {
        cin >> num;
        if (num < 0 || num > 8 ) {
            cout << "Invalid input. Please enter a number between 0 and 8." << endl; // eight puzzle can only have numbers ranging from 0 to 8
        } else {
            board[row][col] = num; // fill the respective position with the user input
            col++;
            if (col == 3) { // If the column index reaches 3 (furthest right), reset it to 0 to start filling from the left in the next row again.
                col = 0;
                row++; // Move to the next row
            }
        }
    counter++;
    }
}

void Board::printPuzzle() {
    cout << "CURR BOARD " << endl;
   for (int i = 0; i < 3; i++) { // Tracks the rows
        for (int j = 0; j < 3; j++) { // Prints all columns in the curr row
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}