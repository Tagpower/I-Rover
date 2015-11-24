#include <clef.hpp>

/*!
 * Constructeur d'une clef.
 * @param[in] x la position en x où la clef sera créée.
 * @param[in] y la position en y où la clef sera créée.
 * @param[out] Clef la clef créée.
 */
Clef::Clef(int x, int y){
	positionX = x;
	positionY = y;
}

/*!
 * Le constructeur d'une clef par défaut.
 * @param[out] Clef la clef créée.
 */
Clef::Clef(void){

}

int::getPositionX(){
	return positionX;
}

void Clef::setPositionX(int x){
	this->positionX = x;
}
int::getPositionY(){
	return positionY;
}

void Clef::setPositionY(int y){
	this->positionY = y;
}
