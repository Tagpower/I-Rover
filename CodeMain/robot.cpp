#include "robot.hpp"


/*!
 * Constructeur du robot.
 * @return Robot le robot créé.
 */
Robot::Robot() : Personnage(){

}
  
/*!
 * Constructeur du robot.
 * @param[in] x La position en x du robot sur la carte.
 * @param[in] y La position en y du robot sur la carte.
 * @param[out] inventaire La taille de l'inventaire du robot, 0 par défaut.
 * @return Robot le robot créé.
 */  
Robot::Robot(int x, int y) : Personnage(x, y){
	this->inventaire = 0;
}

/*!
 * Methode servant à modifier l'inventaire du robot.
 * L'inventaire correspond au nombre de clef que possède le robot.
 * @param[in] inventaire La valeur à affecter à l'inventaire.
 * @param[out] inventaire La nouvelle valeur de l'inventaire.
 */
void Robot::setInventaire(int inventaire){
	this->inventaire = inventaire;
}

/*!
 * Methode servant à retourner l'inventaire du robot.
 * L'inventaire correspond au nombre de clef que possède le robot.
 * @return inventaire L'inventaire du robot.
 * */
int Robot::getInventaire(){
	return this->inventaire;
}
	
/*! 
 * Methode servant a ouvrir un coffre. 
 * Il faut que le robot ai la même position que le coffre.
 * Le coffre disparait après ouverture et le robot perd une clef.
 * @param[in] coffre Le coffre à ouvrir.
 * @param[out] inventaire L'inventaire du robot avec une clef en moins.
 * @param[out] ouvert Le statut du coffre à ouvrir après ouverture.
 * @exception si le robot ne possède aucune clef.
 */
void Robot::ouvrir(Coffre* coffre){
	//On ouvre le coffre seulement si le robot et le coffre sont sur la même case
	if(this->positionX == coffre->getPositionX() && this->positionY == coffre->getPositionY()){
		if(this->inventaire > 0 && !coffre->isOuvert()){
			coffre->setOuvert(true);
			inventaire --;
		}
		else{
			throw std::string("inventaire vide.");
		}
	}
}

/*! 
 * Methode servant a ramasser une clef. 
 * Incrémente l'inventaire de 1 quand on ramasse la clef et fait disparaitre la clef de la carte.
 * Il faut que le robot ai la même position que la clef pour la ramasser.
 * @param[in] clef La clef à ramasser.
 * @param[out] inventaire l'inventaire incrémenté de 1.
 */
void Robot::ramasser(Clef* clef){
	if(this->positionX == clef->getPositionX() && this->positionY == clef->getPositionY()){
		this->inventaire++;
	}
}
