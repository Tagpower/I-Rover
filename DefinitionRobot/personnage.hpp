#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "clef.hpp"


class Personnage
{
protected:
	int positionX;
	int positionY;
public:
	Personnage();
	Personnage(int positionX, int positionY);
	int getPositionX();
	int getPositionY();
	void setPositionX(int x);
	void setPositionY(int y);
	void deplacer(int x, int y);
	bool Combattre(Personnage* adversaire);
};
