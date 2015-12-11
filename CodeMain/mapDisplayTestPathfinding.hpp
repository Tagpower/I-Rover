#include "precomp.hpp"
#include "robot.hpp"
#include "ennemi.hpp"
#include "tileset.hpp"
#include "map.hpp"
#include "astar.hpp"
#pragma once

class MapDisplayTestPathfinding : public clan::Application
{
public:
	MapDisplayTestPathfinding();
	bool update() override;

private:
	void on_input_up(const clan::InputEvent &key);

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
