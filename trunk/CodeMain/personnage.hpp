#include "precomp.hpp"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "clef.hpp"

#pragma once

using namespace std;

class Personnage
{
protected:
	int positionX;
	int positionY;
        clan::Image sprite;
        vector<vector<int>> collision_map;
public:
	Personnage();
	Personnage(int positionX, int positionY, clan::Image sprite);
	int getPositionX();
	int getPositionY();
	void setPositionX(int x);
	void setPositionY(int y);
        void setCollisionMap(vector<vector<int>> map);
	void deplacer(int x, int y);
	bool Combattre(Personnage* adversaire);
        void draw(clan::Canvas c, int x, int y);
};