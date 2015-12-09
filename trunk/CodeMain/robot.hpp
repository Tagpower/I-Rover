#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "personnage.hpp"
#include "coffre.hpp"


class Robot : public Personnage
{
private:
	int inventaire;
public:
	Robot();
	Robot(int positionX,int positionY);
	int getInventaire();
	void setInventaire(int inventaire);
	void ouvrir(Coffre* coffre);
	void ramasser(Clef* clef);
};
