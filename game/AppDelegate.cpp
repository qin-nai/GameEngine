#include <iostream>
#include "AppDelegate.h"
#include "scene/UserGuideScene.h"
using namespace std;
using namespace dhgame;

AppDelegate::AppDelegate()
{
	
}

AppDelegate::~AppDelegate()
{
	
}

void AppDelegate::applicatioDidFinishLaunching()
{
	Director::getInstance()->setDesignResolutionSize(130, 44);//实际显示分辨率
	auto scene = UserGurideScene::create();
	Director::getInstance()->runWithScene(scene);

}
