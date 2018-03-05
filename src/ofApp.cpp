#include  "ofApp.h"
using namespace ofxCv;

void ofApp::setup(){
  ofSetWindowTitle("Facesaver 2");
  width=ofGetWidth();
  height=ofGetHeight();
  ofSetVerticalSync(true);
  ofClear(255,255,255,0);
  ofSetBackgroundAuto(false);
  ofEnableAlphaBlending();
  fbo.allocate( width, height, GL_RGBA );
  temp.allocate( width, height, OF_PIXELS_RGBA);
  fbo.begin();
  ofClear(255,255,255,0);
  fbo.end();
  cam.initGrabber(2560, 1440);
    
  tracker.setup();
  path = ("images/" + ofToString(ofGetTimestampString("%Y-%m-%d_%H-%M-%S")));
  ofDirectory dir(path);
  if(!dir.exists()){
  dir.create(true);
  absolutePath = dir.getAbsolutePath();
  }
  ofDirectory::createDirectory(path);
  ofSetDataPathRoot(ofToDataPath(path));
}

void ofApp::update(){
  cam.update();
  if(cam.isFrameNew()) {
    tracker.update(toCv(cam));
  }
}

void ofApp::draw(){
  fbo.begin();
  ofSetupScreenOrtho(width,height, -1000, 1000);
    
  if(tracker.getFound()) {

    ofPushMatrix();
	ofTranslate(ofRandom(150,width-150), ofRandom(150,height-150));
    	ofScale(6.5,6.5,6.5);
    		cam.getTexture().bind();
    			ofRotateX(ofRandom(0,360));
    			ofRotateY(ofRandom(0,360));
    			ofRotateZ(ofRandom(0,360));
    			tracker.getMeanObjectMesh().draw();
			fbo.readToPixels(temp);
	        cam.getTexture().unbind();
    ofPopMatrix();

    if(x <= (width)){
      x+=250;
    } else {
        ofSaveImage(temp, ofGetTimestampString("%Y-%m-%d_%H-%M-%S") + ".png", OF_IMAGE_QUALITY_BEST);
      img_count++;
      x=0;
      //string convert_command = "cd " + absolutePath + "/ && " + "/usr/local/bin/convert -antialias -delay 1x2 *.png animation.mov &";
      string convert_command = "cd " + absolutePath + "/ && " + "/usr/local/bin/ffmpeg -framerate 4 -pattern_type glob -i '*.png' -y -c:v libx264 -pix_fmt yuv420p animation.mp4 &";
      ofSystem(convert_command);
    }
    sleep(1);   
  }
    
    fbo.end();
    fbo.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
