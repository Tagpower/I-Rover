/*! 
 * \brief construit et dessine une map.
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
 * @param [in] tileset Le tileset à charger pour construire la map.
 * @param [out] height La hauteur de la map.
 * @param [out] width La largeur de la map.
 * @param [out] tiles 
 * @param [out] tileset Le tileset utilisé pour la map.
 * @param [out] tile_size la tailel du tileset utilisé.
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
 * @param [out] tiles 
 * @param [out] tileset Le tileset utilisé pour la map.
 * @param [out] tile_size la tailel du tileset utilisé.
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
 * @param [out] height
 * @param [out] wifth
 * @param [out] tileset
 * @param [out] tile_size
 * @param [out] tiles
 */
Map::Map(std::string tmxFile, Tileset tileset) {
    
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
 * Méthode qui vide la map.
 */ 
Map::~Map() {
    tiles.clear();
}

/*!
 * Getter de l'attribut height.
 * @return height La valeur height de la classe Map.
 */ 
int Map::getHeight() {
    return this->height;
}

/*!
 * Getter de l'attribut width.
 * @return width La valeur width de la classe Map.
 */ 
int Map::getWidth() {
    return this->width;
}

/*!
 * Getter de l'attribut tiles.
 * @return tiles La valeur tiles de la classe Map.
 */ 
vector<vector<int>> Map::getTiles() {
    return this->tiles;
}

/*!
 * Getter de l'attribut tile_size.
 * @return tile_size La valeur tile_size de la classe Map.
 */ 
int Map::getTileSize() {
    return this->tile_size;
}

/*!
 * Getter de l'attribut height à une certaine position.
 * @param [in] row La ligne à laquelle se trouve le tiles.
 * @param [in] col La colonne à laquelel se trouve le tiles.
 * @return tiles La valeur tiles de la classe Map à la position (row, col).
 */ 
int Map::getTileAt(int row, int col) {
    return this->tiles[row][col];
}

/*!
 * Setter de l'attribut tiles. 
 * Modifie le tiles à une certaines position.
 * @param [in] row la ligne à laquelle se trouve le tile à modifier.
 * @param [in] col la colonne à laquelle se trouve le tile à modifier.
 * @param [in] tile la nouvelle valeur du tile à modifier.
 * @param [out] tiles Le nouveau tiles de l'objet en (row, col).
 */ 
void Map::setTileAt(int row, int col, int tile) {
    this->tiles[row][col] = tile;
}

/*!
 * Méthode qui permet de retourner un objet Map à partir d'un fichier XML.
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

vector<vector<int>> Map::getCollisionMap() {
    return this->collision_map;
}

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
 * @param [in] c
 * @param [out] tileset
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
 * @param [in] c Le canvas à dessiner à une certaine position.
 * @param [in] x
 * @param [in] y
 * @param [out] tileset
 */ 
void Map::drawMap(clan::Canvas c, int x, int y) {
    
    for(int i=0; i < this->height; i++) {
        for (int j=0; j<this->width; j++) {
            this->tileset.drawTile(c, tiles.at(i).at(j), j*tile_size + x , i*tile_size + y);
        }
    }
}


