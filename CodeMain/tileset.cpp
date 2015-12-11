/*! 
 * \brief Classe représentant un tileset, c'est-à-dire la liste des images utilisées pour dessiner la carte et leurs informations.
 * \details 
 * \author Clément Bauchet
 * \version 1
 * \date 20 novembre 2015, 19:22
 */

#include <sstream>
#include "tileset.hpp"

/*!
 * Constructeur par défaut de la classe Tileset.
 * @return Tileset un objet Tileset vide.
 */ 
Tileset::Tileset() {
    
}

/*!
 * Constructeur de l'objet Tileset.
 * @param [in] tilesheet l'image contenant les tiles
 * @param [in] h la hauteur du tileset en tiles
 * @param [in] w la largeur du tileset en tiles
 * @param [in] tile_h la hauteur d'un tile en pixels
 * @param [in] tile_w la largeur d'un tile en pixels
 * @param [in] spacing l'espace entre chaque tile dans la tilesheet, en pixels
 * @return Tileset un objet Tileset avec les propriétés des valeurs en entrée.
 * 
 */ 
Tileset::Tileset(clan::Image tilesheet, int h, int w, int tile_h, int tile_w, int spacing) {
    this->tilesheet = tilesheet;
    this->height = h;
    this->width = w;
    this->tile_height = tile_h;
    this->tile_width = tile_w;
    this->spacing = spacing;
    
}

/*!
 * Constructeur de l'objet Tileset, par lecture du fichier de carte .tmx correspondant
 * @param [in] tilesheet l'image contenant les tiles
 * @param [in] tmxFile le nom du fichier de carte .tmx utilisant ce tileset
 * @return Tileset un objet Tileset avec les propriétés récupérées depuis le fichier .tmx.
 */ 
Tileset::Tileset(clan::Image tilesheet, std::string tmxFile) {
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

/*!
 * Constructeur de l'objet Tileset par copie d'un autre tileset
 * @return Tileset un objet Tileset identique à celui fourni en entrée
 */ 
Tileset::Tileset(const Tileset& orig) {
    this->tilesheet = orig.tilesheet;
    this->height = orig.height;
    this->width = orig.width;
    this->tile_height = orig.tile_height;
    this->tile_width = orig.tile_width;
    this->spacing = orig.spacing;
}

/*!
 * Destructeur de Tileset
 */ 
Tileset::~Tileset() {
}

/*!
 * Méthode dessinant une case du tileset à une position donnée 
 * @param [in] c le canvas où dessiner la case
 * @param [in] id le numéro dans le tileset de la tile à dessiner
 * @param [in] x la coordonnée x de la position où dessiner la case
 * @param [in] y la coordonnée y de la position où dessiner la case
 */ 
void Tileset::drawTile(clan::Canvas c, int id, int x, int y) {
    clan::Point coords_src( (id-1) % width * (tile_width  + spacing),
                            (id-1) / width * (tile_height + spacing)); //Récupération dans le tileset des coordonnées du tile à dessiner     
    clan::Rect source(coords_src, clan::Size(tile_width, tile_height)); //Rectange à dessiner, provenant du tileset
    
    clan::Point coords_dest(x,y);
    clan::Rect dest(coords_dest, clan::Size(tile_width, tile_height)); //Rectangle où dessiner le tile, dans le canvas
    
    tilesheet.draw(c, source, dest);
}

