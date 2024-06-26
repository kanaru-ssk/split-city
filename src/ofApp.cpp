#include "ofApp.h"

//--------------------------------------------------------------
// 起動時に一度実行される
void ofApp::setup()
{
	// for standalone build
	// ofSetDataPathRoot("../Resources/data/");

	loadImg();

	gui.setup();
	gui.add(splitTypeSlider.setup("splitType", 4, 1, 4));
	gui.add(sqrtNumSplitSlider.setup("sqrtNumSplit", 256, 1, 256));
	gui.add(numLimitImgSlider.setup("numLimitImg", 9, 1, numImg));
	gui.add(minDOpacitySlider.setup("minDOpacity", 0.0035, 0.002, 0.005));
	gui.add(maxDOpacitySlider.setup("maxDOpacity", 0.01, 0.005, 0.5));
	gui.add(hintScreenshot.setup(" 's'  key", "export img"));
	gui.add(hitInitApp.setup("enter key", "init app"));

	initApp();
}

//--------------------------------------------------------------
// データ更新処理 シェーダー側のコードは bin/data/shader/update.frag
void ofApp::update()
{
	splitTex.dst->begin();
	splitShader.begin();

	splitShader.setUniform1f("elapsedTime", ofGetElapsedTimef());
	splitShader.setUniformTexture("preSplitTex", splitTex.src->getTexture(), 3);
	splitTex.src->draw(0, 0);

	splitShader.end();
	splitTex.dst->end();

	splitTex.swap();
}

//--------------------------------------------------------------
// 描画処理 シェーダー側のコードは bin/data/shader/draw-*.frag
void ofApp::draw()
{
	// 空画像上に描画シェーダーのテクスチャを描画
	drawShader.begin();
	drawShader.setUniformTexture("splitTex", splitTex.src->getTexture(), 2);
	emptyImage.draw(0, 0, winW, winH);
	drawShader.end();

	if (showGui)
		gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if (key == 's')
		exportImg();

	if (key == OF_KEY_RETURN)
		initApp();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	showGui = !showGui;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
	initApp();
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}
