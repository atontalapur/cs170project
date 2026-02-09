#include <vector>
using namespace std;


class Board {
    private:
        int board[3][3];
        vector <Board> children;

    public:
        Board();

        void fillTable();
        /**
         * Prints the current state of the 8-puzzle board.
         */
        void printPuzzle();
        /**
         * @return The number of misplaced tiles compared to the goal state.
         * @brief Calculates the number of tiles that are not in their goal position, excluding the blank tile (0). 
         */
};