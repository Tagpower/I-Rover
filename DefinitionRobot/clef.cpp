/*! 
 * \brief Objet clef.
 * \details POJO de la classe Clef avec getter et setter.
 * \author Geoffrey DESBROSSES
 * \version 1
 * \date 2015-12-09
 */

#include "clef.hpp"

/*!
 * Constructeur d'une clef.
 * @param [in] x la position en x où la clef sera créée.
 * @param [in] y la position en y où la clef sera créée.
 * @param [out] Clef la clef créée.
 */
Clef::Clef(int x, int y){
	positionX = x;
	positionY = y;
}

/*!
 * Le constructeur d'une clef par défaut.
 * @param [out] Clef la clef créée.
 */
Clef::Clef(){

}

int Clef::getPositionX(){
	return this->positionX;
}

void Clef::setPositionX(int x){
	this->positionX = x;
}
int Clef::getPositionY(){
	return this->positionY;
}

void Clef::setPositionY(int y){
	this->positionY = y;
}
