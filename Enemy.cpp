#include "Enemy.h"
#include "ofGraphics.h"
#include "ofAppRunner.h"


void Enemy::init(float x, float y, float w, float h, Player *hero)
{
	pos.set(x, y);
	player = hero;
	this->w = w;
	this->h = h;
	imgLeft.load("EnemigoRight.png");
	imgRight.load("EnemigoLeft.png");
	//imgLeft.mirror(false, true);
	//currentImg = &imgLeft;
	state = PATROL;
	strState = "Patrol";
	initPos.set(x, y);
	finalPos.set(x + (32 * 3), y);
	velx = 3;
	vely = 3;
	followRadius = 64;
	attackRadius = 16;
	dir = 1;
	currentTime = ofGetElapsedTimeMillis();
	acumulator = 0;
	timer = 2000;
	cooldown = false;
}

void Enemy::update()
{
	targetPos.set(player->x + player->w/2, player->y + player->h/2);
	targetSize.set(player->w, player->h);
	float deltaTime = ofGetElapsedTimeMillis() - currentTime;
	acumulator += deltaTime;
	currentTime = ofGetElapsedTimeMillis();
	if (acumulator > timer) {
		acumulator = 0;
		cooldown = false;
		
	}
	/*if (player->isAttack) {

	}*/

	switch (state) {
	case PATROL:
		patrol();
		break;
	case FOLLOW:
		follow();
		break;
	case ATTACK:
		attack();
		break;
	}
}

void Enemy::draw()
{
	ofSetColor(255);
	if (dir == 1) {
		imgRight.draw(pos.x, pos.y);
	}
	else if (dir == -1) {
		imgLeft.draw(pos.x, pos.y);
	}
	ofSetColor(0);
	ofNoFill();
	ofDrawCircle(pos.x + w/2, pos.y + h/2, followRadius);
	ofDrawCircle(pos.x + w / 2, pos.y + h / 2, attackRadius);
	ofDrawBitmapString(strState, pos.x + w, pos.y);
}

void Enemy::patrol()
{
	ofVec2f center(pos.x + w / 2, pos.y + h / 2);
	float dist = ofDist(targetPos.x, targetPos.y, center.x, center.y);

	if (dist < followRadius + targetSize.x / 2) {
		state = FOLLOW;
		strState = "FOLLOW";

	}
	if (pos.x > finalPos.x) {
		dir = -1;
	}
	else if (pos.x < initPos.x) {
		dir = 1;
	}
	pos.x += velx*dir;
}

void Enemy::follow()
{
	ofVec2f center(pos.x + w / 2, pos.y + h / 2);
	float dist = ofDist(targetPos.x, targetPos.y, center.x, center.y);

	if (dist > followRadius + targetSize.x / 2) {
		state = PATROL;
		strState = "PATROL";
		initPos.set(pos.x, pos.y);
		finalPos.set(pos.x + (32 * 3), pos.y);
	}
	
	if (targetPos.x > center.x) {
		dir = 1;
	}
	else {
		dir = -1;
	}

	if (dist < w / 2 + targetSize.x / 2) {
		state = ATTACK;
		strState = "Attack";
	}
		ofVec2f vel = center - targetPos;
		vel.normalize();
		pos -= vel*velx;
}

void Enemy::attack()
{
	ofVec2f center(pos.x + w / 2, pos.y + h / 2);
	float dist = ofDist(targetPos.x, targetPos.y, center.x, center.y);
	if (dist > w / 2 + targetSize.x / 2) {
		state = FOLLOW;
		strState = "Follow";
	}
	if (!cooldown) {
		player->hit();		
		acumulator = 0;
		cooldown = true;
	}
}
