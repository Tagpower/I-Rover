/*!
 * \brief Classe Armure.
 * \details Implémentation de la classe Armure et de ses méthodes.
 * \author Geoffrey DESBROSSES
 * \version 1
 * \date 2015-12-10
 */

#include "Armure.h"


/*!
 * Constructeur d'une armure.
 * @param[in] robustesse La robustesse de l'armure.
 * @param[in] nom Le nom de l'armure.
 * @param[out] Armure L'armure créée.
 */
Armure::Armure(int robustesse, std::string nom){
	this->robustesse = robustesse;
    this->nom = nom;
}


/*!
 * Le constructeur d'une armure par défaut.
 * @param[out] Armure l'armure créée.
 */
Armure::Armure(){
}

/*!
 * Le getter du nom de l'armure.
 * Retourne le nom de l'armure.
 */
int Armure::getNom(){
	return this->nom;
}

/*!
 * Le setter du nom de l'armure.
 * Modifie le nom de l'armure.
 * @param[in] nom le nouveau nom de l'armure.
 */
void Armure::setNom(std::string nom){
	this->nom = nom;
}

/*!
 * Le getter de la robustesse de l'armure.
 * @return la robustesse de l'armure.
 */
int Armure::getRobustesse(){
	return this->robustesse;
}

/*!
 * Le setter de la robustesse de l'armure.
 * Modifie la robustesse de l'armure.
 * @param [in] robustesse la nouvelle robustesse de l'armure.
 * @param [out] robustesse La nouvelle robustesse de l'armure.
 */
void Armure::setRobustesse(int robustesse){
	this->robustesse = robustesse;
}

