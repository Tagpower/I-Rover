/*!
 * \brief Classe Bazooka.
 * \details Impl�mentation de la classe Bazooka et de ses m�thodes.
 * \author Geoffrey DESBROSSES
 * \version 1
 * \date 2015-12-09
 */

#include "bazooka.hpp"
using namespace std;


/*!
 * Constructeur du bazooka.
 * @param [out] puissance La puissance du bazooka, 20 par d�faut.
 * @param [out] nom Le nom du bazooka.
 * @return Bazooka le bazooka cr��.
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
 * @return Bazooka le bazooka cr��.
 */
Bazooka::Bazooka(int puissance, string nom) : Arme(puissance, nom){
}


