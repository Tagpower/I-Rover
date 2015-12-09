#include "precomp.hpp"
#include "robot.hpp"
//#include "ennemi.hpp"
//#include "coffre.hpp"
#include "tileset.hpp"
#include "map.hpp"

#pragma once

class MapDisplay : public clan::Application
{
public:
	MapDisplay();
	bool update() override;

private:
	void on_input_up(const clan::InputEvent &key);

private:
	bool quit = false;
        Tileset tileset;
        Map map;
        Robot robot;
	clan::SlotContainer sc;
	clan::DisplayWindow window;
	clan::Canvas canvas;
        clan::Image tilesheet;
	clan::Font font;
	clan::GameTime game_time;
};