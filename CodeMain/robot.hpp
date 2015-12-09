#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "personnage.hpp"
#include "coffre.hpp"

#pragma once

class Robot : public Personnage
{
private:
	int inventaire;
public:
	Robot();
	Robot(int positionX,int positionY, clan::Image sprite);
	int getInventaire();
	void setInventaire(int inventaire);
	void ouvrir(Coffre* coffre);
	void ramasser(Clef* clef);
};
