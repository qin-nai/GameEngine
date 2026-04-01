#pragma once
#include "Scene.h"
#include "Schedule.h"
#include "KeyDispatcher.h"

namespace dhgame {
	struct Size {
		int width;
		int height;
	};
	class Director
	{
	protected:
		
		friend class AppIication;
		Size _designResolutionSize;//设计分辨率
		char* _frame = nullptr;//节点画面缓存
		char* _screen = nullptr;//屏幕画面缓存
		Scene* _runningScene = nullptr;//当前运行的场景节点
		int _col = 0;//当前控制台的列数
		int _row = 0;//当前控制台的行数
		float _animationInterval = 0.1;//每帧的时间间隔(单位：秒)
		long long _lastTimestamp = 0;//上次的时间戳

		Schedule* _schedule;//定时器，全局唯一
		KeyDispatcher* _keyDispatcher;//按键派发器，全局唯一

	private:
		Director();
		void draw();
		void drawNodes(Node* root , Vec2 p);
		//设置光标位置
		void setCursorPosition(int x, int y);

		//获取当前时间戳
		long long getTimestamp();

	public:
		~Director();

		static Director* getInstance();

		Schedule* getScheduler();//获取定时器
		KeyDispatcher* getKeyDispatcher();//获取事件派发器
		void setDesignResolutionSize(int width, int height);
		void runWithScene(Scene* scene);
	
		void setAnimationInterval(float interval);//设置每帧间隔
	};
}