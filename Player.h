#pragma once
#include "ofImage.h"
#include "ofVec2f.h"

enum Direction {UP, DOWN, LEFT, RIGTH};

class Player {
public:
	float x;
	float y;
	float w;
	float h;
	ofVec2f swordPosition;
	//ofVec2f initPos;
	float swordRadius;
	bool hasSword;
	float acumulator;
	float currentTime;
	float timer;
	bool cooldown;
	Direction direction;
	ofVec2f center;
	float speedX;
	float speedY;
	bool up;
	bool down;
	bool left;
	bool right;
	ofImage imgRight;
	ofImage imgLeft;
	ofImage imgUp;
	ofImage imgDown;
	int HP;
	int MP;
	int maxHP;
	int maxMP;
	ofImage emptyHeart;
	ofImage fullHeart;
	ofImage emptyMN;
	ofImage fullMN;
	float HPMeter_x;
	float HPMeter_y;
	float MNMeter_x;
	float MNMeter_y;

	void start(float x, float y, float width, float height);
	void update();
	void draw();
	void attack();
	void stop();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void stopUp();
	void stopDown();
	void stopRight();
	void stopLeft();
	void hit();
	void HPUp();
	void MPUp();
	void dead();
};
