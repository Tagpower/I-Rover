#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <personnage.hpp>


class Robot:Personnage
{
private:
	std::vector <Clef> inventaire;
public:
	Robot();
	std::vector <Clef> getInventaire;
	void setInventaire;
	void ouvrir(Coffre coffre);
	void ramasser(Clef clef);

}
