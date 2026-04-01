#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <chrono>
#include "Director.h"
#include "AutoreleasePool.h"
using namespace std;
using namespace dhgame;

static Director* instance = nullptr;

void Director::setCursorPosition(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//单例模式，获取Director实例=====控制分辨率
Director::Director() {
	this->_keyDispatcher = new KeyDispatcher();
	this->_schedule = new Schedule();
	this->setDesignResolutionSize(10, 10);
	this->setAnimationInterval(1.0 / 10);//10帧
	this->_lastTimestamp = this->getTimestamp();

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
	if (this->_screen)delete[]this->_screen;
	//分配帧缓冲区
	this->_frame = new char[width * height];
	this->_screen = new char[width * height];

	memset(this->_frame, ' ', width * height);
	memset(this->_screen, ' ', width * height);
}

void Director::drawNodes(Node* root ,Vec2 p)
{
	p.x += root->getpositionX();
	p.y += root->getpositionY();
	//绘制当前节点的世界坐标
	root->draw(this->_frame, this->_designResolutionSize.width, this->_designResolutionSize.height, p);
	auto childs = root->getChildren();
	for(int i=0;i<childs.size();i++){
		this->drawNodes(childs[i], p);
	}
}

//绘制当前场景
void Director::draw()
{
	auto timestamp = this->getTimestamp();
	float dt = (timestamp - this->_lastTimestamp) / 1000000.0;//现在的时间戳-上次的时间戳=当前时间间隔
	if (dt < this->_animationInterval) {
		int t = (this->_animationInterval - dt) * 1000;
		Sleep(t);
		timestamp = this->getTimestamp();
		dt = (timestamp - this->_lastTimestamp) / 1000000.0;
	}
	this->_lastTimestamp = timestamp; 

	int width = this->_designResolutionSize.width;
	int height = this->_designResolutionSize.height;
	
	memset(this->_frame, ' ', width * height);
	if (this->_runningScene) {
		Vec2 p;
		this->drawNodes(this->_runningScene, p);
	}

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	DWORD columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;//控制台窗口的列数
	DWORD rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;//控制台窗口的行数

	int offsetX = (columns - width) / 2;
	int offsetY = (rows - height) / 2;
	if (offsetX < 0) offsetX = 0;
	if (offsetY < 0) offsetY = 0;

	if (columns < width || rows < height) {
		system("cls");
		memset(this->_frame, ' ', width * height);
		memset(this->_screen, ' ', width * height);
		const char* str ="窗口过小，请拉大窗口";
		memcpy(this->_frame, str, strlen(str));
	}

	if (this->_col != columns || this->_row != rows) {
		this->_col = columns;
		this->_row = rows;
		system("cls");
		memset(this->_screen, ' ', width * height);
	}

	for(int i=0;i<height;i++){
		for (int j = 0; j < width; ) {
			if (this->_frame[i * width + j] < 0) {//判断是否是中文
				if (j == width - 1) {
					this->setCursorPosition(j + offsetX, i + offsetY);
					cout << ' ';
					j++;
					continue;
				}
				if (this->_frame[i * width + j] != this->_screen[i * width + j] ||
					this->_frame[i * width + j + 1] != this->_screen[i * width + j + 1]) 
				{
					this->setCursorPosition(j + offsetX, i + offsetY);
					cout << this->_frame[i * width + j];
					cout << this->_frame[i * width + j + 1];
				}
				j += 2;
			}
			else {
				if (this->_frame[i * width + j] != this->_screen[i * width + j]) {
					this->setCursorPosition(j+offsetX, i+offsetY);
					cout << this->_frame[i*width+j];
				}
				j++;
			}
		}
	}

	memcpy(this->_screen, this->_frame, width * height);
	
	cout.flush();

	this->_keyDispatcher->update();
	this->_schedule->updata(dt);
	AutoreleasePool::getInstace()->clear();

}
//运行场景
void Director::runWithScene(Scene* scene)
{
	if (this->_runningScene) {
		this->_runningScene->release();
	}
	this->_runningScene = scene;
	this->_runningScene->retain();
}

void Director::setAnimationInterval(float interval)
{
	this->_animationInterval = interval;
}

long long Director::getTimestamp()
{
	//微秒级
	auto now2 = std::chrono::system_clock::now();
	auto duration2 = now2.time_since_epoch();
	auto microseconds2 = std::chrono::duration_cast<std::chrono::microseconds>(duration2).count();
	return microseconds2;
}

Schedule* Director::getScheduler()
{
	return this->_schedule;
}

KeyDispatcher* dhgame::Director::getKeyDispatcher()
{
	return this->_keyDispatcher;
}
