/*!
 * \brief Classe Armure.
 * \details Impl�mentation de la classe Armure et de ses m�thodes.
 * \author Geoffrey DESBROSSES
 * \version 1
 * \date 2015-12-10
 */

#include "armure.hpp"
using namespace std;

/*!
 * Constructeur d'une armure.
 * @param [in] robustesse La robustesse de l'armure.
 * @param [in] nom Le nom de l'armure.
 * @param [out] robustesse La nouvelle robustesse de l'armure.
 * @param [out] nom Le nouveau nom de l'armure.
 * @return Armure L'armure cr��e.
 */
Armure::Armure(int robustesse, string nom){
	this->robustesse = robustesse;
    this->nom = nom;
}


/*!
 * Le constructeur d'une armure par d�faut.
 * @return Armure l'armure cr��e.
 */
Armure::Armure(){
}

/*!
 * Le getter du nom de l'armure.
 * @return le nom de l'armure.
 */
string Armure::getNom(){
	return this->nom;
}

/*!
 * Le setter du nom de l'armure.
 * Modifie le nom de l'armure.
 * @param [in] nom Le nom � affecter � l'armure.
 * @param [out] nom Le nouveau nom de l'armure.
 */
void Armure::setNom(string nom){
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
 * @param [in] robustesse la robustesse � affecter � l'armure.
 * @param [out] robustesse La nouvelle robustesse de l'armure.
 */
void Armure::setRobustesse(int robustesse){
	this->robustesse = robustesse;
}

