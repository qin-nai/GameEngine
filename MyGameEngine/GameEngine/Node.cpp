#include "Node.h"
#include <cstring>
using namespace dhgame;

bool Node::init()
{
	
	return true;
}

void Node::draw(char* frame, int width, int height, Vec2 p) {

}
//添加子节点
void Node::addChild(Node* node) {
	this->_childs.push_back(node);
}
//删除子节点
void Node::removeChild(Node* node) {
	
}

std::vector<Node*>& Node::getChildren() {


	
	return this->_childs;
}
//设置节点的坐标位置
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