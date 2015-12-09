/*! 
 * \brief 
 * \details 
 * \author Clément Bauchet
 * \version 1
 * \date 20 novembre 2015, 19:22
 */
 
#include "mapDisplay.hpp"

clan::ApplicationInstance<MapDisplay> clanapp;

/*! 
 * Classe gérant l'affichage graphique du terrain et des éléments présents dessus.
 * 
 * 
 * 
 */
MapDisplay::MapDisplay()
{
#ifdef WIN32
	clan::D3DTarget::set_current();
#else
	clan::OpenGLTarget::set_current();
#endif
        //Création de la fenêtre
	clan::DisplayWindowDescription desc;
	desc.set_title("I-Rover Map Display");
	desc.set_size(clan::Sizef(640.0f, 480.0f), true);
	desc.set_allow_resize(true);

	window = clan::DisplayWindow(desc);
	canvas = clan::Canvas(window);

	//Activer la fermeture de la fenêtre
	sc.connect(window.sig_window_close(), [&](){quit = true; });

	//Détection du clavier
	sc.connect(window.get_keyboard().sig_key_up(), clan::bind_member(this, &MapDisplay::on_input_up));

	//Charger l'image contenant les sprites des tiles
        tilesheet = clan::Image(canvas, "roguelikeSheet.png");
        clan::Image sprite_robot(canvas, "robot.png");
        
	font = clan::Font("tahoma", 24);
        
        //Lecture et affichage de la carte
        std::string fichierTmx = "map1.tmx"; //Fichier de carte à utiliser
        
        //Création du tileset à utiliser, en récupérant ses paramètres dans le fichier 
        Tileset myTileset(tilesheet, fichierTmx); 
        
         //Création de la carte par lecture du fichier .tmx
        Map terrain(fichierTmx, myTileset);
        
        this->tileset = myTileset;
        this->map = terrain;
        
        this->robot = Robot(0,0, sprite_robot);
        
	game_time.reset();
}

bool MapDisplay::update()
{
	game_time.update();

	//Tout effacer
	canvas.clear(clan::Colorf::gray20);

        //Affichage d'un texte
	std::string text("Map Display");
	clan::Sizef text_size = font.measure_text(canvas, text).bbox_size;
	font.draw_text(canvas, ((canvas.get_width() - text_size.width) / 2), 32, text, clan::Colorf::white);

        //Dessin de la carte au centre de la fenêtre
        clan::Point map_origin(canvas.get_width()/2 - map.getWidth() * map.getTileSize() /2 ,
                               canvas.get_height()/2 - map.getHeight() * map.getTileSize() /2);
        
        this->map.drawMap(canvas, map_origin.x, map_origin.y);
                                  
        //Dessiner les objets et personnages à la bonne position
        this->robot.draw(canvas, map_origin.x + (robot.getPositionX()*tileset.getTile_width()) ,
                                 map_origin.y + (robot.getPositionY()*tileset.getTile_height()));
        
        this->robot.deplacer(0,0);
         //Afficher les changements du canvas
	window.flip(1);
        
	return !quit;
}


/*!
 * Méthode servant à quitter le programme.
 * @param [in] key La touche à presser pour quitter le programme.
 * @param [out] quit Valeur booléenne qui permet de savoir si le programem doit continuer ou pas.
 */ 
void MapDisplay::on_input_up(const clan::InputEvent &key)
{
	if(key.id == clan::keycode_escape)
	{
		quit = true;
	}
}
