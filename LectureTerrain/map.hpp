/* 
 * File:   map.hpp
 * Author: clement
 *
 * Created on 20 novembre 2015, 19:22
 */

#ifndef MAP_HPP
#define	MAP_HPP

#include <ClanLib/core.h>
#include <ClanLib/application.h>
#include <ClanLib/display.h>
#include <ClanLib/xml.h>
#include <ClanLib/gl.h>
#include <cmath>
#include <vector>

using namespace std;

class Map {
public:
    Map(int height, int width, int tile_size);
    Map(const Map& orig);
    virtual ~Map();
    
    int getHeight();
    int getWidth();
    vector<vector<int>> getTiles();
    int getTileAt(int x, int y);
    void setTileAt(int x, int y, int tile);
    int getTileSize();
    
    void readTmxFile(std::string file);
    void drawMap();
    
private:
    //! Hauteur de la carte en cases     
    int height;
    //! Largeur de la carte en cases
    int width;
    //! Matrice contenant les cases de la carte et leur type
    vector<vector<int>> tiles;
    //! Taille d'une case en pixels
    int tile_size;
    //! Image où récupérer les textures des cases
    clan::Image tileset;
};

#endif	/* MAP_HPP */
    