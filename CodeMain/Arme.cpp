/*!
 * \brief Classe Arme.
 * \details Implémentation de la classe Arme et de ses méthodes.
 * \author Geoffrey DESBROSSES
 * \version 1
 * \date 2015-12-10
 */

#include "Arme.h"


/*!
 * Constructeur d'une arme.
 * @param[in] puissance La puissance de l'arme.
 * @param[in] nom Le nom de l'arme.
 * @param[out] Arme L'arme créée.
 */
Arme::Arme(int puissance, std::string nom){
	this->puissance = puissance;
    this->nom = nom;
}


/*!
 * Le constructeur d'une arme par défaut.
 * @param[out] Arme l'arme créée.
 */
Arme::Arme(){
}

/*!
 * Le getter du nom de l'arme.
 * Retourne le nom de l'arme.
 */
int Arme::getNom(){
	return this->nom;
}

/*!
 * Le setter du nom de l'arme.
 * Modifie le nom de l'arme.
 * @param[in] nom le nouvea uno mde l'arme.
 */
void Arme::setNom(std::string nom){
	this->nom = nom;
}

/*!
 * Le getter de la puissance de l'arme.
 * @return la puissance de l'arme.
 */
int Arme::getPuissance(){
	return this->puissance;
}

/*!
 * Le setter de la puissance de l'arme.
 * Modifie la puissance de l'arme.
 * @param [in] puissance la nouvelle puissance de l'arme.
 * @param [out] puissance La nouvelle puissance de l'arme.
 */
void Arme::setPuissance(int puissance){
	this->puissance = puissance;
}

