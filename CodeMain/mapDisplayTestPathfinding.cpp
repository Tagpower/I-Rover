
#include "mapDisplayTestPathfinding.hpp"

clan::ApplicationInstance<MapDisplayTestPathfinding> clanapp;

/*! Classe gérant l'affichage graphique du terrain et des éléments présents dessus.
 *
 *
 *
 */
MapDisplayTestPathfinding::MapDisplayTestPathfinding()
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
        clan::Image sprite_ennemi_1(canvas, "ennemi1.png");
        clan::Image sprite_coffreF(canvas, "coffre_ferme.png");
        clan::Image sprite_clef(canvas, "clef.png");
        clan::Image sprite_mine(canvas, "mine.png");

	font = clan::Font("tahoma", 24);

        //Lecture et affichage de la carte
        std::string fichierTmx = "map1.tmx"; //Fichier de carte à utiliser

        //Création du tileset à utiliser, en récupérant ses paramètres dans le fichier
        Tileset myTileset(tilesheet, fichierTmx);

         //Création de la carte par lecture du fichier .tmx
        Map terrain(fichierTmx, myTileset);

        this->tileset = myTileset;
        this->map = terrain;
        this->map.setCollisionMap(vector<int>({6,1005})); //A changer en fonction de la map

        this->robot = Robot(0,0, sprite_robot);
        this->robot.setCollisionMap(this->map.getCollisionMap());

        this->liste_coffres = vector<Coffre>();
        this->liste_coffres.push_back(Coffre(5,5,sprite_coffreF));
        this->liste_coffres.push_back(Coffre(7,7,sprite_coffreF));


        this->liste_clefs = vector<Clef>();
        this->liste_clefs.push_back(Clef(2,8,sprite_clef));
        this->liste_clefs.push_back(Clef(12,6,sprite_clef));


        this->liste_ennemis = vector<Ennemi>();
        this->liste_ennemis.push_back(Ennemi(14,10,sprite_ennemi_1));
        this->liste_ennemis.push_back(Ennemi(8,14,sprite_ennemi_1));



	game_time.reset();
}

/*! Méthode mettant à jour l'application et redessinant tout
 * @return quit un booléen indiquant si l'application doit être quittée ou non
 */
bool MapDisplayTestPathfinding::update()
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
        for(auto &coffre : this->liste_coffres) {
            coffre.draw(canvas,map_origin.x + (coffre.getPositionX()*tileset.getTile_width()) ,
                               map_origin.y + (coffre.getPositionY()*tileset.getTile_height()));
        }
        for(auto &clef : this->liste_clefs) {
            clef.draw(canvas,map_origin.x + (clef.getPositionX()*tileset.getTile_width()) ,
                             map_origin.y + (clef.getPositionY()*tileset.getTile_height()));
        }
        for(auto &ennemi : this->liste_ennemis) {
            ennemi.draw(canvas,map_origin.x + (ennemi.getPositionX()*tileset.getTile_width()) ,
                               map_origin.y + (ennemi.getPositionY()*tileset.getTile_height()));
        }

        this->robot.draw(canvas, map_origin.x + (robot.getPositionX()*tileset.getTile_width()) ,
                                 map_origin.y + (robot.getPositionY()*tileset.getTile_height()));

		std::string pathRobot = this->pathFind(robot.getPositionX(), robot.getPositionY(), 12, 4, robot.getCollisionMap());
        this->goTo(robot, pathRobot);
        
        //std::string pathEnnemi = this->pathFind(robot.getPositionX(), robot.getPositionY(), 12, 4, robot.getCollisionMap());
        //this->goTo(robot, pathEnnemi);

         //Afficher les changements du canvas
	window.flip(1);

	return !quit;
}

//Gestion des évènements du clavier
void MapDisplayTestPathfinding::on_input_up(const clan::InputEvent &key)
{
	if(key.id == clan::keycode_escape)
	{
		quit = true;
	}
	
	//Déplacement manuel du robot
        switch (key.id) {
            case clan::keycode_up :
                this->robot.deplacer(0,-1);
                break;
            case clan::keycode_down :
                this->robot.deplacer(0,1);
                break;
            case clan::keycode_left :
                this->robot.deplacer(-1,0);
                break;
            case clan::keycode_right :
                this->robot.deplacer(1,0);
                break;
        }
}

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
