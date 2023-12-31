#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "pingPongBuffer.h"

class ofApp : public ofBaseApp
{
public:
	void setup();
	void update();
	void draw();

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

private:
	const int maxSqrtNumSplit = 16384;
	const int maxNumSplit = maxSqrtNumSplit * maxSqrtNumSplit; // 最大分割数

	// 設定値
	int sqrtNumSplit;	 // 分割数の正の平方根
	int numImg;				 // 画像数
	int numLimitImg;	 // 同時表示画像数
	float minDOpacity; // 透明度の変化幅の最小値
	float maxDOpacity; // 透明度の変化幅の最大値

	// gui
	ofxPanel gui;
	ofxIntSlider splitTypeSlider;
	ofxIntSlider sqrtNumSplitSlider;
	ofxIntSlider numLimitImgSlider;
	ofxFloatSlider minDOpacitySlider;
	ofxFloatSlider maxDOpacitySlider;
	ofxLabel hintScreenshot;
	ofxLabel hitInitApp;
	bool showGui = false;

	void loadImg();					 // setupで呼び出す
	void initApp();					 // setup,mousePressed,windowResized で呼び出す
	void initUpdateShader(); // update.fragに渡すデータ初期化
	void initDrawShader();	 // draw-*.fragに渡すデータ初期化
	void exportImg();				 // 's'キーを押した時に呼び出す

	// 入力画像
	vector<ofImage> images; // bin/data/images内の画像
	ofFbo joinedFbo;				// 結合画像 (全ての画像を結合した画像)

	// 更新用
	ofShader splitShader;		 // 分割領域のデータ更新シェーダー
	pingPongBuffer splitTex; // 分割領域のデータテクスチャ R:現在の画像ID G:次の画像ID B:透明度
	ofTexture dOpacityTex;	 // 透明度の変化幅

	// 描画用
	ofShader drawShader; // 描画シェーダー
	ofImage emptyImage;	 // 空画像
	int winW, winH;			 // ウィンドウサイズ
};
