/* 
 * File:   map.cpp
 * Author: clement
 * 
 * Created on 20 novembre 2015, 19:22
 */

#include "map.hpp"


/*! Création d'une carte de taille donnée
 *
 * 
 */
Map::Map(int height, int width, int tile_size) {
    this->height = height;
    this->width = width;
    this->tiles = vector<vector<int>>(width, vector<int>(height));
    this->tile_size = tile_size;    
}

/*! Création d'une carte par copie d'une autre
 *
 */
Map::Map(const Map& orig) {
    this->height = orig.height;
    this->width = orig.width;
    this->tiles = orig.tiles;
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
      //clan::DomDocument doc;
      //doc.load(mapTmx);
      
//    
//    clan::DomElement map_node(doc.get_document_element());
//    
//    std::cout << map_node.get_attribute_int("width") << std::endl;
    
    
   
}



