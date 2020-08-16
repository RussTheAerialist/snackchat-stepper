#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "stepper.h"

const int number_points = 5;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

	private:
		Stepper stepper;
		ofTrueTypeFont font;
		ofxPanel gui;
		int step_show;

		void next_step();
		void draw_text();

		string points[number_points] = {
			"low cost",
			"precise",
			"rugged",
			"reliable",
			"high torque",
		};
};
