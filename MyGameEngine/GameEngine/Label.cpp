#include "Label.h"

using namespace dhgame;

void Label::setString(string str) {
	this->_str = str;

}

string Label::getString() {

	
	
	return this->_str;
}

void Label::draw(char* frame, int width, int height) {
	int x = 0;
	int y = 0;
	for(int i=0;i<this->_str.size();i++){
		y = this->_y;
		x = this->_x + i;
		if (x < 0 || y < 0 || x >= width || y >= height) continue;
		frame[y * width + x] = this->_str[i];
	}

}
