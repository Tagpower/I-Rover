#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <math.h>
#include <ctime>
#include <cstdlib> 
#include <cstdio>
#include <vector>
#include "robot.hpp"
#include "ennemi.hpp"
#pragma once
using namespace std;




class node
{
   
    int xPos;
    int yPos;
	int level;
    int priority;  

    public:
		node();
        node(int xp, int yp, int l, int p);
    
        int getxPos()const ;
        int getyPos()const;
        int getLevel()const;
        int getPriority()const;

        void updatePriority(const int & xDest, const int & yDest);
        void nextLevel(const int & i);
        const int & estimate(const int & xDest, const int & yDest)const;
};


bool operator<(const node & a, const node & b);


std::string  pathFind( const int & xStart, const int & yStart, 
                 const int & xFinish, const int & yFinish, vector<vector<int> > collision_map );

