#include "Inventory.h"
#include "ofGraphics.h"

void Inventory::init(float x, float y) {
	this->x = x;
	this-> y = y;
	emptySlot.load("empty.png");

	for (int i = 0; i < 5; i++) {
		items[i].start(x + i*(32 + 15), y, 32, 32, EMPTY, &emptySlot);
	}
}

void Inventory::addItem(Tile *tile) {
	for (int i = 0; i < 5; i++) {
		if (items[i].type == EMPTY) {
			items[i].type = tile->type;
			items[i].image = tile->image;
			return;
		}
	}
}

int Inventory::useItem(int index) {
	if (index >= 0 && index < 5) {
		return items[index].type;
	}
	return EMPTY;
}

void Inventory::removeItem(int index) {
	if (index >= 0 && index < 5) {
		items[index].type = EMPTY;
		items[index].image = &emptySlot;
	}
}

void Inventory::draw(){
	for (int i = 0; i < 5; i++) {
	ofSetColor(255);
		items[i].draw();
		float x = items[i].x + 16;
		float y = items[i].y + 16;
		ofDrawBitmapString(i + 1, x, y);
	}
}
