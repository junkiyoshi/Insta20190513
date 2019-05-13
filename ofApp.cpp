#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	//ofNoFill();
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	auto center = glm::vec2(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	auto span = 20;
	for (auto radius = 50; radius < 350; radius += span) {

		vector<glm::vec2> inner, outer;
		int deg_start = ofRandom(360);
		int deg_width = (int)(ofRandom(0, 360) + ofGetFrameNum() * ofRandom(1, 5)) % 720;
		if (deg_width < 360) {
			
			for (auto deg = deg_start; deg <= deg_start + deg_width; deg++) {

				inner.push_back(center + glm::vec2((radius - span * 0.45) * cos(deg * DEG_TO_RAD), (radius - span * 0.45) * sin(deg * DEG_TO_RAD)));
				outer.push_back(center + glm::vec2((radius + span * 0.45) * cos(deg * DEG_TO_RAD), (radius + span * 0.45) * sin(deg * DEG_TO_RAD)));
			}
		}
		else {

			for (auto deg = deg_start + deg_width - 360; deg <= deg_start + 360; deg++) {

				inner.push_back(center + glm::vec2((radius - span * 0.45) * cos(deg * DEG_TO_RAD), (radius - span * 0.45) * sin(deg * DEG_TO_RAD)));
				outer.push_back(center + glm::vec2((radius + span * 0.45) * cos(deg * DEG_TO_RAD), (radius + span * 0.45) * sin(deg * DEG_TO_RAD)));
			}
		}

		reverse(inner.begin(), inner.end());

		ofBeginShape();
		ofVertices(outer);
		ofVertices(inner);
		ofEndShape(true);
	}
	
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}