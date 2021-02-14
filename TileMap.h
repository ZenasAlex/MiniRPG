#pragma once
#include "Tile.h"
#include "FileReader.h"
#include "ofImage.h"
#include "Enemy.h"
#include "Player.h"

#define ROWS 24
#define COLS 32

class TileMap {
public:
	float tileWidth;
	float tileHeight;
	Tile tiles[ROWS][COLS];
	vector<Tile> items;
	vector<Enemy> enemies;
	Player *player;
	ofImage muro;
	ofImage piso;
	ofImage healthPt;
	ofImage manaPt;
	ofImage key;
	ofImage sword;
	ofImage staff;

	void loadMap(string fileName);
	void setPlayer(Player *hero);
	void update();
	void draw();
	bool testPlayerCollision(float x, float y, float width, float height);
	Tile* testItemCollisions(float x, float y, float width, float height);
};
