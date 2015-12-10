/* 
 * File:   map.hpp
 * Author: clement
 *
 * Created on 20 novembre 2015, 19:22
 */

#ifndef MAP_HPP
#define	MAP_HPP

#include "precomp.hpp"
#include "tileset.hpp"
#include <vector>

using namespace std;

class Map {
public:
    Map();
    Map(int height, int width, Tileset tileset);
    Map(std::string tmxFile, Tileset tileset);
    Map(const Map& orig);
    virtual ~Map();
    
    int getHeight();
    int getWidth();
    vector<vector<int>> getTiles();
    int getTileAt(int x, int y);
    void setTileAt(int x, int y, int tile);
    int getTileSize();
    
    vector<vector<int>> getCollisionMap();
    void setCollisionMap(vector<int> passable_tiles);
    
    void readTmxFile(std::string file);
    void drawMap(clan::Canvas c);
    void drawMap(clan::Canvas c, int x, int y);
    
private:
    //! Hauteur de la carte en cases     
    int height;
    //! Largeur de la carte en cases
    int width;
    //! Matrice contenant les cases de la carte et leur type
    vector<vector<int>> tiles;
    //! Matrice contenant les informations sur la praticabilité des cases de la carte
    vector<vector<int>> collision_map;
    //! Taille d'une case en pixels
    int tile_size;
    //! Tileset comprenant l'image où récupérer les textures des cases et ses informations
    Tileset tileset;
    
    
};

#endif	/* MAP_HPP */
    