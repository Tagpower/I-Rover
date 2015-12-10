#include "precomp.hpp"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#pragma once

class Coffre
{
private:
	int positionX;
	int positionY;
	bool ouvert;
        clan::Image sprite;
public:
	Coffre();
	Coffre(int positionX, int positionY, clan::Image sprite);
	int getPositionX();
	int getPositionY();
	bool isOuvert();
	void setPositionX(int x);
	void setPositionY(int y);
	void setOuvert(bool status);
        void draw(clan::Canvas c, int x, int y);

};
