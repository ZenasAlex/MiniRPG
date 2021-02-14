#include "Tile.h"
#include "ofGraphics.h"

/*Tile::Tile(){
	x = 0;
	y = 0;
	width = 0;
	height = 0;
	image = NULL;
}

Tile::Tile(float x, float y, float width, float height, int type, ofImage * img) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->type = type;
	image = img;
}

Tile::~Tile(){
	cout << "Se destruyo el tile" << endl;
}*/

void Tile::start(float x, float y, float width, float height, int type, ofImage *img){
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->type = type;
	image = img;
	active = true;
}

void Tile::draw(){
	ofSetColor(255);
	if (image != NULL && active) {
		image->draw(x, y, width, height);
	}
}

bool Tile::intersects(float px, float py, float pw, float ph)
{
	return (x < px + pw && x + width > px && y < py + ph && y + height > py);
}
