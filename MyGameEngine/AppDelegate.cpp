#include <iostream>
#include "AppDelegate.h"
#include "UserGuideScene.h"
using namespace std;
using namespace dhgame;

AppDelegate::AppDelegate()
{
	cout << "AppDelegate 构造函数\n";
}

AppDelegate::~AppDelegate()
{
	cout << "AppDelegate 析构函数\n";
}

void AppDelegate::applicatioDidFinishLaunching()
{
	Director::getInstance()->setDesignResolutionSize(40, 20);
	auto scene = UserGurideScene::create();
	Director::getInstance()->runWithScene(scene);

}
