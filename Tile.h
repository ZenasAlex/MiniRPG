#pragma once
#include "ofImage.h"
#include "ofRectangle.h"

enum {FLOOR, WALL, HP_POTION, MANA, KEY, SWORD, STAFF, EMPTY, ENEMY};

class Tile {
public:
	float x;
	float y;
	float width;
	float height;
	int type;
	bool active;
	ofImage *image;

	//Tile();
	//Tile(float x, float y, float width, float height, ofImage *img);
	//~Tile();

	void start(float x, float y, float width, float height, int type, ofImage *img);
	void draw();
	bool intersects(float px, float py, float pw, float ph);
};
