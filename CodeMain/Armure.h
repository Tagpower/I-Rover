#include <string>

class Armure
{
protected:
	int robustesse;
	std::string nom;
public:
	Armure();
	Armure(int robustesse, std::string nom);
	int getRobustesse();
	std::string getNom();
	void setRobustesse(int robustesse);
	void setNom(std::string nom);
};
