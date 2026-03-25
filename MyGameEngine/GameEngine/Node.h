#pragma once
#include <cstring>
#include <vector>

namespace dhgame
{
//创建对象的宏定义
#define CREATE_FUNC(Type)\
static Type* create()\
{\
	Type* p = new Type();\
	if (p && p->init()) {\
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

	class Node {
	protected:

		std::vector<Node*> _childs;//元素子节点
		Vec2 _pos;//节点坐标位置

	public:

		CREATE_FUNC(Node);

		virtual bool init();
		virtual void draw(char* frame, int width, int height,Vec2 p);//绘制节点
		void addChild(Node* node);//添加子节点
		void removeChild(Node* node);//删除子节点
		//获取子节点
		std::vector<Node*>& getChildren();
		//设置节点的坐标位置
		void setPosition(int x, int y);
		//获取节点的横坐标
		int getpositionX();
		//获取节点的纵坐标
		int getpositionY();
	};
}