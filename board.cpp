#include "board.h"
#include <iostream>
#include <string>

Board::Board() {
    fillTable();
}

void Board::fillTable() {
    int num = 0;
    int row = 0;
    int col = 0;
    int counter = 0;
    cout << "Start entering numbers for the board: " << endl;
    while (counter < 9) {
        cin >> num;
        if (num < 0 || num > 8 ) {
            cout << "Invalid input. Please enter a number between 0 and 8." << endl;
        } else {
            board[row][col] = num;
            col++;
            if (col == 3) {
                col = 0;
                row++;
            }
        }
    counter++;
    }
}

void Board::printPuzzle() {
    cout << "CURR BOARD " << endl;
   for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}