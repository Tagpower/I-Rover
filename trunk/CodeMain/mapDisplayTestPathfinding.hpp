#include "precomp.hpp"
#include "robot.hpp"
#include "ennemi.hpp"
#include "tileset.hpp"
#include "mine.hpp"
#include "armure.hpp"
#include "map.hpp"
#include "astar.hpp"
#include "coffre.hpp"
#include "clef.hpp"

#pragma once

class MapDisplayTestPathfinding : public clan::Application
{
public:
	MapDisplayTestPathfinding();
	bool update() override;
    void  goTo(Personnage perso, std::string path);
    void explorationRobot(Robot robot,vector<Clef> liste_clefs, vector<Coffre> liste_coffres);
    void explorationEnnemi(Ennemi ennemi);
	Coffre findNearestChest(Robot robot, vector<Coffre> liste_coffres);
	Coffre findNearestKey(Robot robot, vector<Clef> liste_clefs);

private:
	bool quit = false;
        Tileset tileset;
        Map map;
        Robot robot;
        vector<Ennemi> liste_ennemis;
        vector<Coffre> liste_coffres;
        vector<Clef> liste_clefs;
        
	clan::SlotContainer sc;
	clan::DisplayWindow window;
	clan::Canvas canvas;
        clan::Image tilesheet;
	clan::Font font;
	clan::GameTime game_time;
};
