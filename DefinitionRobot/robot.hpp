#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include "personnage.hpp"
#include "coffre.hpp"


class Robot : public Personnage
{
private:
	std::vector <Clef*> inventaire;
public:
	Robot();
	Robot(int positionX,int positionY);
	std::vector <Clef*> getInventaire;
	void setInventaire(std::vector <Clef*> inventaire);
	void ouvrir(Coffre* coffre);
	void ramasser(Clef* clef);

};
