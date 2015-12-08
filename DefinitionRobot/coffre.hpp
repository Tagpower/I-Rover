#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>


class Coffre
{
private:
	int positionX;
	int positionY;
	bool ouvert;
public:
	Coffre();
	Coffre(int positionX, int positionY);
	int getPositionX();
	int getPositionY();
	bool isOuvert();
	void setPositionX(int x);
	void setPositionY(int y);
	void setOuvert(bool status);

};
