#include <iostream>
#include "board.h"
#include "search.h"

void displayInstructions()
{
    cout << "=======INSTRUCTIONS BEGINS=======" << endl;
    cout << "Initialize the current state of the board by entering all the numbers and hitting 'enter' after each number." << endl;
    cout << "Use '0' to represent the blank tile." << endl;
    string example[3][3] = {
        {"1", "2", "3"},
        {"4", "5", "6"},
        {"7", "8", "0"}};

    cout << "For example, the input for the board below would look like: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << example[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 1; i < 9; i++)
    {
        cout << i << endl;
    }
    cout << 0 << endl
         << "=======INSTRUCTIONS ENDS=======" << endl;
}

int userSearchChoice()
{
    int choice = 0;
    cout << "Enter 1 to choose Uniform Cost, 2 for A* with the Misplaced Tile heuristic, and 3 for A* with the Manhattan Distance heuristic." << endl;
    cin >> choice;
    if (choice)
    {
        if (choice < 1 || choice > 3)
        {
            cout << "Invalid input. Please enter a number between 1 and 3." << endl;
            return userSearchChoice();
        }
        else
        {
            return choice;
        }
    }
    else
    {
        cout << "Invalid input. Please enter a number between 1 and 3." << endl;
        return userSearchChoice();
    }
}

bool handleSearch(int choice, Board b)
{
    if (choice < 1 || choice > 3)
    {
        cout << "Invalid input. Please enter a number between 1 and 3." << endl;
        return handleSearch(userSearchChoice(), b);
    }
    Search search;
    if (choice == 1)
    {
        cout << "Uniform Cost Search selected." << endl; // TODO: Implement uniform cost search
        return search.generalSearch(b, 1);
    }
    else if (choice == 2)
    {
        cout << "A* with the Misplaced Tile heuristic selected." << endl; // TODO: Implement A* with the Misplaced Tile heuristic
        return search.generalSearch(b, 2);
    }
    else
    {
        cout << "A* with the Manhattan Distance heuristic selected." << endl; // TODO: Implement A* with the Manhattan Distance heuristic
        return search.generalSearch(b, 3);
    }
}

int main()
{
    displayInstructions();
    Board board;
    board.fillTable();
    board.printPuzzle();
    handleSearch(userSearchChoice(), board);
}
