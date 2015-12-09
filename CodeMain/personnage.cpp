/*! 
 * \brief Classe Personnage.
 * \details Implémentation de la classe Personnage et de ses méthodes.
 * \author Geoffrey DESBROSSES
 * \version 1
 * \date 2015-12-09
 */

#include "personnage.hpp"
#include <math.h>

/*!
 * Constructeur d'un personnage.
 * @param [in] x la position en x où le personnage sera créé.
 * @param [in] y la position en y où le personnage sera créé.
 * @param [out] positionX la nouvelle position en x du personnage créé.
 * @param [out] positionY la nouvelle position en y du personnage créé.
 * @return Personnage le personnage créé.
 */
Personnage::Personnage(int x, int y, clan::Image sprite){
	positionX = x;
	positionY = y;
    this->sprite = sprite;
}

/*!
 * Le constructeur d'un personnage par défaut.
 * @return Personnage le personnage créé.
 */
Personnage::Personnage(){

}

/*!
 * Le getter de la position en x du personnage.
 * @return la position courante du personnage en x.
 */
int Personnage::getPositionX(){
	return this->positionX;
}

/*!
 * Le setter de la position en x du personnage.
 * Modifie la position du personnage en x.
 * @param [in] x la position en x à affecter.
 * @param [out] positionX La nouvelle position en x du personnage.
 */
void Personnage::setPositionX(int x){
	this->positionX = x;
}

/*!
 * Le getter de la position en y du personnage.
 * @return la position courante du personnage en y.
 */
int Personnage::getPositionY(){
	return this->positionY;
}

/*!
 * Le setter de la position en x du personnage.
 * Modifie la position du personnage en y.
 * @param [in] y la nouvelle position en y du personnage.
 * @param [out] positionY La nouvelle position en y du personnage.
 */
void Personnage::setPositionY(int y){
	this->positionY = y;
}

/*!
 * Deplace le personnage d'une case a droite, gauche, haut ou bas.
 * @param [in] x la valeur de déplacement en x.
 * @param [in] y la valeur de déplacement en y.
 * @param [out] x la position du personnage en x après le déplacement.
 * @param [out] y la position du personnage en y après le déplacement.
 * @exception si x et y en entrée ne sont pas entre -1 et 1.
 * @exception s'il n'y a aucun déplacement.
 * @exception si x et y sont différents de 0.
 * @return rien
 */
void Personnage::deplacer(int x, int y){
	if( x > 1 || x < -1 || y > 1 || y < -1){
		throw std::string("trop gros nombre de déplacement."); 
	}
	if( x == 0 && y ==0){
		throw std::string("déplacement null."); 
	}
	if((x == 1 && y == 1) || (x == 1 && y == -1) || (x == -1 && y == 1) || (x == -1 && y == -1)){
		throw std::string("le déplacement ne doit pas dépasser une case");
	}
	//Déplacement horizontal
	if(x == 0){
		this->positionY = this->positionY + y;
	}
	//Déplacement vertical
	else{
		this->positionX = this->positionX + x;
	}
}

/*! 
 * Methode servant a faire affronter deux personnages du jeu.
 * Calcul aléatoirement la force des deux adversaires et compare ces deux forces.
 * @param [in] adversaire Le personnage a combattre.
 * @return victoire true si le combat est gagné, false sinon.
 */
bool Personnage::Combattre(Personnage* adversaire){
	bool victoire;
	int force_hero = rand() * 10;
	int force_adversaire = rand() * 10;
	
	if(force_hero >= force_adversaire){
		victoire = true;
	}
	else{
		victoire = false;
	}
    return victoire;    
}

/*!
 * Méthode servant à dessiner un personnage sur la map.
 * @param [in] c L'image à dessiner.
 * @param [in] x la position en x du personnage à dessiner.
 * @param [in] y la position en y du personnage à dessiner.
 * @param [out] sprite L'image de l'objet aux coordonnées (x,y).
 */ 
void Personnage::draw(clan::Canvas c, int x, int y) {
    this->sprite.draw(c, x, y);
}


