#include "search.h"
#include "board.h"
#include <iostream>
#include <vector>
#include <queue>
#include <chrono>
#include <algorithm>
#include <iomanip>

using namespace std::chrono;

Search::Search()
{
    visitedNodes = 0;
    depth = 0;
    time = 0;
}

int Search::getHeuristicCost(Board board, int heuristicType)
{
    if (heuristicType == 1)
    {
        return 0; // Uniform Cost Search has no heuristic cost
    }
    else if (heuristicType == 2)
    {
        return getMisplacedTileCost(board);
    }
    return getManhattanDistanceCost(board);
}

int Search::getMisplacedTileCost(Board board)
{
    vector<std::vector<int>> terminalState = {// Goal State
                                              {1, 2, 3},
                                              {4, 5, 6},
                                              {7, 8, 0}};

    int misplacedTiles = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board.getBoardValue(i, j) != 0 && (board.getBoardValue(i, j) != terminalState[i][j])) // If the value is not 0, and at a given position, the value is different than the goal state
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

    vector<Node *> visited;                                            // track the nodes that have been visited
    priority_queue<Node *, vector<Node *>, CompareNode> nodes;         // MaxHeap cturned into minHeap by CompareNode struct
    int heuristicCost = getHeuristicCost(rootBoard, queueingFunction); // determine which search to do
    // cout << "Heuristic cost of the root node: " << heuristicCost << endl;

    Node *root = new Node(rootBoard, nullptr, 0, heuristicCost); // create the root node with gCost = 0 and hCost = heuristic cost of the root board
    nodes.push(root);
    auto start = high_resolution_clock::now(); // store the start time

    while (nodes.empty() == false)
    {
        if ((int)(nodes.size()) > depth) // update depth of the solution
        {
            setDepth((int)(nodes.size() - 1));
        }

        Node *currNode = nodes.top(); // get the node with the lowest fCost
        nodes.pop();
        // TA REMARKS: display g(n) and h(n) of the current node
        // TA REMARKS: End should have g(n) - d and small h(n)

        cout << "Current g(n): " << currNode->gCost << " Current h(n): " << currNode->hCost << endl;
        // TA REMARK: TODO: Solution Depth, Number of nodes expanded, max queue size
        if (checkTerminalState(currNode->board)) // Terminal test
        {
            cout << "Goal state reached!" << endl;
            auto end = high_resolution_clock::now(); // store the end time
            setTime(duration_cast<microseconds>(end - start).count());
            cout << "Solution Depth: " << currNode->gCost << endl;
            cout << "Number of nodes expanded: " << getVisitedNodes() << endl;
            cout << "Max queue size: " << (int)(nodes.size()) << endl;
            cout << "Time taken: " << setprecision(7) << getTime() / 1000000.0 << " seconds" << endl;
            return true; // we found the goal state in our search
        }

        visited.push_back(currNode); // Explored node pushed to array
        visitedNodes++;

        currNode->board.setChildren(); // find all the next possible moves and save them as children
        // currNode->board.printChildren();
        expand(currNode, nodes, visited, queueingFunction); // analyze which children node takes us closer to goal state
    }
    cout << "Solution not found." << endl;
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

void Search::expand(Node *node, priority_queue<Node *, vector<Node *>, CompareNode> &nodes, vector<Node *> &visited, int queueingFunction)
{
    for (Board child : node->board.getChildren())
    {
        if (!isVisited(child, visited))
        {

            int gCost = node->gCost + 1;                           // Increment gCost by 1 for each move
            int hCost = getHeuristicCost(child, queueingFunction); // Get the heuristic cost of the child node
            Node *childNode = new Node(child, node, gCost, hCost); // Create a new node for the child
            nodes.push(childNode);
            
        }
    }
}

bool Search::isVisited(Board board, vector<Node *> &visited)
{
    string boardState = board.toString();
    for (Node *node : visited)
    {
        if (node->board.toString() == boardState)
        {
            return true;
        }
    }
    return false;
}