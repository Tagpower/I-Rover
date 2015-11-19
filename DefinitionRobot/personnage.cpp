#include <personnage.hpp>
#include <math.h>

/*!
 * Constructeur d'un personnage.
 * @param[in] x la position en x où le personnage sera créé.
 * @param[in] y la position en y où le personnage sera créé.
 * @param[out] Personnage le personnage créé.
 */
Personnage::Personnage(int x, int y){
	positionX = x;
	positionY = y;
}

/*!
 * Le constructeur d'un personnage par défaut.
 * @param[out] Personnage le personnage créé.
 */
Personnage::Personnage(void){

}

int::getPositionX(){
	return positionX;
}

void Personnage::setPositionX(int x){
	this->positionX = x;
}
int::getPositionY(){
	return positionY;
}

void Personnage::setPositionY(int y){
	this->positionY = y;
}

/*!
 * Deplace le personnage d'une case a droite, gauche, haut ou bas.
 * @param[in] x la position actuelle du personnage en x.
 * @param[in] y la position actuelle du personnage en y.
 * @return rien
 */
void deplacer(int x, int y){
	
}

/*! 
 * Methode servant a faire affronter deux personnages du jeu.
 * Calcul aléatoirement la force des deux adversaires et compare ces deux forces.
 * @param[in] adversaire Le personnage a combattre.
 * @return victoire true si le combat est gagné, false sinon.
 */
bool Combattre(Personnage adversaire){
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



