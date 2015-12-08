#include "coffre.hpp"

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
Coffre::Coffre(){

}

int Coffre::getPositionX(){
	return this->positionX;
}

void Coffre::setPositionX(int x){
	this->positionX = x;
}
int Coffre::getPositionY(){
	return this->positionY;
}

void Coffre::setPositionY(int y){
	this->positionY = y;
}

bool Coffre::isOuvert(){
	return this->ouvert;
}

void Coffre::setOuvert(bool ouv){
	this->ouvert = ouv;
}
