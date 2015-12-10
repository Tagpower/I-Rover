#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <math.h>
#include <ctime>
#include <cstdlib> 
#include <cstdio>
#include "astar.hpp"
#include "clef.hpp"
#include "coffre.hpp"
#include "Personnage.hpp"

int nb_clefs; //todo récupérer le nombre de clefs sur la map
int nb_coffres;//todo récupérer le nombre de coffres sur la map
void explorationEnnemi(Ennemi ennemi){
	while(ennemi->isActive){
		//random coord x et y
		//std::string path= astar::pathfind(ennemi.positionX, ennemi.positionY, positionCibleX, positionCibleY, ennemi->collision_map);
		//goTo(robot, path);
	}
}
void exploration(Robot robot){
	while((robot.inventaire==0){
		Clef cibleClef= findNearestKey();
		std::string path= astar::pathfind(robot->positionX, robot->positionY, cibleClef->positionX, cibleClef->positionY, robot->collision_map);
		goTo(robot, path);
		}
	if(robot.inventaire>0){
		Coffre cibleCoffre = findNearestCrest();
		std::string path= astar::pathfind(robot->positionX, robot->positionY, cibleCoffre->positionX, cibleCoffre->positionY, robot->collision_map);
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


void goTo(Personnage perso, std::string path){
	while (path::length()>0){
			int dirToGo= path.at(0);
			switch(dirToGo){
				case 0:
					perso.deplacer(1,0);
					path::erase(0,1);
				case 1:
					perso.deplacer(0,-1);
					path::erase(0,1);
				case 2:
					perso.deplacer(-1,0);
					path::erase(0,1);
				case 3:
					perso.deplacer(0,1);
					path::erase(0,1);	
			}			
}
}
