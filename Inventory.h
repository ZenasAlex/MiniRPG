#pragma once
#include "Tile.h"
#include "ofImage.h"
#include "ofGraphics.h"

class Inventory {
public:
	float x;
	float y;
	Tile items[5];
	ofImage emptySlot;

	void init(float x, float y);
	void addItem(Tile *tile);
	int useItem(int index);
	void removeItem(int index);
	void draw();
};
