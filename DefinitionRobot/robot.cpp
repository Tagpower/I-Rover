#include <personnage.hpp>
#include <personnage.cpp>
#include <robot.hpp>


/*!
 * Constructeur du robot.
 * @param[out] Robot le robot créé.
 */
Robot::Robot(){

}

void Robot::setInventaire(std::vector <Clef> inventaire){
	this->inventaire = inventaire;
}

std::vector<Clef>::getInventaire(){
	return std::vector<Clef> inventaire;
}
	
/*! 
 * Methode servant a ouvrir un coffre.
 * @param[in] coffre Le coffre à ouvrir.
 */
void ouvrir(Coffre coffre){
	//On ouvre le coffre seulement si le robot et le coffre sont sur la même case
	if(this.positionX == coffre.getPositionX() && this.positionY == coffre.getPositionY()){
		coffre.setOuvert(true);
	}
}

/*! 
 * Methode servant a ramasser une clef.
 * @param[in] clef La clef à ramasser.
 */
void ramasser(Clef clef){
	//On ramasse la clef seulement si le robot et la clef sont sur la même case
	if(this.positionX == clef.positionX && this.positiony == clef.positionY){
		this.inventaire.insert(1, clef);
	}
}
