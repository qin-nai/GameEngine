#include "UserGuideScene.h"

using namespace dhgame;

bool UserGurideScene::init()
{
	this->addKeyEvent(this, KeyCallback(&UserGurideScene::onKeyEvent));
	this->_curScreen = 1;

	//logo
	auto logoSprite = Sprite::create("resource/UserGuideScene/0.spr");
	logoSprite->setPosition(30, 0);
	this->addChild(logoSprite);

	auto label1 = Label::create("外星電腦科技有限公司");
	label1->setPosition(55, 20);
	this->addChild(label1);

	auto label2 = Label::create("WAIXING COMPUTER SCIENCE & TECHNOLOGY CO.,LTD.");
	label2->setPosition(45, 24);
	this->addChild(label2);

	auto label3 = Label::create("版权所有                 970100686");
	label3->setPosition(44, 38);
	this->addChild(label3);

	auto label4 = Label::create("EMULATION START.");
	label4->setPosition(45, 40);
	this->addChild(label4);

	this->schedule(this, CallbackFunc(&UserGurideScene::SecondScreen), 3.0, false);
	
    return true;
}

void UserGurideScene::update(float dt)
{
	
}

void UserGurideScene::SecondScreen(float dt)
{
	this->_curScreen = 2;
	this->removeAllChil();

	auto sprite = Sprite::create("resource/UserGuideScene/1.spr");
	sprite->setPosition(30,0);
	this->addChild(sprite);

	this->schedule(this, CallbackFunc(&UserGurideScene::thirdScreen), 3.0, false);

}

void UserGurideScene::thirdScreen(float dt)
{
	this->_curScreen = 3;
	AudioEngine::getInstance()->playBgMusic("resource/audio/start.mp3");

	this->removeAllChil();
	auto sprite = Sprite::create("resource/UserGuideScene/sea.spr");
	sprite->setPosition(0, 0);
	this->addChild(sprite);

}

void UserGurideScene::showMenu()
{
	AudioEngine::getInstance()->playBgMusic("resource/audio/option.mp3");
	this->removeAllChil();

	auto sprite = Sprite::create("resource/UserGuideScene/menu_frame.spr");
	sprite->setPosition(40, 10);
	this->addChild(sprite);

	auto arrow = Sprite::create("resource/UserGuideScene/arrow.spr");
	arrow->setPosition(54, 14);
	this->addChild(arrow);
	this->_arrow = arrow;

	this->_curScreen = 4;
	
}

void UserGurideScene::onKeyEvent(int keyCode)
{
	if (keyCode == 'i' || keyCode == 'I') {
		switch (this->_curScreen)
		{
		case 1:
			this->unscheduleAll();
			this->SecondScreen(0);
			break; 
		case 2:
			this->unscheduleAll();
			this->thirdScreen(0);
			break;
		case 3:
			this->unscheduleAll();
			this->showMenu();
			break;
		}
	}
	if (this->_curScreen == 4) {
		if (keyCode == 'w' || keyCode == 'W') {
			this->_muneID = (this->_muneID + 1) % 2;
			this->_arrow->setPosition(54, 14 + this->_muneID);
		}
		else if (keyCode == 's' || keyCode == 'S') {
			this->_muneID = (this->_muneID + 1) % 2;
			this->_arrow->setPosition(54, 14 + this->_muneID);
		}
	}
	
}
