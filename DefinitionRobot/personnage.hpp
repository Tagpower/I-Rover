#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>


class Personnage
{
private:
	int positionX;
	int positionY;
public:
	Personnage();
	int getPositionX;
	int getPositionY;
	void setPositionX;
	void setPositionY;
	void deplacer(int x, int y);
	void Combattre();
}
