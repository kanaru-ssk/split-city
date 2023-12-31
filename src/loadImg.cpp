#include "ofApp.h"

// bin/data/images/ フォルダ内のjpg画像を取得
void ofApp::loadImg()
{
  ofDirectory imagesDir;
  imagesDir.listDir("loadImg");
  imagesDir.allowExt("jpg");
  imagesDir.sort();

  numImg = imagesDir.size();

  // 画像ロード
  images.assign(numImg, ofImage());
  for (int i = 0; i < numImg; i++)
  {
    images[i].load(imagesDir.getPath(i));
  }
}
