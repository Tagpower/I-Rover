#include <string.h>
using namespace std ;

class Armure
{
protected:
	int robustesse;
	std::string nom;
public:
	Arme();
	Arme(int robustesse, std::string nom);
	int getRobustesse();
	std::string getNom();
	void setRobustesse(int robustesse);
	void setNom(std::string nom);
};
