#include "precomp.hpp"
#include "arme.h"
#include "ennemi.hpp"

#pragma once

class Mine : public Arme
{
private:
    int positionX;
    int positionY;
    clan::Image sprite;
public:
	Mine();
	Mine(int x, int y, clan::Image sprite);
	Mine(int x, int y, int puissance, std::string nom, clan::Image sprite);
	int getPositionX();
	int getPositionY();
	void setPositionX(int x);
	void setPositionY(int y);
	void exploser();
    void draw(clan::Canvas c, int x, int y);
};
