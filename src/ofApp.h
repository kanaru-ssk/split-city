#pragma once

#define WEBCAM

#include "ofMain.h"

struct pingPongBuffer {
public:
	void allocate( int _width, int _height, int _internalformat = GL_RGBA){
		// Allocate
		for(int i = 0; i < 2; i++){
			FBOs[i].allocate(_width,_height, _internalformat );
			FBOs[i].getTexture().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
		}

		//Assign
		src = &FBOs[0];
		dst = &FBOs[1];

		// Clean
		clear();
	}

	void swap(){
		std::swap(src,dst);
	}

	void clear(){
		for(int i = 0; i < 2; i++){
			FBOs[i].begin();
			ofClear(0,255);
			FBOs[i].end();
		}
	}

	ofFbo& operator[]( int n ){ return FBOs[n];}
	ofFbo *src;    // Source       ->  Ping
	ofFbo *dst;    // Destination  ->  Pong

private:
	ofFbo FBOs[2]; // Real addresses of ping/pong FBO«s
};

class ofApp : public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

    void mousePressed(int x, int y, int button);
    void windowResized(int w, int h);

private:
    void init();
    int numImages, numSplit, winW, winH, texW, texH;
    ofDirectory imagesDir;
    vector<ofImage> images;
    ofFbo joinedFbo;
    ofImage emptyImage;
    ofShader renderShader, splitShader;
    pingPongBuffer splitTex;
		ofTexture dOpacityTex;
};
