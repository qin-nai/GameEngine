#include "Sprite.h"
#include <fstream>
using namespace dhgame;


void Sprite::draw(char* frame, int width, int height, Vec2 p) {
	
	int x = p.x;
	int y = p.y;
	for (int i = 0; i < this->_size; i++) {
		char c = this->_data[i];
		if (c == "\n") {
			y++;
			x = p.x;
			continue;
		}
		if (x < 0 || y < 0 || x >= width || y >= height) continue;
		frame[y * width + x] = c;
	}

}

void Sprite::setTexture(const std::string& path)
{
	//打开文件
	std::ifstream f(path, std::ios::in);
	if (!f.is_open()) return;
	
	//移动光标到最后，为了获取文件长度
	f.seekg(0, f.end);
	this->_size = f.tellg();
	//查看是否有数据缓存，有就清除
	if (this->_data) delete[] this->_data;

	this->_data = new char[this->_size];
	//把光标移动到最开头得的位置
	f.seekg(0);
	//读取文件
	f.read(this->_data, this->_size);
	//关闭文件
	f.close();
}
