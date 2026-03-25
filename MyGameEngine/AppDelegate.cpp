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
	UserGurideScene* scene = new UserGurideScene();
	Director::getInstance()->runWithScene(scene);

	Label* label1 = new Label();
	label1->setString("123");
	label1->setPosition(0, 0);
	Label* label2 = new Label();
	label2->setPosition(5, 5);
	label2->setString("ABC");

	scene->addChild(label1);
	scene->addChild(label2);
}
