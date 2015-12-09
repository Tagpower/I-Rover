#include "precomp.hpp"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "clef.hpp"

#pragma once

class Personnage
{
protected:
	int positionX;
	int positionY;
    clan::Image sprite;
public:
	Personnage();
	Personnage(int positionX, int positionY, clan::Image sprite);
	int getPositionX();
	int getPositionY();
	void setPositionX(int x);
	void setPositionY(int y);
	void deplacer(int x, int y);
	bool Combattre(Personnage* adversaire);
    void draw(clan::Canvas c, int x, int y);
};
