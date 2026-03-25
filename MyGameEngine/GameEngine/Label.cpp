#include "Label.h"

using namespace dhgame;

void Label::setString(string str) {
	this->_str = str;

}

string Label::getString() {

	
	
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
