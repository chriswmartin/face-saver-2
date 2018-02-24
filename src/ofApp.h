#pragma once

#include <ctime>
#include "ofMain.h"
#include "ofxCv.h"
#include "ofxFaceTracker.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();

  		ofFbo fbo;
		ofPixels temp;
		ofVideoGrabber cam;
		ofxFaceTracker tracker;
		ofEasyCam easyCam;
    		ofImage img;
  		string path;
  		int x;
  		int img_count=0;
  		int width;
  		int height;
				
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
};
