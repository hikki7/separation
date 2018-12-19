#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    for(int i=0;i<1000;i++){
        auto vehicle=make_unique<Vehicle>();
        this->vehicles.push_back(move(vehicle()));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(auto& vehicle: this->vehicles){
        vehicle->separate(vehicles);
        vehicle->border();
        vehicle->update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(auto& vehicle: this->vehicles){
        vehicle->display();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    auto vehicle=make_unique<Vehicle>();
    this->vehicles.push_back(move(vehicle));
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
