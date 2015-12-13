/*!
 * \brief Classe Mine.
 * \details Impl�mentation de la classe Mine et de ses m�thodes.
 * \author Geoffrey DESBROSSES
 * \version 1
 * \date 2015-12-09
 */

#include "mine.hpp"
using namespace std;


/*!
 * Constructeur de mine.
 * @param [out] puissance la puissance de la mine, 8 par d�faut.
 * @param [out] nom Le nom de la mine.
 * @return Mine la mine cr��e.
 */
Mine::Mine() : Arme(){
    this->puissance = 8;
    this->nom = "Mine";
}

/*!
 * Constructeur de mine.
 * @param [in] x la position en x de la mine.
 * @param [in] y la position en y de la mine.
 * @param [in] sprite L'image de la mine.
 * @param [out] positionX La position de la mine en x.
 * @param [out] positionY La position de la mine en y.
 * @param [out] puissance La puissance de la mine, 8 par d�faut.
 * @param [out] nom Le nom de la mine.
 * @param [out] sprite l'image de la mine cr��e.
 * @return Mine la mine cr��e.
 */
Mine::Mine(int x, int y, clan::Image sprite) : Arme(){
    this->positionX = x;
    this->positionY = y;
    this->puissance = 8;
    this->nom = "Mine";
    this->sprite = sprite;
}

/*!
 * Constructeur de mine.
 * @param [in] x la position en x de la mine.
 * @param [in] y la position en y de la mine.
 * @param [in] puissance La puissance de la mine.
 * @param [in] nom Le nom de la mine.
 * @param [in] sprite L'image de la mine.
 * @param [out] positionX La position de la mine en x.
 * @param [out] positionY La position de la mine en y.
 * @param [out] puissance La puissance de la mine.
 * @param [out] nom Le nom de la mine.
 * @param [out] sprite l'image de la mine cr��e.
 * @return Mine la mine cr��e.
 */
Mine::Mine(int x, int y, int puissance, string nom, clan::Image sprite) : Arme(puissance, nom){
    this->positionX = x;
    this->positionY = y;
    this->sprite = sprite;
}

/*!
 * Le getter de la position en x de la  mine.
 * @return la position courante de la mine en x.
 */
int Mine::getPositionX(){
	return this->positionX;
}

/*!
 * Le setter de la position en x de la mine.
 * Modifie la position de la mine en x.
 * @param [in] x la position � affecter � la mine en x.
 * @param [out] positionX la nouvelle position de la mine.
 */
void Mine::setPositionX(int x){
	this->positionX = x;
}

/*!
 * Le getter de la position en y de la mine.
 * @return la position courante de la mine en y.
 */
int Mine::getPositionY(){
	return this->positionY;
}

/*!
 * Le setter de la position en y de la mine.
 * Modifie la position de la mine en y.
 * @param [in] y la position � affecter � la mine en y.
 * @param [out] positionY la nouvelle position de la mine.
 */
void Mine::setPositionY(int y){
	this->positionY = y;
}

/*!
 * Fait exploser la mine lorsqu'un ennemi passe dessus qui l'affaiblit.
 * @param [in] ennemi L'ennemi qui marche sur la mine.
 * @param [out] robustesse La robustesse de l'ennemi qui passe � 0.
 * @param [out] puissance La puissance de l'ennemi affaibli qui est moins �lev�e.
 */
void Mine::exploser(Ennemi* ennemi){
    if(this->positionX == ennemi->getPositionX() && this->positionY == ennemi->getPositionY()){
        ennemi->setRobustesse(0);
        ennemi->setPuissance(ennemi->getPuissance() - 5);
    }
}

/*!
 * Desinne une mine sur la map.
 * @param [in] c L'image de la mine � dessiner.
 * @param [in] x L'endroit o� dessiner la mine en x.
 * @param [in] y L'endroit o� dessiner la mine en y.
 */
void Mine::draw(clan::Canvas c, int x, int y) {
    this->sprite.draw(c, x, y);
}
