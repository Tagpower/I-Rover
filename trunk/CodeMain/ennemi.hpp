#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "personnage.hpp"

#pragma once

class Ennemi : public Personnage
{
private:

public:

	Ennemi();
	Ennemi(int positionX, int positionY, Arme* arme, Armure* armure, clan::Image sprite);

};
