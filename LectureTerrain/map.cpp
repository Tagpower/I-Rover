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
Map::Map(int height, int width) {
    this->height = height;
    this->width = width;
    
}

/*! Création d'une carte par copie d'une autre
 *
 */
Map::Map(const Map& orig) {
    this->height = orig->height;
    this->width = orig->width;
    this->tiles = orig->tiles;
}

Map::~Map() {
    ~tiles();
}

Map::getHeight() {
    return this->height;
}

Map::getWidth() {
    return this->width;
}

Map::getTiles() {
    return this->tiles;
}

Map::getTileAt(int x, int y) {
    return this->tiles[x*this->width + y - 1];
}

Map::setTileAt(int x, int y, int tile) {
    this->tiles[x*this->width + y - 1] = tile;
}

Map::readTmxFile(std::string file) {
    //TODO parser le fichier .tmx pour remplir le tableau de tiles.
    
    
    
}


