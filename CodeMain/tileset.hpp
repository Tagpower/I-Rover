/* 
 * File:   tileset.hpp
 * Author: clement
 *
 * Created on 7 décembre 2015, 11:04
 */

#include "precomp.hpp"

#ifndef TILESET_HPP
#define	TILESET_HPP

using namespace std;

class Tileset {
public:
    Tileset();
    Tileset(clan::Image tilesheet, int h, int w, int tile_h, int tile_w, int spacing);
    Tileset(clan::Image tilesheet, std::string tmxFile);
    Tileset(const Tileset& orig);
    virtual ~Tileset();
    
    int getTile_height() const {
        return tile_height;
    }

    int getTile_width() const {
        return tile_width;
    }

    
    void drawTile(clan::Canvas c, int id, int x, int y);
    
private:
    int height;
    int width;
    int tile_height;
    int tile_width;
    int spacing;
    
    clan::Image tilesheet;

};

#endif	/* TILESET_HPP */

