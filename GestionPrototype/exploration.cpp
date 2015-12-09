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

int nb_clefs; //todo récupérer le nombre de clefs sur la map
int nb_coffres;//todo récupérer le nombre de coffres sur la map

void exploration(Robot robot){
	while((robot.inventaire==0){
		Clef cibleClef= findNearestKey();
		std::string path= astar::pathfind(robot.positionX, robot.positionY, cibleClef.positionX, cibleClef.positionY);
		goTo(robot, path);
		}
	if(robot.inventaire>0){
		Coffre cibleCoffre = findNearestCrest();
		std::string path= astar::pathfind(robot.positionX, robot.positionY, cibleCoffre.positionX, cibleCoffre.positionY);
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

void goTo(Robot robot, std::string path){
	while (path::length()>0){
			int dirToGo= path.at(0);
			switch(dirToGo){
				case 0:
					robot.deplacer(1,0);
					path::erase(0,1);
				case 1:
					robot.deplacer(0,-1);
					path::erase(0,1);
				case 2:
					robot.deplacer(-1,0);
					path::erase(0,1);
				case 3:
					robot.deplacer(0,1);
					path::erase(0,1);	
			}			
}
