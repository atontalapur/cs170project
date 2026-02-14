#ifndef SEARCH_H
#define SEARCH_H

#include "board.h"
#include <iostream>
#include <vector>
#include <queue>

struct Node
{
    Board board;
    Node *parent;
    int gCost; // Cost from the start node to the current node
    int hCost; // Heuristic cost from the current node to the goal
    int fCost; // Total cost (gCost + hCost)

    Node(Board b, Node *p, int g, int h)
    {
        board = b;
        parent = p;
        gCost = g;
        hCost = h;
        fCost = gCost + hCost;
    }
};

struct CompareNode
{
    bool operator()(Node *a, Node *b)
    {
        return a->fCost > b->fCost;
    }
};

class Search
{
private:
    int visitedNodes;
    int depth;
    int time;

public:
    Search();

    bool generalSearch(Board rootBoard, int queueingFunction);
    bool checkTerminalState(Board board);
    int getHeuristicCost(Board board, int heuristicType);
    int getMisplacedTileCost(Board board);
    int getManhattanDistanceCost(Board board);
    void expand(Node *node, priority_queue<Node *, vector<Node *>, CompareNode> &nodes, vector<Node *> &visited, int queueingFunction);
    bool isVisited(Board board, vector<Node *> &visited);

    int getVisitedNodes()
    {
        return visitedNodes;
    }

    int getDepth()
    {
        return depth;
    }

    int getTime()
    {
        return time;
    }

    void setVisitedNodes(int nodes)
    {
        visitedNodes = nodes;
    }

    void setDepth(int d)
    {
        depth = d;
    }

    void setTime(int t)
    {
        time = t;
    }
};

#endif