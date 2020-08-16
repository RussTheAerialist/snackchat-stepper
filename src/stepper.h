#pragma once

#define HUMP 100

#include "ofMain.h"

class Stepper {
	const float spacing = 43;

	public:
		ofParameter<float> x_offset;
		ofParameter<float> y_offset;

		void setup(ofTrueTypeFont &f) {
			font = &f;
			coil_a_active = coil_b_active = coil_direction = false;

			setup_coil();
			setup_arrow();

			set_step();
		}

		void update() { }

		void draw() {
			ofPushStyle();
			ofSetColor(ofColor::black);
			ofSetLineWidth(3);
			ofNoFill();

			// Motor Outline
			ofDrawEllipse(0, 0, 35 * 5, 35 * 5);

			// Labels
			auto rect = font->getStringBoundingBox("M", 0, 0);
			font->drawString("M", -rect.width / 2., rect.height / 2.);

			ofPushMatrix();
			ofTranslate(- 45 * 5, -35 * 2.5);
			// Left Coil
			draw_coil(coil_a_active);
			draw_coil_direction(coil_a_active);
			ofPopMatrix();

			ofPushMatrix();
			ofRotateDeg(-90);
			ofTranslate(- 45 * 5, -35 * 2.5);
			// Bottom Coil
			draw_coil(coil_b_active);
			draw_coil_direction(coil_b_active);
			ofPopMatrix();

			// Motor Rotation Arrows

			// Position Indicator
			// TODO: ofRotate
			ofSetLineWidth(10);
			ofRotateDeg(angle);
			ofDrawLine(0, 15 * 5, 0, 20 * 5);
			ofPopStyle();
		}

		void setCoilA(bool a) {
			coil_a_active = a;
		}

		void setCoilB(bool b) {
			coil_b_active = b;
		}

		void setDirection(bool dir) {
			coil_direction = dir;
		}

		void step() {
			current_step = (current_step + 1) % 4;
			angle = (angle + 2) % 360;
			set_step();
		}

		void step_backward() {
			current_step -= 1;
			angle -= 2;
			if (angle < 0) {
				angle += 360;
			}
			if (current_step < 0) {
				current_step += 4;
			}
			set_step();
		}

		void set_step() {
			switch(current_step) {
				case 0:
					coil_a_active = true;
					coil_b_active = false;
					coil_direction = true;
					break;
				case 1:
					coil_a_active = false;
					coil_b_active = true;
					coil_direction = true;
					break;
				case 2:
					coil_a_active = true;
					coil_b_active = false;
					coil_direction = false;
					break;
				case 3:
					coil_a_active = false;
					coil_b_active = true;
					coil_direction = false;
					break;
			}
		}

		private:
			ofTrueTypeFont *font;
			ofPath coil, arrow;
			bool coil_a_active, coil_b_active;
			bool coil_direction;
			int current_step;
			int angle = 0;

			void setup_coil() {

				coil.setFilled(false);
				coil.setStrokeWidth(3);
				coil.setColor(ofColor::black);
				coil.moveTo(0, 0);
				coil.lineTo(spacing, 0);
				coil.arc(spacing, spacing / 2., spacing / 2., spacing / 2., -90, 90);
				coil.arc(spacing, spacing * 1.5, spacing / 2., spacing / 2., -90, 90);
				coil.arc(spacing, spacing * 2.5, spacing / 2., spacing / 2., -90, 90);
				coil.arc(spacing, spacing * 3.5, spacing / 2., spacing / 2., -90, 90);
				coil.lineTo(0, spacing * 4.);

				// draw_hump(spacing - 2, 0,      spacing - 2, spacing);
				// draw_hump(spacing - 2, spacing,   spacing - 2, spacing*2);
				// draw_hump(spacing - 2, spacing*2, spacing - 2, spacing*3);
				// draw_hump(spacing - 2, spacing*3, spacing - 2, 175);
				// ofDrawLine(0, 175, spacing, 175);
			}

			void draw_coil(bool active) {
				if (active) {
					if (coil_direction) {
						coil.setColor(ofColor::red);
					} else {
						coil.setColor(ofColor::blue);
					}
				} else {
					coil.setColor(ofColor::black);
				}

				coil.draw();
			}

			void draw_coil_direction(bool active) {
				if (!active) {
					return;
				}

				ofPushStyle();
				if (coil_direction) {
					arrow.setColor(ofColor::red);
					ofSetColor(ofColor::red);
				} else {
					arrow.setColor(ofColor::blue);
					ofSetColor(ofColor::blue);
				}

				arrow.draw();


				ofFill();
				ofPushMatrix();
				if (coil_direction) {
					ofScale(1, -1);
				}
				ofTranslate(-spacing / 2., spacing / 4.);
				ofRotateDeg(-60);
				ofTranslate(-22.75, 0);
				if (coil_direction) {
					ofTranslate(150, -90);
				}
				ofDrawTriangle(0, 0, spacing / 4., spacing, -spacing / 4., spacing);
				ofPopMatrix();
				ofPopStyle();
			}

			void setup_arrow() {
				const float position = spacing * 2.25;
				const float padding = spacing;

				arrow.setFilled(false);
				arrow.setStrokeWidth(25);
				arrow.setColor(ofColor::black);
				arrow.arc(-spacing / 2., spacing * 2., spacing, spacing, -60, 60);
			}
};