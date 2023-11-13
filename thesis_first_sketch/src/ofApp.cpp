#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    ofEnableDepthTest(); // Enable depth testing for 3D rendering
    cam.setPosition(0, 0, 400); // Set the initial camera position
    cam.lookAt(glm::vec3(0, 0, 0)); // Point the camera at the origin
    ofAddListener(ofEvents().mouseScrolled, this, &ofApp::mouseScrolled);
}



//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    ofPushMatrix();
    createSpheresAndTubes();
    ofPopMatrix();
    cam.end();
}

void ofApp::createSpheresAndTubes() {

    float xspace = spacing / 2;
    for (int i = 0; i < numLayersX; i++) {
        for (int j = 0; j < numLayersY; j++) {
            for (int k = 0; k < numLayersZ; k++) {
                if (i % 2 != 0 )
                {        
                    if (k >= (numLayersZ - 1))
                    {
                        continue;
                    }

                    if (j >= (numLayersY - 1))
                    {
                        continue;
                    }
                    else
                    {
                        float x = i * xspace - xspace * (numLayersX - 1);
                        float y = j * spacing - spacing * (numLayersY - 1)  + spacing/2;
                        float z = k * spacing - spacing * (numLayersZ - 1)  + spacing/2;


                        ofSpherePrimitive sphere;
                        ofSetColor(125);
                        sphere.setPosition(x, y, z);
                        sphere.set(radius, 16);  // 16 segments for a smoother sphere
                        sphere.draw();
                       // std::cout << x << "s" << i << "\n";

                        float x_front = x + xspace ;
                        float x_back  = x - xspace ;
                        float  y_up = y + (spacing / 2);
                        float y_do = y - (spacing / 2);
                        float z_left = z + (spacing /2);
                        float z_right = z - (spacing /2);

                        createPipe(ofVec3f(x, y, z), ofVec3f(x_front, y_up, z_left), 5);
                        createPipe(ofVec3f(x, y, z), ofVec3f(x_front, y_up, z_right), 5);
                        createPipe(ofVec3f(x, y, z), ofVec3f(x_front, y_do, z_left), 5);
                        createPipe(ofVec3f(x, y, z), ofVec3f(x_front, y_do, z_right), 5);
                        createPipe(ofVec3f(x, y, z), ofVec3f(x_back, y_up, z_left), 5);
                        createPipe(ofVec3f(x, y, z), ofVec3f(x_back, y_up, z_right), 5);
                        createPipe(ofVec3f(x, y, z), ofVec3f(x_back, y_do, z_left), 5);
                        createPipe(ofVec3f(x, y, z), ofVec3f(x_back, y_do, z_right), 5);
                       


                        

                    }
                    
                }
                else {

                 
                    

                        float x = i * xspace  - xspace * (numLayersX - 1);
                        float y = j * spacing - spacing * (numLayersY - 1) ;
                        float z = k * spacing - spacing * (numLayersZ - 1) ;
                        ofSpherePrimitive sphere;
                        ofSetColor(255);
                        sphere.setPosition(x, y, z);
                        sphere.set(radius, 16);  // 16 segments for a smoother sphere
                        sphere.draw();
                       // std::cout << x << "s" << i << "\n";
                       
                                 
                        
                    

                  

                }
            }
        }
    }

    

}
void ofApp::createPipe(ofVec3f startPoint, ofVec3f endPoint, float radius) {
    ofVec3f direction = endPoint - startPoint;
    float length = direction.length();
    direction.normalize();

    ofPushMatrix();  // Save the current coordinate system
    ofTranslate(startPoint);  // Translate to the start point

    // Rotate the coordinate system to align with the direction of the pipe
    float rotationAmount = acos(direction.dot(ofVec3f(0, -1, 0))) * RAD_TO_DEG;
    ofVec3f rotationAxis = direction.getCrossed(ofVec3f(0, -1, 0));
    ofRotate(rotationAmount, rotationAxis.x, rotationAxis.y, rotationAxis.z);

    // Translate along the y-axis by half the length of the cylinder
    ofTranslate(0, length / 2, 0);

    // Draw the cylinder with the calculated length and your desired radius
    ofSetColor(200,255,255);
    ofDrawCylinder(0, 0, 0, radius, length);

    ofPopMatrix();  // Restore the original coordinate system
}


void ofApp::mouseScrolled(ofMouseEventArgs& args) {
    cam.setDistance(cam.getDistance() + args.scrollY);
}





//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
