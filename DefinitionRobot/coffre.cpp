#include <coffre.hpp>

/*!
 * Constructeur d'un coffre.
 * @param[in] x la position en x où le coffre sera créé.
 * @param[in] y la position en y où le coffre sera créé.
 * @param[out] Coffre le coffre créé.
 */
Coffre::Coffre(int x, int y){
	positionX = x;
	positionY = y;
	ouvert = false;
}

/*!
 * Le constructeur d'un coffre par défaut.
 * @param[out] Coffre le coffre créé.
 */
Coffre::Coffre(void){

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

bool::getOuvert(){
	return ouvert;
}

void Coffre::setOuvert(bool ouv){
	this->ouvert = ouv;
}
