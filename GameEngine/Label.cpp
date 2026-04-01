#include "Label.h"

using namespace dhgame;

Label* Label::create(const std::string text)
{
	auto label = new Label();
	//判断文本获取是否成功
	if (label) {
		label->autorelease();
		label->setString(text);
		//判断节点文本是否初始化成功
		if (!label->init()) {
			delete label;
			return nullptr;
		}
		return label;
	}
	return nullptr;
}

void Label::setString(std::string str) {
	this->_str = str;

}

std::string Label::getString() {

	
	
	return this->_str;
}
//节点本身的世界坐标 = 父节点的世界坐标 + 节点的局部坐标
void Label::draw(char* frame, int width, int height, Vec2 p) {
	int x = 0;
	int y = 0;
	for(int i=0;i<this->_str.size();i++){
		y = p.y;
		x = p.x + i;
		if (x < 0 || y < 0 || x >= width || y >= height) continue;
		frame[y * width + x] = this->_str[i];
	}

}
