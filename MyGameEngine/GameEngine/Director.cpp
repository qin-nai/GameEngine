#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include "Director.h"
using namespace std;
using namespace dhgame;

static Director* instance = nullptr;

Director::Director() {
	this->setDesignResolutionSize(10, 10);
}

Director::~Director() {

}

Director* Director::getInstance()
{
	if (instance == nullptr)
	{
		instance = new Director();
	}
	
	return instance;
}

void Director::setDesignResolutionSize(int width, int height)
{
	//设置设计分辨率
	this->_designResolutionSize.width = width;
	this->_designResolutionSize.height = height;
	//分配帧缓冲区是否需要重新分配
	if (this->_frame) delete[]this->_frame;
	//分配帧缓冲区
	this->_frame = new char[width * height];
}

void Director::drawNodes(Node* root)
{
	root->draw(this->_frame, this->_designResolutionSize.width, this->_designResolutionSize.height);
	auto childs = root->getChildren();
	for(int i=0;i<childs.size();i++){
		this->drawNodes(childs[i]);
	}
}

//绘制当前场景
void Director::draw()
{
	int width = this->_designResolutionSize.width;
	int height = this->_designResolutionSize.height;
	memset(this->_frame, ' ', width * height);
	if (this->_runningScene) {
		this->drawNodes(this->_runningScene);
	}
	system("cls");
	for(int i=0;i<height;i++){
		for (int j = 0; j < width; j++) {
			cout << this->_frame[i*width+j];
		}
		cout << endl;
	}
	
	cout.flush();
	Sleep(100);
}
//运行场景
void Director::runWithScene(Scene* scene)
{
	this->_runningScene = scene;
}

