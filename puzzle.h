class Puzzle {
    private:
        int rowOne[3];
        int rowTwo[3];
        int rowThree[3];
    
    public:
        Puzzle();
        void fillTable();

        /**
         * Prints the current state of the 8-puzzle board.
         */
        void printPuzzle();
        /**
         * @return The number of misplaced tiles compared to the goal state.
         * @brief Calculates the number of tiles that are not in their goal position, excluding the blank tile (0). 
         */
        int misplacedTilesHeuristic();
};