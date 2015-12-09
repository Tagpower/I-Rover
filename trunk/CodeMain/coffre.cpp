#include "coffre.hpp"

/*!
 * Constructeur d'un coffre.
 * @param[in] x la position en x où le coffre sera créé.
 * @param[in] y la position en y où le coffre sera créé.
 * @param[out] positionX La position du coffre en x.
 * @param[out] positionY La position du coffre en y.
 * @param[out] ouvert Le statut du coffre, false par défaut.
 * @return Coffre le coffre créé.
 */
Coffre::Coffre(int x, int y){
	positionX = x;
	positionY = y;
	ouvert = false;
}

/*!
 * Le constructeur d'un coffre par défaut.
 * @return Coffre le coffre créé.
 */
Coffre::Coffre(){

}

/*!
 * Méthode qui permet d'acceder à la position en x d'un coffre.
 * @return la position en x du coffre. 
 */
int Coffre::getPositionX(){
	return this->positionX;
}

/*!
 * Méthode qui mermet de modifier la position en x d'un coffre.
 * @param[in] x La nouvelle position en x du coffre à modifier.
 * @param[out] positionX La position du coffre àprès modification.
 */ 
void Coffre::setPositionX(int x){
	this->positionX = x;
}

/*!
 * Méthode qui permet d'acceder à la position en y d'un coffre.
 * @return la position en y du coffre. 
 */
int Coffre::getPositionY(){
	return this->positionY;
}

/*!
 * Méthode qui mermet de modifier la position en x d'un coffre.
 * @param[in] y La nouvelle position en y du coffre à modifier.
 * @param[out] positionY La position du coffre àprès modification.
 */ 
void Coffre::setPositionY(int y){
	this->positionY = y;
}

/*!
 * Méthode qui permet de savoir si un coffre est ouvert ou non.
 * @param[out] ouvert Boolean qui prend la valeur true si le coffre est ouvert, false sinon.
 */ 
bool Coffre::isOuvert(){
	return this->ouvert;
}

/*!
 * Méthode qui permet de modifier le statut d'un coffre.
 * @param[in] ouv la valeur booléenne à affecter au statut du coffre.
 * @param[out] ouvert Le statut du coffre: true si le coffre est ouvert, false sinon.
 */ 
void Coffre::setOuvert(bool ouv){
	this->ouvert = ouv;
}
