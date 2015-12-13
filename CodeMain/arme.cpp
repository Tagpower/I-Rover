/*!
 * \brief Classe Arme.
 * \details Impl�mentation de la classe Arme et de ses m�thodes.
 * \author Geoffrey DESBROSSES
 * \version 1
 * \date 2015-12-10
 */

#include "arme.hpp"
using namespace std;


/*!
 * Constructeur d'une arme.
 * @param [in] puissance La puissance de l'arme.
 * @param [in] nom Le nom de l'arme.
 * @param [out] puissance La puissance de l'arme.
 * @param [out] nom Le nom de l'arme.
 * @return Arme L'arme cr��e.
 */
Arme::Arme(int puissance, string nom){
	this->puissance = puissance;
    this->nom = nom;
}


/*!
 * Le constructeur d'une arme par d�faut.
 * @param [out] Arme l'arme cr��e.
 */
Arme::Arme(){
}

/*!
 * Le getter du nom de l'arme.
 * @return le nom de l'arme.
 */
string Arme::getNom(){
	return this->nom;
}

/*!
 * Le setter du nom de l'arme.
 * Modifie le nom de l'arme.
 * @param [in] la valeur � affecter au nom de l'arme.
 * @param [out] nom le nouveau nom de l'arme.
 */
void Arme::setNom(string nom){
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

