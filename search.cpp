#include "search.h"
#include "board.h"
#include <iostream>
#include <vector>
#include <queue>
#include <chrono>

using namespace std::chrono;

Search::Search()
{
    visitedNodes = 0;
    depth = 0;
    time = 0;
}

int Search::getHeuristicCost(Board board, int heuristicType)
{
    if (heuristicType == 2)
    {
        return getMisplacedTileCost(board);
    }
    else if (heuristicType == 3)
    {
        return getManhattanDistanceCost(board);
    }
    return 0;
}

int Search::getMisplacedTileCost(Board board)
{
    vector<std::vector<int>> terminalState = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}};

    int misplacedTiles = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board.getBoardValue(i, j) != 0 && (board.getBoardValue(i, j) != terminalState[i][j]))
            {
                misplacedTiles++;
            }
        }
    }
    return misplacedTiles;
}

int Search::getManhattanDistanceCost(Board board)
{
    vector<std::vector<int>> terminalState = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}};

    int manhattanDistance = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int value = board.getBoardValue(i, j);
            if (value != 0) // Skip the blank tile
            {
                int targetRow = (value - 1) / 3;
                int targetCol = (value - 1) % 3;
                manhattanDistance += abs(i - targetRow) + abs(j - targetCol);
            }
        }
    }
    return manhattanDistance;
}

bool Search::generalSearch(Board rootBoard, int queueingFunction)
{
    auto start = high_resolution_clock::now(); // Track how long the search takes


    vector<Node *> visited; // track the nodes that have been visited
    priority_queue<Node *, vector<Node *>, CompareNode> nodes; // MaxHeap cturned into minHeap by CompareNode struct
    int heuristicCost = getHeuristicCost(rootBoard, queueingFunction); // determine which search to do
    cout << "Heuristic cost of the root node: " << heuristicCost << endl;

    Node *root = new Node(rootBoard, nullptr, 0, heuristicCost);// create the root node with gCost = 0 and hCost = heuristic cost of the root board
    nodes.push(root);

    while (nodes.empty() == false)
    {
        if ((int)(nodes.size()) > depth) // update depth of the solution
        {
            setDepth((int)(nodes.size()));
        }

        Node *currNode = nodes.top(); // get the node with the lowest fCost
        nodes.pop();

        if (checkTerminalState(currNode->board)) // Terminal test
        {
            cout << "Goal state reached!" << endl;
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<seconds>(end - start);
            setTime(duration.count());
            return true;
        }

        visited.push_back(currNode); // Explored node pushed to array
        visitedNodes++; 

        // TODO: Generate children and expand them
    }


    return false;
}

bool Search::checkTerminalState(Board board)
{
    vector<std::vector<int>> terminalState = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board.getBoardValue(i, j) != 0 && (board.getBoardValue(i, j) != terminalState[i][j]))
            {
                return false;
            }
        }
    }
    return true;
}
