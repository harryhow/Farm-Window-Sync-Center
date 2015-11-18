#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#define     HOST "127.0.0.1"
#define     SENDPORT 6002
#define    RECVPORT 6003

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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    
        void dumpOSC(ofxOscMessage m);
    
        ofxOscSender oscSender;
        ofxOscReceiver oscReceiver;
    
        ofxOscMessage msgSend;
        ofxOscMessage msgRecv;

};
