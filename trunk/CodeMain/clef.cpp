#include "clef.hpp"

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
Clef::Clef(){

}

/*!
 * Le getter de la position en x de la clef.
 * Retourne la position courante de la clef en x.
 */
int Clef::getPositionX(){
	return this->positionX;
}

/*!
 * Le setter de la position en x de la clef.
 * Modifie la position de la clef en x.
 * @param[in] x la nouvelle position en x de la clef.
 */
void Clef::setPositionX(int x){
	this->positionX = x;
}

/*!
 * Le getter de la position en y de la clef.
 * Retourne la position courante de la clef en y.
 */
int Clef::getPositionY(){
	return this->positionY;
}

/*!
 * Le setter de la position en y de la clef.
 * Modifie la position de la clef en y.
 * @param[in] x la nouvelle position en y de la clef.
 */
void Clef::setPositionY(int y){
	this->positionY = y;
}
