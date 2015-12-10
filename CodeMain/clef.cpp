/*! 
 * \brief Classe Clef.
 * \details Implémentation de la classe Clef et de ses méthodes.
 * \author Geoffrey DESBROSSES
 * \version 1
 * \date 2015-12-09
 */

#include "clef.hpp"

/*!
 * Constructeur d'une clef.
 * @param[in] x la position en x où la clef sera créée.
 * @param[in] y la position en y où la clef sera créée.
 * @param[out] Clef la clef créée.
 */
Clef::Clef(int x, int y, clan::Image sprite){
	positionX = x;
	positionY = y;
        this->sprite = sprite;
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
 * @param [in] x la nouvelle position en x de la clef.
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
 * @param [in] x la nouvelle position en y de la clef.
 */
void Clef::setPositionY(int y){
	this->positionY = y;
}

/*!
 * Méthode servant à dessiner une clef sur la map.
 * @param [in] c Le contexte où dessiner.
 * @param [in] x la position en x de la clef à dessiner.
 * @param [in] y la position en y de la clef à dessiner.
 * @param [out] sprite L'image de l'objet aux coordonnées (x,y).
 */ 
void Clef::draw(clan::Canvas c, int x, int y) {
    this->sprite.draw(c, x, y);
}
