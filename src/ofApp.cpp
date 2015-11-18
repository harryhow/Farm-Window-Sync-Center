#include "ofApp.h"

int currentFrameA, currentFrameB, currentFrameC, currentFrameD;

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0, 0, 0);
    oscSender.setup(HOST, SENDPORT);
    oscReceiver.setup(RECVPORT-1);
    
    msgSend.setAddress("/sync/videoJump");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
//    int currentFrameA, currentFrameB, currentFrameC, currentFrameD;
    int frameDiff;
    
    while (oscReceiver.hasWaitingMessages()) {
        
        cout << "New msg is coming + ";
        ofxOscMessage m;
        oscReceiver.getNextMessage(&m);
        
        if (m.getAddress() == "/sync/A/currentFrame") {
            currentFrameA = m.getArgAsInt32(0);
            cout << "current frame from A: " << currentFrameA <<"\r\n";
        }
        else if (m.getAddress() == "/sync/B/currentFrame") {
            currentFrameB = m.getArgAsInt32(0);
            cout << "current frame from B: " << currentFrameB <<"\r\n";
        }
        else if (m.getAddress() == "/sync/C/currentFrame") {
            currentFrameC = m.getArgAsInt32(0);
            cout << "current frame from C: " << currentFrameC <<"\r\n";
        }
        else if (m.getAddress() == "/sync/D/currentFrame") {
            currentFrameD = m.getArgAsInt32(0);
            cout << "current frame from D: " << currentFrameD <<"\r\n";
        }
        
        //dumpOSC(m);
    }
    
    // sync/A/currentFrame
    // sync/B/currentFrame
    // sync/C/currentFrame
    // sync/D/currentFrame
    frameDiff = currentFrameA - currentFrameB;
    
    if (frameDiff >= 10) {
        msgSend.addIntArg(frameDiff); //
        oscSender.sendMessage(msgSend);
        cout << "== Broadcast to jump frame:" << frameDiff << " frames" << "\r\n";
    }
}

void ofApp::dumpOSC(ofxOscMessage m) {
    
    string msg_string;
    
    msg_string = m.getAddress();
    
    for (int i=0; i<m.getNumArgs(); i++ ) {
        msg_string += " ";
        if(m.getArgType(i) == OFXOSC_TYPE_INT32)
            msg_string += ofToString( m.getArgAsInt32(i));
        else if(m.getArgType(i) == OFXOSC_TYPE_FLOAT)
            msg_string += ofToString( m.getArgAsFloat(i));
        else if(m.getArgType(i) == OFXOSC_TYPE_STRING)
            msg_string += m.getArgAsString(i);
    }
    cout << msg_string << endl;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
    
    currentFrameA = x;
    currentFrameB = y;
    
    ofxOscMessage msgfromA;
    ofxOscMessage msgfromB;
    msgfromA.setAddress("/sync/A/currentFrame");
    msgfromB.setAddress("/sync/B/currentFrame");
    
    msgfromA.addIntArg(currentFrameA);
    msgfromB.addIntArg(currentFrameB);
    
    oscSender.sendMessage(msgfromA);
    oscSender.sendMessage(msgfromB);
    
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

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
