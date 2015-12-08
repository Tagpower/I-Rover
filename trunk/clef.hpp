#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>


class Clef
{
private:
	int positionX;
	int positionY;
public:
	Clef();
	Clef(int positionX, int positionY);
	int getPositionX();
	int getPositionY();
	void setPositionX(int x);
	void setPositionY(int y);
};
