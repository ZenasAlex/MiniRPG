#include "Player.h"
#include "ofGraphics.h"
#include "ofAppRunner.h"

void Player::start(float x, float y, float width, float height){
	this->x = x;
	this->y = y;
	this->w = width;
	this->h = height;
	center.set(x + w / 2, y + h / 2);
	//initPos.set(x, y);
	swordRadius = 15;
	cooldown = 2;
	currentTime = ofGetElapsedTimeMillis();
	speedX = 4;
	speedY = 4;
	up = false;
	down = false;
	left = false;
	right = false;
	imgRight.load("PersonajeRight.png");
	imgLeft.load("PersonajeLeft.png");
	imgUp.load("PersonajeUp.png");
	imgDown.load("PersonajeDown.png");
	imgRight.resize(width, height);
	imgLeft.resize(width, height);
	imgDown.resize(width, height);
	imgUp.resize(width, height);
	emptyHeart.load("heart vacio.png");
	emptyHeart.resize(width, height);
	fullHeart.load("heart.png");
	fullHeart.resize(width, height);
	emptyMN.load("mana vacio.png");
	emptyMN.resize(width, height);
	fullMN.load("mana.png");
	fullMN.resize(width, height);
	HPMeter_x = 700;
	HPMeter_y = 1;
	MNMeter_x = 700;
	MNMeter_y = 61;
	maxHP = 5;
	maxMP = 5;
	HP = 5;
	MP = 5;
}

void Player::update(){
	float deltaTime = ofGetElapsedTimeMillis() - currentTime;
	acumulator += deltaTime;
	currentTime = ofGetElapsedTimeMillis();
	if (acumulator > timer) {
		cooldown = true;
	}
	if (up) {
		y -= speedY;
		direction = UP;
	}
	else if (down) {
		y += speedY;
		direction = DOWN;
	}

	if (right) {
		x += speedX;
		direction = LEFT;
	}
	else if (left) {
		x -= speedX;
		direction = RIGTH;
	}
	center.set(x + w / 2, y + h / 2);
}

void Player::draw(){
	ofSetColor(255);
	if (imgDown.isAllocated()) {
		imgDown.draw(x, y);
	}
	for (int i = 0; i < maxHP; i++) {
		emptyHeart.draw(HPMeter_x + i *(32 + 10), HPMeter_y);
	}
	for (int i = 0; i < HP; i++) {
		fullHeart.draw(HPMeter_x + i *(32 + 10), HPMeter_y);
	}
	for (int i = 0; i < maxMP; i++) {
		emptyMN.draw(MNMeter_x + i *(32 + 10), MNMeter_y);
	}
	for (int i = 0; i < MP; i++) {
		fullMN.draw(MNMeter_x + i *(32 + 10), MNMeter_y);
	}
	ofNoFill;
	if (!cooldown) {
		switch (direction) {
		case UP:
			ofDrawCircle(center.x, center.y - h / 2 - swordRadius, swordRadius);
			break;
		case DOWN:
			ofDrawCircle(center.x, center.y + h / 2 + swordRadius, swordRadius);
			break;
		case LEFT:
			ofDrawCircle(center.x-w / 2 - swordRadius, center.y, swordRadius);
			break;
		case RIGTH:
			ofDrawCircle(center.x+w / 2 + swordRadius, center.y, swordRadius);
			break;
		}
	}

}

void Player::attack()
{
	if (cooldown == true) {
		acumulator = 0;
		cooldown = false;
	}
	if (MP > 0) {
		MP--;
	}
}

void Player::stop(){
	up = false;
	down = false;
	left = false;
	right = false;
}

void Player::moveUp(){
	up = true;
}

void Player::moveDown(){
	down = true;
}

void Player::moveLeft(){
	left = true;
}

void Player::moveRight(){
	right = true;
}

void Player::stopUp(){
	up = false;
}

void Player::stopDown(){
	down = false;
}

void Player::stopRight(){
	right = false;
}

void Player::stopLeft(){
	left = false;
}

void Player::hit()
{
	if (HP > 0) {
		HP--;
	}
}

void Player::HPUp()
{
	if (HP < maxHP) {
		HP++;
	}
}

void Player::MPUp()
{
	if (MP < maxMP) {
		MP = 5;
	}
}

/*void Player::dead()
{
	if (HP <= 0) {
		initPos.set(50, 150);
	}
}*/
