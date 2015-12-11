/*! 
 * \brief Construit et dessine une carte.
 * \details 
 * \author Clément Bauchet
 * \version 1
 * \date 20 novembre 2015, 19:22
 */

#include <sstream>
#include <algorithm>
#include "map.hpp"

/*!
 * Constructeur de la map par défaut.
 * @return la Map créée.
 */ 
Map::Map() {
    
}

/*! 
 * Création d'une carte de taille donnée.
 * @param [in] height La hauteur de la map à créer.
 * @param [in] width La largeur de la map à créer.
 * @param [in] tileset Le tileset à charger pour dessiner la map.
 * @param [out] height La hauteur de la map en cases.
 * @param [out] width La largeur de la map en cases.
 * @param [out] tiles La matrice des cases de la carte
 * @param [out] collision_map La matrice de collision de la carte
 * @param [out] tileset Le tileset utilisé pour dessiner la map.
 * @param [out] tile_size la taille en pixels des cases du tileset utilisé (en supposant les tiles carrés).
 * @return la Map créée.
 */
Map::Map(int height, int width, Tileset tileset) {
    this->height = height;
    this->width = width;
    this->tiles = vector<vector<int>>(height, vector<int>(width));
    this->collision_map = vector<vector<int>>(height, vector<int>(width));
    this->tileset = tileset;
    this->tile_size = tileset.getTile_height();
}

/*! 
 * Création d'une carte par copie d'une autre
 * @author Clément Bauchet
 * @param [in] orig La Map à copier.
 * @param [out] height La hauteur de la map.
 * @param [out] width La largeur de la map.
 * @param [out] tiles La matrice des cases de la carte
 * @param [out] collision_map La matrice de collision de la carte
 * @param [out] tileset Le tileset utilisé pour dessiner la map.
 * @param [out] tile_size la taille en pixels des cases du tileset utilisé (en supposant les tiles carrés).
 * @return la Map créée.
 */
Map::Map(const Map& orig) {
    this->height = orig.height;
    this->width = orig.width;
    this->tiles = orig.tiles;
    this->collision_map = orig.collision_map;
    this->tileset = orig.tileset;
    this->tile_size = orig.tile_size;
}

/**
 * Création d'une carte à partir du seul fichier .tmx
 * @param [in] tmxFile le fichier au format .tmx contenant les données de la carte.
 * @param [in] tileset le tileset contenant les tiles à dessiner.
 * @param [out] height La hauteur de la map.
 * @param [out] width La largeur de la map.
 * @param [out] tileset Le tileset utilisé pour dessiner la map.
 * @param [out] tile_size la taille en pixels des cases du tileset utilisé (en supposant les tiles carrés).
 * @param [out] tiles La matrice des cases de la carte
 */
Map::Map(std::string tmxFile, Tileset tileset) {
    
      //Création d'un document DOM pour lire les données au format XML
      clan::File mapTmx(tmxFile);
      clan::DomDocument doc;
      doc.load(mapTmx);
    
      clan::DomElement map_node(doc.get_document_element());      
      clan::DomNode layer_data_node(map_node.get_child_nodes().item(1).get_first_child());
      clan::DomNodeList all_tiles(layer_data_node.get_child_nodes());
        
      this->height = map_node.get_attribute_int("height") ;
      this->width = map_node.get_attribute_int("width") ;
      
      this->tileset = tileset;
      this->tile_size = tileset.getTile_height();
      
      this->tiles = vector<vector<int>>(height, vector<int>(width));
      this->collision_map = vector<vector<int>>(height, vector<int>(width));
      
      //Remplissage de la matrice de tiles
      int id;
      for(int i=0; i < this->height; i++) {
          for(int j=0; j < this->width; j++) {
              clan::DomString tile_id = all_tiles.item(i*this->width+j).get_attributes().get_named_item("gid").get_node_value();
              cout << tile_id << " ";
              id = stoi(tile_id);
              setTileAt(i, j, id);
          }
          cout << endl;
      }
      
      
      
}

/*!
 * Destructeur de la map.
 */ 
Map::~Map() {
    tiles.clear();
}

/*!
 * Getter de l'attribut height.
 * @return height La hauteur de la carte en cases.
 */ 
int Map::getHeight() {
    return this->height;
}

/*!
 * Getter de l'attribut width.
 * @return width La largeur de la carte en cases.
 */ 
int Map::getWidth() {
    return this->width;
}

/*!
 * Getter de l'attribut tiles.
 * @return tiles La matrice des cases de la carte.
 */ 
vector<vector<int>> Map::getTiles() {
    return this->tiles;
}

/*!
 * Getter de l'attribut tile_size.
 * @return tile_size La taille en pixels des cases (en supposant les cases carrées).
 */ 
int Map::getTileSize() {
    return this->tile_size;
}

/*!
 * Getter de la valeur de la case à une position donnée.
 * @param [in] row La ligne à laquelle se trouve la case.
 * @param [in] col La colonne à laquelel se trouve la case.
 * @return tiles Un entier représentant le type de case présent à la position (row, col).
 */ 
int Map::getTileAt(int row, int col) {
    return this->tiles[row][col];
}

/*!
 * Setter de l'attribut tiles. 
 * Modifie la case à une certaine position.
 * @param [in] row la ligne à laquelle se trouve la case à modifier.
 * @param [in] col la colonne à laquelle se trouve la case à modifier.
 * @param [in] tile la nouvelle valeur de la case à modifier.
 * @param [out] tiles la nouvelle valeur de la case en (row, col).
 */ 
void Map::setTileAt(int row, int col, int tile) {
    this->tiles[row][col] = tile;
}

/*!
 * Méthode qui permet de remplir la matrice de cases de la carte à partir d'un fichier XML.
 * @param [in] file Le nom du fichier à lire.
 */ 
void Map::readTmxFile(std::string file) {
      //Création d'un document DOM pour lire les données au format XML
      clan::File mapTmx(file);
      clan::DomDocument doc;
      doc.load(mapTmx);
    
      //Récupération des balises XML contenant les données
      clan::DomElement map_node(doc.get_document_element());
      clan::DomNode layer_data_node(map_node.get_child_nodes().item(1).get_first_child());
      clan::DomNodeList all_tiles(layer_data_node.get_child_nodes());
      
      //Remplissage de la matrice de tiles
      int id;
      for(int i=0; i < this->height; i++) {
          for(int j=0; j < this->width; j++) {
              clan::DomString tile_id = all_tiles.item(i*this->width+j).get_attributes().get_named_item("gid").get_node_value();
              cout << tile_id << " ";
              //istringstream (tile_id) >> id;
              id = stoi(tile_id);
              setTileAt(i, j, id);
          }
          cout << endl;
      }
   
}

/*!
 * Méthode qui retourne la matrice de collision de la carte.
 * @param [out] file La matrice de collision de la carte.
 */ 
vector<vector<int>> Map::getCollisionMap() {
    return this->collision_map;
}

/*!
 * Méthode qui établit la matrice de collision de la carte, en fonction d'une liste d'id de cases passables.
 * @param [out] file La matrice de collision de la carte.
 */ 
void Map::setCollisionMap(vector<int> passable_tiles) {
    
    for(int i=0; i < height; i++) {
        for (int j=0; j < width; j++) {
            
            if (std::find(passable_tiles.begin(), passable_tiles.end(), tiles[i][j]) != passable_tiles.end()) {
                this->collision_map[i][j] = 1;
            } else {
                this->collision_map[i][j] = 0;
            }
            cout << this->collision_map[i][j] << " ";
        }
        cout << endl;
    }
}

/*!
 * Dessine la carte dans le canvas.
 * @param [in] c le canvas dans lequel dessiner
 */ 
void Map::drawMap(clan::Canvas c) {
    
    for(int i=0; i < this->height; i++) {
        for (int j=0; j<this->width; j++) {
            this->tileset.drawTile(c, tiles.at(i).at(j), j*tile_size , i*tile_size);
        }
    }
}


/*!
 * Dessine la carte dans le canvas à une position donnée.
 * @param [in] c Le canvas dans lequel dessiner à une certaine position.
 * @param [in] x La coordonnée x de la position du canvas où dessiner  
 * @param [in] y La coordonnée y de la position du canvas où dessiner
 */ 
void Map::drawMap(clan::Canvas c, int x, int y) {
    
    for(int i=0; i < this->height; i++) {
        for (int j=0; j<this->width; j++) {
            this->tileset.drawTile(c, tiles.at(i).at(j), j*tile_size + x , i*tile_size + y);
        }
    }
}


