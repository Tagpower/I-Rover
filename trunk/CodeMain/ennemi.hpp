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
	Ennemi(int positionX, int positionY, clan::Image sprite);
};
