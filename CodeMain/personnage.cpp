#include "personnage.hpp"
#include <math.h>

/*!
 * Constructeur d'un personnage.
 * @param [in] x la position en x où le personnage sera créé.
 * @param [in] y la position en y où le personnage sera créé.
 * @param [in] arme L'arme que possède le personnage.
 * @param [in] armure L'armure que possède le personnage.
 * @param [in] sprite L'image du personnage.
 * @param [out] positionX la position en x du personnage sur la map.
 * @param [out] positionY la position en y du personnage sur la map.
 * @param [out] arme l'arme du personnage.
 * @param [out] armure l'armure du personnage.
 * @param [out] puissance La puissance du personnage, calculée à partir de son arme.
 * @param [out] robustesse La robustesse du personnage, calculée à partir de son armure.
 * @param [out] sprite L'image du personnage.
 * @param [out] isActive true par défaut pour que le personnage soit actif.
 * @return Personnage le personnage créé.
 */
Personnage::Personnage(int x, int y, Arme arme, Armure armure, clan::Image sprite){
	this->positionX = x;
	this->positionY = y;
	this->arme = arme;
	this->armure = armure;
	this->puissance = arme.getPuissance();
	this->robustesse = armure.getRobustesse();
    this->sprite = sprite;
    this->isActive=true;
}

/*!
 * Le constructeur d'un personnage par défaut.
 * @param [out] isActive true par défaut pour que le personnage soit actif.
 * @return Personnage le personnage créé.
 */
Personnage::Personnage(){
	this->isActive=true;
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
 * @param [in] x la position à affecter au personnage en x.
 * @param [out] positionX la nouvelle position en x du personnage.
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
 * @param [in] y la position à affecter au personnage en y.
 * @param [out] positionY la nouvelle position en y du personnage.
 */
void Personnage::setPositionY(int y){
	this->positionY = y;
}

/*!
 * Le setter pour collisionMap.
 * Donne une map au personnage pour savoir là où il peut passer.
 * @param [in] map Le vector représentant la map.
 * @param [out] map Le vector donné au personnage représentant la map courante.
 */
void Personnage::setCollisionMap(vector<vector<int> > map) {
    this->collision_map = map;
}

/*!
 * Le getter de la puissance du personnage.
 * @return la puissance du personnage.
 */
int Personnage::getPuissance(){
	return this->puissance;
}

/*!
 * Le setter de la puissance du personnage.
 * Modifie la puissance du personnage.
 * @param [in] puissance la nouvelle puissance du personnage.
 * @param [out] puissance La nouvelle puissance du personnage.
 */
void Personnage::setPuissance(int puissance){
	this->puissance = puissance;
}

/*!
 * Le getter de la robustesse du personnage.
 * @return la robustesse du personnage.
 */
int Personnage::getRobustesse(){
	return this->robustesse;
}

/*!
 * Le setter de la robustesse du personnage.
 * Modifie la robustesse du personnage.
 * @param [in] robustesse la nouvelle robustesse du personnage.
 * @param [out] robustesse La nouvelle robustesse du personnage.
 */
void Personnage::setRobustesse(int robustesse){
	this->robustesse = robustesse;
}

/*!
 * Le getter de l'arme du personnage.
 * @return l'arme du personnage.
 */
Arme Personnage::getArme(){
	return this->arme;
}

/*!
 * Le setter de l'arme du personnage.
 * Modifie l'arme du personnage.
 * @param [in] arme la nouvelle arme du personnage.
 * @param [out] arme La nouvelle arme du personnage.
 */
void Personnage::setArme(Arme arme){
	this->arme = arme;
}

/*!
 * Le getter de l'armure du personnage.
 * @return l'armure du personnage.
 */
Armure Personnage::getArmure(){
	return this->armure;
}

/*!
 * Le setter de l'armure du personnage.
 * Modifie l'armure du personnage.
 * @param [in] armure la nouvelle armure du personnage.
 * @param [out] armure La nouvelle armure du personnage.
 */
void Personnage::setArmure(Armure armure){
	this->armure = armure;
}

/*!
 * passe la valeur à true de l'attribut isActive du personnage.
 * @param [out] isActive = active. Le personnage n'est plus actif dans le jeu.
 */
void Personnage::setActive(bool active){
	this->isActive = active;
}


/*!
 * Getter de l'attribut isActivre d'un personnage.
 * @return si le personnage est actif ou non.
 */
bool Personnage::getIsActive(){
	return this->isActive;
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
	//Pose une mine avant de se déplacer
//	if(this->arme.getNom().compare("mine") == 0 && this->positionX%2 == 0 && this->positionY%2 == 1){
//            Mine mine(this->positionX, this->positionY);
//	}
	//Déplacement horizontal
	if(x == 1 && y == 0){
            if (this->positionX < collision_map.at(0).size()-1) {
                if (collision_map.at(positionY).at(positionX+1) != 0) {
                    positionX++;
                }
            }
	}
	if(x == -1 && y == 0){
            if (this->positionX > 0) {
                if (collision_map.at(positionY).at(positionX-1) != 0) {
                    positionX--;
                }
            }
	}
	if(x == 0 && y == 1){
            if (this->positionY < collision_map.size()-1) {
                if (collision_map.at(positionY+1).at(positionX) != 0) {
                    positionY++;
                }
            }
	}
        if(x == 0 && y == -1){
            if (this->positionY > 0) {
                if (collision_map.at(positionY-1).at(positionX) != 0) {
                    positionY--;
                }
            }
	}

}

/*!
 * Methode servant a faire affronter deux personnages du jeu.
 * Calcul aléatoirement la force des deux adversaires et compare ces deux forces à partir de leur puissance et de leur robustesse.
 * @param [in] adversaire Le personnage a combattre.
 * @return victoire true si le combat est gagné, false sinon.
 */
bool Personnage::Combattre(Personnage* adversaire){
	bool victoire;
	int force_hero = rand() * this->puissance * this->robustesse;
	int force_adversaire = rand() * adversaire->getPuissance() * adversaire->getRobustesse();

	if(force_hero >= force_adversaire){
		victoire = true;
	}
	else{
		victoire = false;
	}
    return victoire;
}

/*!
 * Desinne un personnage sur la map.
 * @param [in] c L'image du personnage.
 * @param [in] x la position en x où dessiner le personnage.
 * @param [in] y la position en y où dessiner le personnage.
 * @param [out] sprite l'image dessinée.
 */
void Personnage::draw(clan::Canvas c, int x, int y) {
    this->sprite.draw(c, x, y);
}

vector<vector<int> > Personnage::getCollisionMap(){
    return this->collision_map;
}


