#include "ennemi.hpp"

/*!
 * Constructeur de l'ennemi.
 * @param[out] Ennemi l'ennemi créé.
 */
Ennemi::Ennemi() : Personnage(){

}
    
 /*!
 * Constructeur de l'ennemi.
 * @param[in] x la position en x de l'ennemi à créer.
 * @param[in] y la position en y de l'ennemi à créer.
 * @param[out] Ennemi l'ennemi créé.
 */
Ennemi::Ennemi(int x, int y, clan::Image sprite) : Personnage(x, y, sprite){

}
