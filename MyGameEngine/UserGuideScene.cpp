#include "UserGuideScene.h"

using namespace dhgame;

bool UserGurideScene::init()
{
	Label* label1 = Label::create();
	label1->setString("123");
	label1->setPosition(0, 6);
	Label* label2 = Label::create();
	label2->setPosition(0, 1);
	label2->setString("ABC");

	auto node = Node::create();
	this->addChild(node);

	this->addChild(label1);
	label1->addChild(label2);
	
	auto spr = Sprite::create();
	spr->setTexture("resource/0.spr");

    return true;
}
