/*!
 * \brief Classe Bazooka.
 * \details Implémentation de la classe Bazooka et de ses méthodes.
 * \author Geoffrey DESBROSSES
 * \version 1
 * \date 2015-12-09
 */

#include "bazooka.h"
using namespace std;


/*!
 * Constructeur du bazooka.
 * @param [out] puissance La puissance du bazooka, 20 par défaut.
 * @param [out] nom Le nom du bazooka.
 * @return Bazooka le bazooka créé.
 */
Bazooka::Bazooka() : Arme(){
    this->puissance = 20;
    this->nom = "Bazooka";
}

/*!
 * Constructeur du bazooka.
 * @param [in] puissance La puissance du bazooka.
 * @param [in] nom Le nom du bazooka.
 * @param [out] puissance La puissance du bazooka.
 * @param [out] nom Le nom du bazooka.
 * @return Bazooka le bazooka créé.
 */
Bazooka::Bazooka(int puissance, string nom) : Arme(puissance, nom){
}


