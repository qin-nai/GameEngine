#include "Node.h"
#include "Director.h"
#include <cstring>
using namespace dhgame;

bool Node::init()
{
	return true;
}

Node::~Node()
{
	Director::getInstance()->getKeyDispatcher()->removeEventForTarget(this);
	Director::getInstance()->getScheduler()->unschedleForTarget(this);
	this->removeAllChil();
}

void Node::update(float dt)
{

}

void Node::draw(char* frame, int width, int height, Vec2 p) {

}
//添加子节点
void Node::addChild(Node* node) {
	this->_childs.push_back(node);
	node->retain();
}
//删除子节点
void Node::removeChild(Node* node) {
	for (int i = this->_childs.size() - 1; i >= 0; i--) {
		if (this->_childs[i] == node) {
			this->_childs[i]->release();
			this->_childs.erase(this->_childs.begin() + i);
		}
	}
}

void Node::removeAllChil()
{
	for (int i = 0; i < this->_childs.size(); i++) {
		this->_childs[i]->release();
	}
	this->_childs.clear();
}

std::vector<Node*>& Node::getChildren() {

	return this->_childs;
}
//设置节点的世界坐标
void Node::setPosition(int x, int y) {
	this->_pos.x = x;
	this->_pos.y = y;

}
//获取节点的横坐标
int Node::getpositionX() {


	return this->_pos.x;
}
//获取节点的纵坐标
int Node::getpositionY() {

	return this->_pos.y;
}

void Node::scheduleUpdate()
{
	auto scheduler = Director::getInstance()->getScheduler();
	scheduler->schedule(this, CallbackFunc(&Node::update), 0, true);
}

void Node::schedule(Node* target, CallbackFunc callback, float duration, bool isRepeat)
{
	auto scheduler = Director::getInstance()->getScheduler();
	scheduler->schedule(this, callback,duration, isRepeat);
}

void Node::unscheduleAll()
{
	Director::getInstance()->getScheduler()->unschedleForTarget(this);
}

void Node::addKeyEvent(Node* target, KeyCallback callback)
{
	Director::getInstance()->getKeyDispatcher()->addKeyEvent(target, callback);
}
