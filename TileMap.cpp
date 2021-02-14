#include "TileMap.h"
#include "ofGraphics.h"

void TileMap::loadMap(string fileName){
	muro.load("wall.png");
	piso.load("piso.png");
	healthPt.load("HP.png");
	manaPt.load("MN.png");
	key.load("key.png");
	sword.load("sword.png");
	staff.load("staff.png");

	tileWidth = 32;
	tileHeight = 32;

	vector<string> lines = FileReader::readFile(fileName);

	for (int i = 0; i < lines.size(); i++) {
		cout << lines[i] << endl;
	}

	for (int i = 0; i < ROWS; i++) {
		string line = lines[i];
		vector<string> tilesIndex = ofSplitString(line, ",");
		for (int j = 0; j < COLS; j++) {
			int index = ofToInt(tilesIndex[j]);
			if (index != WALL) {
				tiles[i][j].start(j*tileWidth, i*tileHeight, tileWidth, tileHeight, index, &piso);
			}
			else if (index == WALL) {
				tiles[i][j].start(j*tileWidth, i*tileHeight, tileWidth, tileHeight, index, &muro);
			}

			if (index == HP_POTION) {
				Tile tile;
				tile.start(j*tileWidth, i*tileHeight, tileWidth, tileHeight, index, &healthPt);
				items.push_back(tile);
			}
			else if (index == MANA) {
				Tile tile;
				tile.start(j*tileWidth, i*tileHeight, tileWidth, tileHeight, index, &manaPt);
				items.push_back(tile);
			}
			else if (index == KEY) {
				Tile tile;
				tile.start(j*tileWidth, i*tileHeight, tileWidth, tileHeight, index, &key);
				items.push_back(tile);
			}
			else if (index == SWORD) {
				Tile tile;
				tile.start(j*tileWidth, i*tileHeight, tileWidth, tileHeight, index, &sword);
				items.push_back(tile);
			}
			else if (index == STAFF) {
				Tile tile;
				tile.start(j*tileWidth, i*tileHeight, tileWidth, tileHeight, index, &staff);
				items.push_back(tile);
			}
			else if (index == ENEMY) {
				Enemy enemy;
				enemy.init(j*tileWidth, i*tileHeight, tileWidth, tileHeight, player);
				enemies.push_back(enemy);
			}
		}
	}
}

void TileMap::setPlayer(Player * hero)
{
	player = hero;
}

void TileMap::update()
{
	for (Enemy &e : enemies) {
		e.update();
	}
}

void TileMap::draw(){
	for(int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			tiles[i][j].draw();
		}
	}

	for (Tile &a : items) {
		a.draw();
	}
	for (Enemy &e : enemies) {
		e.draw();
	}
}

bool TileMap::testPlayerCollision(float x, float y, float width, float height)
{
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			if (tiles[i][j].intersects(x, y, width, height)) {
				if (tiles[i][j].type == WALL) {
					return true;
				}
			}
		}
	}
	return false;
}

Tile* TileMap::testItemCollisions(float x, float y, float width, float height){
	for(Tile &item : items) {
		if (item.intersects(x, y, width, height) && item.active) {
			item.active = false;
			return &item;
		}
	}

	return NULL;
}
