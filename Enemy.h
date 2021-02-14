#pragma once
#include "ofVec2f.h"
#include "ofImage.h"
#include "Player.h"

enum EnemyState{PATROL, FOLLOW, ATTACK};

class Enemy {
public:
	ofVec2f pos;
	float w;
	float h;
	float velx;
	float vely;
	ofVec2f initPos;
	ofVec2f finalPos;
	ofVec2f targetPos;
	ofVec2f targetSize;
	float followRadius;
	float attackRadius;
	string strState;
	float dist;
	EnemyState state;
	ofImage imgRight;
	ofImage imgLeft;
	ofImage *currentImg;
	int dir;
	Player *player;
	float currentTime;
	float timer;
	float acumulator;
	bool cooldown;

	void init(float x, float y, float w, float h, Player *hero);
	void update();
	void draw();
	void patrol();
	void follow();
	void attack();
};