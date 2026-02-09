#include <vector>
using namespace std;


class Board {
    private:
        int board[3][3];
        vector <Board> children;

    public:
        Board();
        /**
         * Fills the 8-puzzle board with user input. 
         */
        void fillTable();
        /**
         * Prints the current state of the 8-puzzle board.
         */
        void printPuzzle();
        
};