#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofxGuiEnableHiResDisplay();

	stepper.setup();

	gui.setup();
	gui.add(stepper.x_offset.set("x", 150, -175, 175));
	gui.add(stepper.y_offset.set("y", -90, -175, 175));
}

//--------------------------------------------------------------
void ofApp::update(){
	stepper.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(ofColor::antiqueWhite);
	gui.draw();
	ofTranslate(ofGetWidth() / 2., ofGetHeight() / 2.);
	stepper.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch(key) {
		case 'a':
			stepper.setCoilA(true);
			break;
		case 'b':
			stepper.setCoilB(true);
			break;
		case ' ':
			stepper.setDirection(true);
			break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	switch(key) {
		case 'a':
			stepper.setCoilA(false);
			break;
		case 'b':
			stepper.setCoilB(false);
			break;
		case ' ':
			stepper.setDirection(false);
			break;
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
