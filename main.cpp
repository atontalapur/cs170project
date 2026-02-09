#include <iostream>
#include "board.h"


void instructions() {
    cout << "=======INSTRUCTIONS BEGINS=======" << endl;
    cout << "Initialize the current state of the board by entering all the numbers and hitting 'enter' after each number." << endl;
    cout << "Use '0' to represent the blank tile." << endl;
    string example[3][3] = {
    { "1", "2", "3" },
    { "4", "5", "6" },
    { "7", "8", "0" }
    };

    cout << "For example, the input for the board below would look like: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << example[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 1; i < 9; i ++){
        cout << i << endl;
    }
    cout << 0 << endl << "=======INSTRUCTIONS ENDS=======" << endl;
}


int main() {
    instructions();
    Board board;
    board.printPuzzle();
    
}

