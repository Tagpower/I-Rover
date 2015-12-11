#include "precomp.hpp"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "clef.hpp"
#include "arme.h"
#include "armure.h"

#pragma once

using namespace std;

class Personnage
{
protected:
	int positionX;
	int positionY;
	int puissance;
	int robustesse;
	bool isActive;
    clan::Image sprite;
    vector<vector<int> > collision_map;
    Arme arme;
    Armure armure;
public:
	Personnage();
	Personnage(int positionX, int positionY, Arme arme, Armure armure, clan::Image sprite);
	int getPositionX();
	int getPositionY();
	int getPuissance();
	int getRobustesse();
        Arme getArme();
        Armure getArmure();
	void setPositionX(int x);
	void setPositionY(int y);
	void setPuissance(int puissance);
	void setRobustesse(int robustesse);
        void setCollisionMap(vector<vector<int> > map);
        void setArme(Arme arme);
        void setArmure(Armure armure);
	void deplacer(int x, int y);
	bool Combattre(Personnage* adversaire);
        void draw(clan::Canvas c, int x, int y);
        void setActive(bool active);
	bool getIsActive();
};
