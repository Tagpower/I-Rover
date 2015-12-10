/*!
 * \brief Classe Coffre.
 * \details Implémentation de la classe Coffre avec ses méthodes.
 * \author Geoffrey DESBROSSES
 * \version 1
 * \date 2015-12-09
 */

#include "coffre.hpp"

/*!
 * Constructeur d'un coffre.
 * @param [in] x la position en x où le coffre sera créé.
 * @param [in] y la position en y où le coffre sera créé.
 * @param [in] sprite L'image du coffre à créer.
 * @param [out] positionX La position du coffre en x.
 * @param [out] positionY La position du coffre en y.
 * @param [out] ouvert Le statut du coffre, false par défaut.
 * @param [out] sprite La nouvelle image du coffre.
 * @return Coffre le coffre créé.
 */
Coffre::Coffre(int x, int y, clan::Image sprite){
	positionX = x;
	positionY = y;
	ouvert = false;
    this->sprite = sprite;
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
 * @param [in] x La nouvelle position en x du coffre à modifier.
 * @param [out] positionX La position du coffre après modification.
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
 * @param [in] y La nouvelle position en y du coffre à modifier.
 * @param [out] positionY La position du coffre àprès modification.
 */
void Coffre::setPositionY(int y){
	this->positionY = y;
}

/*!
 * Méthode qui permet de savoir si un coffre est ouvert ou non.
 * @return ouvert Boolean qui prend la valeur true si le coffre est ouvert, false sinon.
 */
bool Coffre::isOuvert(){
	return this->ouvert;
}

/*!
 * Méthode qui permet de modifier le statut d'un coffre.
 * @param [in] ouv la valeur booléenne à affecter au statut du coffre.
 * @param [out] ouvert Le statut du coffre: true si le coffre est ouvert, false sinon.
 */
void Coffre::setOuvert(bool ouv){
	this->ouvert = ouv;
}

/*!
 * Méthode servant à dessiner un coffre sur la map.
 * @param [in] c L'image à dessiner.
 * @param [in] x la position en x du coffre à dessiner.
 * @param [in] y la position en y du coffre à dessiner.
 * @param [out] sprite L'image de l'objet aux coordonnées (x,y).
 */
void Coffre::draw(clan::Canvas c, int x, int y) {
    this->sprite.draw(c, x, y);
}
