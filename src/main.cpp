#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main()
{
	ofGLWindowSettings settings;
	settings.setGLVersion(3, 2);
	settings.windowMode = OF_FULLSCREEN;
	ofCreateWindow(settings);

	ofRunApp(new ofApp());
}
