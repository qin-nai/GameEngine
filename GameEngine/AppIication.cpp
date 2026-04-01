#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include "AppIication.h"
#include "Director.h"
using namespace std;
using namespace dhgame;
static AppIication* app = nullptr;
AppIication* AppIication::getIncation()
{

	return app;
}

AppIication::AppIication() {
	app = this;
	
}
AppIication::~AppIication() {
	
}
void AppIication::run() {
	//引擎初始化
	//获取控制台句柄
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hConsole == INVALID_HANDLE_VALUE) {
		cerr << "无法获取控制台句柄\n";
	}
	//获取当前控制台光标信息
	CONSOLE_CURSOR_INFO cursorInfo;
	if (!GetConsoleCursorInfo(hConsole, &cursorInfo)) {
		cerr << "无法获取控制台光标信息\n";
	}
	//隐藏光标
	cursorInfo.bVisible = FALSE;
	if (!SetConsoleCursorInfo(hConsole, &cursorInfo)) {
		cerr << "无法设置控制台光标信息\n";
	}

	this->applicatioDidFinishLaunching();

	while(true){
		Director::getInstance()->draw();
	}
}
