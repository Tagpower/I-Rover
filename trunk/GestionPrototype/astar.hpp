#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <math.h>
#include <ctime>
#include <cstdlib> 
#include <cstdio>
#include <vector>
#pragma once
using namespace std;




class node
{
    // current position
    int xPos;
    int yPos;
    // total distance already travelled to reach the node
    int level;
    // priority=level+remaining distance estimate
    int priority;  // smaller: higher priority

    public:
		node();
        node(int xp, int yp, int d, int p);
    
        int getxPos()const ;
        int getyPos()const;
        int getLevel()const;
        int getPriority()const;

        void updatePriority(const int & xDest, const int & yDest);

        // give better priority to going strait instead of diagonally
        void nextLevel(const int & i);
        
        // Estimation function for the remaining distance to the goal.
        const int & estimate(const int & xDest, const int & yDest)const;
};

// Determine priority (in the priority queue)
bool operator<(const node & a, const node & b);

// A-star algorithm.
// The route returned is a string of direction digits.
std::string  pathFind( const int & xStart, const int & yStart, 
                 const int & xFinish, const int & yFinish, vector<vector<int> > collision_map );

