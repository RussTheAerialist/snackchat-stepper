#include "ofApp.h"

const int MAX_STEPS = number_points + 1;
#define FONT "Montserrat-Medium.ttf"
#define FONT_SIZE 12 * 5

//--------------------------------------------------------------
void ofApp::setup(){
	ofxGuiEnableHiResDisplay();
	font.load(FONT, FONT_SIZE);

	stepper.setup(font);

	gui.setup();
	gui.add(stepper.x_offset.set("x", 150, -175, 175));
	gui.add(stepper.y_offset.set("y", -90, -175, 175));
	step_show = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
	stepper.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(ofColor::antiqueWhite);
	// gui.draw();

	ofTranslate(ofGetWidth() / 2., ofGetHeight() / 2.);
	if (step_show == 0) {
		stepper.draw();
	} else {
		draw_text();
	}
}

void ofApp::draw_text() {
	ofSetColor(ofColor::black);
	auto rect = font.getStringBoundingBox(points[step_show-1], 0, 0);
	font.drawString(points[step_show-1], -rect.width / 2., rect.height / 2.);
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
		case 'c':
			stepper.setDirection(true);
			break;
		case OF_KEY_UP:
			stepper.step();
			break;
		case OF_KEY_DOWN:
			stepper.step_backward();
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
		case 'c':
			stepper.setDirection(false);
			break;
		case OF_KEY_RETURN:
			next_step();
			break;
	}
}

void ofApp::next_step() {
	step_show = (step_show + 1) % MAX_STEPS;
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
