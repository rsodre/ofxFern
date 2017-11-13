#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofSetFrameRate(60);
	
	int camW = 640;
	int camH = 480;

	fern.setup("model.bmp", camW, camH);
	grabber.initGrabber(camW, camH);
	colorImg.allocate(camW, camH);
	img.allocate(camW, camH);
	
	showTracker = false;
}

//--------------------------------------------------------------
void ofApp::update(){
	
	grabber.update();	
	if(grabber.isFrameNew()){
		colorImg = grabber.getPixels();
		img = colorImg;
		fern.update(img);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetColor(255);
	if(showTracker){
		fern.draw(0, 0, 640, 480);
	}
	else{
		grabber.draw(0, 0, 640, 480);
	}
	
	ofSetHexColor(0xFF0000);
	ofNoFill();
	if(fern.trackedMarker.tracked) {
		fern.trackedMarker.draw();
	}

	ofSetColor(255);
	ofDrawBitmapString("press 'd' to toggle tracker image\nfps: "+ofToString(ofGetFrameRate(), 2), 10, 10);
}


//--------------------------------------------------------------
void ofApp::keyPressed  (int key){

	switch(key){
		
		case 'd':
			showTracker = !showTracker;
			break;
		
		case 't':
			fern.resetTracker();
			break;
		
		case 'k':
			fern.showKeypoints(!fern.getShowKeypoints());
			break;
			
		case 'l':
			fern.showLocations(!fern.getShowLocations());
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
void ofApp::windowResized(int w, int h){
}

