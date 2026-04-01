#pragma once
#include <cstring>
#include <vector>
#include "Schedule.h"
#include "Ref.h"
#include "KeyDispatcher.h"

namespace dhgame
{
//创建对象的宏定义
#define CREATE_FUNC(Type)\
static Type* create()\
{\
	Type* p = new Type();\
	if (p && p->init()) {\
		p->autorelease();\
		return p;\
	}\
	else {\
		delete p;\
	p = nullptr;\
	return p;\
	}\
};

	struct Vec2
	{
		int x = 0;
		int y = 0;
	};

	class Node : public Ref{
	protected:

		std::vector<Node*> _childs;//元素子节点
		Vec2 _pos;//节点坐标位置

	public:

		~Node();

		CREATE_FUNC(Node);

		virtual void update(float dt);

		virtual bool init();
		virtual void draw(char* frame, int width, int height,Vec2 p);//绘制节点
		void addChild(Node* node);//添加子节点
		void removeChild(Node* node);//删除子节点

		//删除所有子节点
		void removeAllChil();

		//获取子节点
		std::vector<Node*>& getChildren();
		//设置节点的坐标位置
		void setPosition(int x, int y);
		//获取节点的横坐标
		int getpositionX();
		//获取节点的纵坐标
		int getpositionY();

		//启用update，每帧回调
		void scheduleUpdate();
		//启用自定义回调
		void schedule(Node* target, CallbackFunc callback, float duration, bool isRepeat);

		//停止所有定时器
		void unscheduleAll();

		//添加按键事件
		void addKeyEvent(Node* target, KeyCallback callback);
	};
}