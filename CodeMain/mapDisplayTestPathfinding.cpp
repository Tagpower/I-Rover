
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
	sc.connect(window.get_keyboard().sig_key_up(), clan::bind_member(this, &MapDisplayTestPathfinding::on_input_up));

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
        Mine mine(4,4,sprite_mine); 
        Armure armure(5,"lol");
        this->robot = Robot(0,0,mine, armure, sprite_robot);
        this->robot.setCollisionMap(this->map.getCollisionMap());

        this->liste_coffres = vector<Coffre>();
        this->liste_coffres.push_back(Coffre(5,5,sprite_coffreF));
        this->liste_coffres.push_back(Coffre(7,7,sprite_coffreF));


        this->liste_clefs = vector<Clef>();
        this->liste_clefs.push_back(Clef(2,8,sprite_clef));
        this->liste_clefs.push_back(Clef(12,6,sprite_clef));


        this->liste_ennemis = vector<Ennemi>();
        this->liste_ennemis.push_back(Ennemi(14,10,mine, armure,sprite_ennemi_1));
        this->liste_ennemis.push_back(Ennemi(8,14,mine, armure,sprite_ennemi_1));



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

        robot.draw(canvas, map_origin.x + (robot.getPositionX()*tileset.getTile_width()) ,
                                 map_origin.y + (robot.getPositionY()*tileset.getTile_height()));

		//std::string pathRobot = pathFind(robot.getPositionX(), robot.getPositionY(), 12, 4, robot.getCollisionMap());
		//MapDisplayTestPathfinding::goTo(robot, pathRobot);

        //std::string pathEnnemi = this->pathFind(robot.getPositionX(), robot.getPositionY(), 12, 4, robot.getCollisionMap());
        //this->goTo(robot, pathEnnemi);
		this->explorationRobot(this->robot, this->liste_clefs, this->liste_coffres);
		this->explorationEnnemi(this->liste_ennemis[0]);
         //Afficher les changements du canvas
	window.flip(1);

	return !quit;
}



/**
 * Méthode permattant à un personnage d'aller vers une direction en particulier.
 * @param [in] perso Le personnage se déplaçant.
 * @param [in] path le chemin est modifie
 */
void MapDisplayTestPathfinding::goTo(Personnage perso, std::string path){
	while (path.length()>0){
			int dirToGo= path.at(0);
			switch(dirToGo){
				case 0:
					perso.deplacer(1,0);
					sleep(1000);
					break;
				case 1:
					perso.deplacer(0,-1);
					sleep(1000);
					break;
				case 2:
					perso.deplacer(-1,0);
					sleep(1000);
					break;
				case 3:
					perso.deplacer(0,1);
					sleep(1000);
					break;
				default:
					break;

				path.erase(0,1);
			}
}
}
/*!
 * Routine d'exploration d'un ennemi
 * @param [in] ennemi l'ennemi qui explore la carte de façon aléatoire
 */ 
void MapDisplayTestPathfinding::explorationEnnemi(Ennemi ennemi){
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
/*!
 * Routine d'exploration du robot
 * @param [in] robot, le robot qui explore
 * @param [in] liste_clefs
 * @param [in] liste_coffres
 */
void MapDisplayTestPathfinding::explorationRobot(Robot robot, vector<Clef> liste_clefs, vector<Coffre> liste_coffres  ){
	while((robot.inventaire==0){
		Clef cibleClef= findNearestKey(robot, liste_clefs);
		std::string path= astar::pathfind(robot.getPositionX(), robot.getPositionY(), cibleClef.getPositionX(), cibleClef.getPositionY(), robot.getCollisionMap());
		goTo(robot, path);
		}
	if(robot.inventaire>0){
		Coffre cibleCoffre = findNearestChest(robot,liste_coffres);
		std::string path= astar::pathfind(robot.getPositionX(), robot.getPositionY(), cibleCoffre.getPositionX(), cibleCoffre.getPositionY(), robot.getCollisionMap());
		goTo(robot, path);
	}	
}
/*!
 * Recherche de la clé la plus proche par distance euclidienne
 * @param [in] robot, le robot qui explore
 * @param [in] liste_clefs
 * @return foundKey la clé la plus proche
 */
Clef findNearestKey(Robot robot, vector<Clef> liste_clefs ){
Clef foundKey;
int distMin;
	if(liste_clefs.size()!=0){
		foundKey=liste_clefs[0];
			int xd, yd;
            xd=robot.getPositionX() - foundKey.getPositionX();
            yd=robot.getPositionY() - foundKey.getPositionY();         

            distMin=<int>(sqrt(xd*xd+yd*yd));

            return(dist);
		for (int i =0;i<liste_clefs.size(), i++){
			int xd, yd, dist;
            xd=robot.getPositionX() - liste_clefs[i].getPositionX();
            yd=robot.getPositionY() - liste_clefs[i].getPositionY();         

            dist=<int>(sqrt(xd*xd+yd*yd));
            if(dist<distMin){
				foundKey=liste_clefs[i];
				distMin=dist;
			}
		}
	}
	
return	foundKey;
}

/*!
 * Recherche de la clé la plus proche par distance euclidienne
 * @param [in] robot, le robot qui explore
 * @param [in] liste_coffres
 * @return foundChest le coffre le plus proche
 */
Coffre findNearestChest(Robot robot, vector<Coffre> liste_coffres ){
Coffre foundChest;
int distMin;
	if(liste_coffres.size()!=0){
		foundChest=liste_coffres[0];
			int xd, yd;
            xd=robot.getPositionX() - foundChest.getPositionX();
            yd=robot.getPositionY() - foundChest.getPositionY();         

            distMin=<int>(sqrt(xd*xd+yd*yd));

            return(dist);
		for (int i =0;i<liste_coffres.size(), i++){
			int xd, yd, dist;
            xd=robot.getPositionX() - liste_coffres[i].getPositionX();
            yd=robot.getPositionY() - liste_coffres[i].getPositionY();         

            dist=<int>(sqrt(xd*xd+yd*yd));
            if(dist<distMin){
				foundChest=liste_coffres[i];
				distMin=dist;
			}
		}
	}
	
return	foundChest;
}

