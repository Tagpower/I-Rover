/* 
 * File:   tileset.cpp
 * Author: clement
 * 
 * Created on 7 décembre 2015, 11:04
 */

#include <sstream>
#include "tileset.hpp"

Tileset::Tileset() {
    
}

Tileset::Tileset(clan::Image tilesheet, int h, int w, int tile_h, int tile_w, int spacing) {
    this->tilesheet = tilesheet;
    this->height = h;
    this->width = w;
    this->tile_height = tile_h;
    this->tile_width = tile_w;
    this->spacing = spacing;
    
}

Tileset::Tileset(clan::Image tilesheet, std::string tmxFile) { //Buggé. Trouver un moyen de transformer std::string en int
    clan::File mapTmx(tmxFile);
    clan::DomDocument doc;
    doc.load(mapTmx);

    clan::DomElement map_node(doc.get_document_element());
    clan::DomNode tileset_data_node(map_node.get_elements_by_tag_name("tileset").item(0));
    clan::DomNamedNodeMap tileset_attributes(tileset_data_node.get_attributes());
    
    this->tilesheet = tilesheet;
    this->tile_height = stoi(tileset_attributes.get_named_item("tileheight").get_node_value());
    this->tile_width = stoi(tileset_attributes.get_named_item("tilewidth").get_node_value());
    this->spacing = stoi(tileset_attributes.get_named_item("spacing").get_node_value());
    
    this->height = (int)tilesheet.get_height()/(tile_height+spacing)+1;
    this->width = (int)tilesheet.get_width()/(tile_width+spacing) +1;
    
    
}

Tileset::Tileset(const Tileset& orig) {
    this->tilesheet = orig.tilesheet;
    this->height = orig.height;
    this->width = orig.width;
    this->tile_height = orig.tile_height;
    this->tile_width = orig.tile_width;
    this->spacing = orig.spacing;
}

Tileset::~Tileset() {
}

void Tileset::drawTile(clan::Canvas c, int id, int x, int y) {
    clan::Point coords_src( (id-1) % width * (tile_width  + spacing),
                            (id-1) / width * (tile_height + spacing)); //Récupération dans le tileset des coordonnées du tile à dessiner     
    clan::Rect source(coords_src, clan::Size(tile_width, tile_height)); //Rectange à dessiner, provenant du tileset
    
    clan::Point coords_dest(x,y);
    clan::Rect dest(coords_dest, clan::Size(tile_width, tile_height)); //Rectangle où dessiner le tile, dans le canvas
    
    tilesheet.draw(c, source, dest);
}

