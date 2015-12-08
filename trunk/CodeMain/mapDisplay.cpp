
#include "mapDisplay.hpp"

clan::ApplicationInstance<MapDisplay> clanapp;

MapDisplay::MapDisplay()
{
#ifdef WIN32
	clan::D3DTarget::set_current();
#else
	clan::OpenGLTarget::set_current();
#endif

	clan::DisplayWindowDescription desc;
	desc.set_title("I-Rover Map Display");
	desc.set_size(clan::Sizef(640.0f, 480.0f), true);
	desc.set_allow_resize(true);

	window = clan::DisplayWindow(desc);
	canvas = clan::Canvas(window);

	// Acriver la fermeture de la fenêtre
	sc.connect(window.sig_window_close(), [&](){quit = true; });

	// Détection du clavier
	sc.connect(window.get_keyboard().sig_key_up(), clan::bind_member(this, &MapDisplay::on_input_up));

	// Load a sprite from a png-file
        tilesheet = clan::Image(canvas, "roguelikeSheet.png");
	font = clan::Font("tahoma", 24);
        
        //Lecture et affichage de la carte
        //Tileset myTileset(tilesheet, 31, 57, 16, 16, 1); //TODO: Paramètres à récupérer depuis le fichier .tmx
        Tileset myTileset(tilesheet, "map3.tmx");
        Map terrain(12,36, myTileset); //Création de la carte. TODO: récupérer les dimensions depuis le fichier .tmx
        //Map terrain("map1.tmx", myTileset);
        this->tileset = myTileset;
        this->map = terrain;
        this->map.readTmxFile("map3.tmx"); //Génération de la carte par lecture du fichier .tmx
        
	game_time.reset();
}

bool MapDisplay::update()
{
	game_time.update();

	// Clear the display
	canvas.clear(clan::Colorf(0.2f, 0.2f, 0.2f));

	std::string text("Map Display");
	clan::Sizef text_size = font.measure_text(canvas, text).bbox_size;
	font.draw_text(canvas, ((canvas.get_width() - text_size.width) / 2), 32, text, clan::Colorf::white);

        //this->map.drawMap(canvas); //TODO: Dessiner la carte au centre de la fenêtre
        this->map.drawMap(canvas, canvas.get_width()/2 - map.getWidth() * map.getTileSize() /2 ,
                                  canvas.get_height()/2 - map.getHeight() * map.getTileSize() /2);
        
	window.flip(1);
        
	return !quit;
}

//Quitter en pressant Echap
void MapDisplay::on_input_up(const clan::InputEvent &key)
{
	if(key.id == clan::keycode_escape)
	{
		quit = true;
	}
}