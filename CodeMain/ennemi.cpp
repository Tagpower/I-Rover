/*!
 * \brief Classe ennemi.
 * \details Implémentation de la classe Ennemi et de ses méthodes;
 * \author Geoffrey DESBROSSES
 * \version 1
 * \date 2015-12-09
 */

#include "ennemi.hpp"

/*!
 * Constructeur de l'ennemi.
 * @param [out] Ennemi l'ennemi créé.
 */
Ennemi::Ennemi() : Personnage(){

}

 /*!
 * Constructeur de l'ennemi.
 * @param [in] x la position en x de l'ennemi à créer.
 * @param [in] y la position en y de l'ennemi à créer.
 * @param [in] arme L'arme de l'ennemi.
 * @param [in] armure L'armure de l'ennemi.
 * @param [in] sprite L'image de l'ennemi.
 * @param [out] Ennemi l'ennemi créé.
 */
Ennemi::Ennemi(int x, int y, Arme* arme, Armure* armure, clan::Image sprite) : Personnage(x, y, arme, armure, sprite){

}
