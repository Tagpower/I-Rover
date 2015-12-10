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
	bool isActive;
    clan::Image sprite;
    vector<vector<int> > collision_map;
public:
	Personnage();
	Personnage(int positionX, int positionY, int puissance, clan::Image sprite);
	int getPositionX();
	int getPositionY();
	int getPuissance();
	void setPositionX(int x);
	void setPositionY(int y);
	void setPuissance(int puissance);
    void setCollisionMap(vector<vector<int> > map);
	void deplacer(int x, int y);
	bool Combattre(Personnage* adversaire);
    void draw(clan::Canvas c, int x, int y);
    void setActive();
	void setInactive();
	bool getIsActive();
};
