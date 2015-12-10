#include <string.h>
using namespace std ;

class Arme
{
protected:
	int puissance;
	std::string nom;
public:
	Arme();
	Arme(int puissance, std::string nom);
	int getPuissance();
	std::string getNom();
	void setPuissance(int puissance);
	void setNom(std::string nom);
};
