#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	prevPosX = 0;
	prevPosY = 0;
	player.start(50, 150, 32, 32);
	map.setPlayer(&player);
	map.loadMap("level 1.csv");
	inventory.init(34.5, 32);
	
}

//--------------------------------------------------------------
void ofApp::update(){
	map.update();
	player.update();
	bool isColliding = map.testPlayerCollision(player.x-3, player.y-3, player.w, player.h);

	if (isColliding) {
		player.stop();
		player.x = prevPosX;
		player.y = prevPosY;
	}
	else {
		prevPosX = player.x;
		prevPosY = player.y;
	}
	Tile *item = map.testItemCollisions(player.x, player.y, player.w, player.h);
	if (item != NULL) {
		inventory.addItem(item);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	map.draw();
	player.draw();
	inventory.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 'w') {
		player.moveUp();
	}
	else if (key == 's') {
		player.moveDown();
	}

	if (key == 'a') {
		player.moveLeft();
	}
	else if (key == 'd') {
		player.moveRight();
	}
	if (key == '1' || key == '2' || key == '3' || key == '4' || key == '5') {
		char c = key;
		string index = ofToString(c);
		int i = ofToInt(index) - 1;
		int type = inventory.useItem(i);
		if (type == HP_POTION) {
			player.HPUp();
			inventory.removeItem(i);
		}
		else if (type == MANA) {
			player.MPUp();
			inventory.removeItem(i);
		}
		else if (type == SWORD) {

		}
		else if (type == STAFF) {

		}
	}
	if (key == ' ') {
		player.attack();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == 'w' || key == 'W') {
		player.stopUp();
	}
	else if (key == 's' || key == 'S') {
		player.stopDown();
	}

	if (key == 'a' || key == 'A') {
		player.stopLeft();
	}
	else if (key == 'd' || key == 'D') {
		player.stopRight();
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
