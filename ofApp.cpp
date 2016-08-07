#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    int bufferSize		= 512;
    sampleRate 			= 44100;
    bPlay = false;
    
    ofSoundStreamSetup(2, 0, this, sampleRate, bufferSize, 4);
    ofSoundStreamStop();
}
//--------------------------------------------------------------
void ofApp::update(){
    
    // "lastBuffer" is shared between update() and audioOut(), which are called
    // on two different threads. This lock makes sure we don't use lastBuffer
    // from both threads simultaneously (see the corresponding lock in audioOut())
    unique_lock<mutex> lock(audioMutex);

}
//--------------------------------------------------------------
void ofApp::draw(){

}
//--------------------------------------------------------------
void ofApp::audioOut(float * output, int bufferSize, int nChannels){
    
    for(int i = 0; i < bufferSize; i++){
        currentCount=(int)timer.phasor(8);//this sets up a metronome that ticks 8 times a second
        
        
        if (lastCount!=currentCount) {//if we have a new timer int this sample, play the sound
            
            playHead++;//iterate the playhead
            lastCount=0;//reset the metrotest
            cout<<playHead<<endl;
        }
    }
    unique_lock<mutex> lock(audioMutex);
}
//--------------------------------------------------------------
void ofApp::exit(){
    ofSoundStreamClose();
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if(key ==32){
        bPlay = !bPlay;
    }
    if(bPlay == true){
        ofSoundStreamStart();
    }
    else{
        ofSoundStreamStop();
        playHead = 0;
    }
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
