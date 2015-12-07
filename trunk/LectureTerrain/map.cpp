/* 
 * File:   map.cpp
 * Author: clement
 * 
 * Created on 20 novembre 2015, 19:22
 */

#include <sstream>
#include "map.hpp"

Map::Map() {
    
}

/*! Création d'une carte de taille donnée
 *
 * 
 */
Map::Map(int height, int width, Tileset tileset) {
    this->height = height;
    this->width = width;
    this->tiles = vector<vector<int>>(width, vector<int>(height));
    this->tileset = tileset;
    this->tile_size = tileset.getTile_height();
}

/*! Création d'une carte par copie d'une autre
 *
 */
Map::Map(const Map& orig) {
    this->height = orig.height;
    this->width = orig.width;
    this->tiles = orig.tiles;
    this->tileset = orig.tileset;
    this->tile_size = orig.tile_size;
}

Map::~Map() {
    tiles.clear();
}

int Map::getHeight() {
    return this->height;
}

int Map::getWidth() {
    return this->width;
}

vector<vector<int>> Map::getTiles() {
    return this->tiles;
}

int Map::getTileSize() {
    return this->tile_size;
}

int Map::getTileAt(int x, int y) {
    //return this->tiles[x*this->width + y - 1];
    return this->tiles[x][y];
}

void Map::setTileAt(int x, int y, int tile) {
    //this->tiles[x*this->width + y - 1] = tile;
    this->tiles[x][y] = tile;
}

void Map::readTmxFile(std::string file) {
    //TODO parser le fichier .tmx pour remplir la matrice de tiles.
      clan::File mapTmx(file);
      clan::DomDocument doc;
      doc.load(mapTmx);
    
      clan::DomElement map_node(doc.get_document_element());
      clan::DomNode layer_data_node(map_node.get_child_nodes().item(1).get_first_child());
      clan::DomNodeList all_tiles(layer_data_node.get_child_nodes());
      
      //Remplissage de la matrice de tiles
      int id;
      for(int i=0; i < this->height; i++) {
          for(int j=0; j < this->width; j++) {
              clan::DomString tile_id = all_tiles.item(i*this->height+j).get_attributes().get_named_item("gid").get_node_value();
              cout << tile_id << " ";
              istringstream (tile_id) >> id;
              setTileAt(i, j, id);
          }
          cout << endl;
      }
   
}

//Dessiner la carte dans le canvas
void Map::drawMap(clan::Canvas c) {
    
    for(int i=0; i < this->height; i++) {
        for (int j=0; j<this->width; j++) {
            this->tileset.drawTile(c, tiles.at(i).at(j), j*tile_size , i*tile_size);
        }
    }
}

//Dessiner la carte dans le à une position donnée
void Map::drawMap(clan::Canvas c, int x, int y) {
    
    for(int i=0; i < this->height; i++) {
        for (int j=0; j<this->width; j++) {
            this->tileset.drawTile(c, tiles.at(i).at(j), j*tile_size + x , i*tile_size + y);
        }
    }
}


