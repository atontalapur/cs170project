#include "puzzle.h"
#include <iostream>
#include <string>

Puzzle::Puzzle() {
    std::cout << "Initialize the current state of the board by entering each row and hitting 'enter' after each row." << std::endl;
    std::cout << "Use '0' to represent the blank tile." << std::endl;
    fillTable();
}

void Puzzle::fillTable() {
    int a, b, c;
    std::cout << "Enter the first row: ";
    std::cin >> a >> b >> c;
    if (a < 0 || a > 8 || b < 0 || b > 8 || c < 0 || c > 8) {
        std::cerr << "Invalid input. Please enter numbers between 0 and 8." << std::endl;
        exit(1);
    }
    rowOne[0] = a;
    rowOne[1] = b;
    rowOne[2] = c;
    std::cout << "Enter the second row: ";
    std::cin >> a >> b >> c;
    if (a < 0 || a > 8 || b < 0 || b > 8 || c < 0 || c > 8) {
        std::cerr << "Invalid input. Please enter numbers between 0 and 8." << std::endl;
        exit(1);
    }
    rowTwo[0] = a;
    rowTwo[1] = b;
    rowTwo[2] = c;
    std::cout << "Enter the third row: ";
    std::cin >> a >> b >> c;
    if (a < 0 || a > 8 || b < 0 || b > 8 || c < 0 || c > 8) {
        std::cerr << "Invalid input. Please enter numbers between 0 and 8." << std::endl;
        exit(1);
    }
    rowThree[0] = a;
    rowThree[1] = b;
    rowThree[2] = c;
}

void Puzzle::printPuzzle() {
    std::cout << "[" << rowOne[0] << "," << rowOne[1] << "," << rowOne[2] << "]" << std::endl;
    std::cout << "[" << rowTwo[0] << "," << rowTwo[1] << "," << rowTwo[2] << "]" << std::endl;
    std::cout << "[" << rowThree[0] << "," << rowThree[1] << "," << rowThree[2] << "]" << std::endl;
}