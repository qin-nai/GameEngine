#pragma once
#include <cstring>
#include <vector>

namespace dhgame
{
	
	class Node {
	protected:

		std::vector<Node*> _childs;//元素子节点
		int _x = 0;//元素横坐标
		int _y = 0;//元素纵坐标

	public:

		virtual void draw(char* frame, int width, int height);//绘制节点
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