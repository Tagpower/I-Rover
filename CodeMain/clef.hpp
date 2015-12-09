#include "precomp.hpp"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>


class Clef
{
private:
	int positionX;
	int positionY;
    clan::Image sprite;
public:
	Clef();
	Clef(int positionX, int positionY, clan::Image sprite);
	int getPositionX();
	int getPositionY();
	void setPositionX(int x);
	void setPositionY(int y);
    void draw(clan::Canvas c, int x, int y);
};
