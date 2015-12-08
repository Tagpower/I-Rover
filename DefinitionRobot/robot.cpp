#include "robot.hpp"


/*!
 * Constructeur du robot.
 * @param[out] Robot le robot créé.
 */
 
Robot::Robot() : Personnage(){

}
    
Robot::Robot(int x, int y) : Personnage(x, y){

}

void Robot::setInventaire(std::vector <Clef*> inventaire){
	this->inventaire = inventaire;
}

std::vector<Clef*> Robot::getInventaire(){
	return this->inventaire;
}
	
/*! 
 * Methode servant a ouvrir un coffre.
 * @param[in] coffre Le coffre à ouvrir.
 */
void Robot::ouvrir(Coffre* coffre){
	//On ouvre le coffre seulement si le robot et le coffre sont sur la même case
	if(this->positionX == coffre->getPositionX() && this->positionY == coffre->getPositionY()){
		coffre->setOuvert(true);
	}
}

/*! 
 * Methode servant a ramasser une clef.
 * @param[in] clef La clef à ramasser.
 */
void Robot::ramasser(Clef* clef){
	//On ramasse la clef seulement si le robot et la clef sont sur la même case
	if(this->positionX == clef->getPositionX() && this->positionY == clef->getPositionY()){
		this->inventaire.insert(1, *clef);
	}
}
