#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <math.h>
#include <ctime>
#include <cstdlib> 
#include <cstdio>
#include <random>
#include "astar.hpp"
#include "clef.hpp"
#include "coffre.hpp"
#include "Personnage.hpp"

int nb_clefs; //todo récupérer le nombre de clefs sur la map
int nb_coffres;//todo récupérer le nombre de coffres sur la map
void explorationEnnemi(Ennemi ennemi){
	while(ennemi.getIsActive()){
		int positionCibleX, positionCibleY;
		int rangeX, rangeY;
		rangeX = ennemi.getCollisionMap->size();
		rangeY = ennemi.getCollisionMap()->at(0)->size();
		
		std::random_device rd;
		std::mt19937 gen(rd());
		
		std::uniform_int_distribution<> distriX(0,rangeX);
		std::uniform_int_distribution<> distriY(0,rangeY);
		
		positionCibleX= distriX(gen);
		positionCibleY= distriY(gen);
		
		std::string path= astar::pathfind(ennemi.getPositionX(), ennemi.getPositionY(), positionCibleX, positionCibleY, ennemi->getCollisionMap());
		goTo(ennemi, path);
	}
}
void exploration(Robot robot){
	while((robot.inventaire==0){
		Clef cibleClef= findNearestKey();
		std::string path= astar::pathfind(robot.getPositionX(), robot.getPositionY(), cibleClef.getPositionX(), cibleClef.getPositionY(), robot.getCollisionMap());
		goTo(robot, path);
		}
	if(robot.inventaire>0){
		Coffre cibleCoffre = findNearestCrest();
		std::string path= astar::pathfind(robot.getPositionX(), robot.getPositionY(), cibleCoffre.getPositionX(), cibleCoffre.getPositionY(), robot.getCollisionMap());
		goTo(robot, path);
	}	
}


Clef findNearestKey(){
Clef foundKey;
return	foundKey;
}

Coffre findNearestCrest(){
Coffre foundCrest;
return	foundCrest;
}

/*! Méthode faisant se déplacer un personnage
 * @param [in] perso, le Personnage à faire déplacer
 * @param [in] path, une chaine de caracteres contenant tous les déplacements à effectuer, chaque caractere peut etre 0, 1, 2 ou 3
 * @param [out] path est modifie, on supprime un caractère des que le deplacement correspondant est fait
 * @param [out] perso est modifie en appelant la methode deplacer
 */
void goTo(Personnage perso, std::string path){
	while (path::length()>0){
			int dirToGo= path.at(0);
			switch(dirToGo){
				case 0:
					perso.deplacer(1,0);
					sleep(1000);
					break();
				case 1:
					perso.deplacer(0,-1);
					sleep(1000);
					break();
				case 2:
					perso.deplacer(-1,0);
					sleep(1000);
					break();
				case 3:
					perso.deplacer(0,1);
					sleep(1000);
					break();
				default:
					break();
					
				path::erase(0,1)		
			}			
}
}
