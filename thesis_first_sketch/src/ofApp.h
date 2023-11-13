#pragma once

#include "ofMain.h"



class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void mouseScrolled(ofMouseEventArgs& args);

		ofEasyCam cam;

		// Adjustable parameters
		int numLayersX = 7; // Number of layers in the X direction
		int numLayersY = 4; // Number of layers in the Y direction
		int numLayersZ = 4; // Number of layers in the Z direction

		float spacing = 150.0;  // Adjust this spacing as needed
		float radius = 10.0;   // Adjust the radius of the spheres

		// Function to create spheres and tubes
		void createSpheresAndTubes();
		void createPipe(ofVec3f startPoint, ofVec3f endPoint, float radius);


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

		



		
};
