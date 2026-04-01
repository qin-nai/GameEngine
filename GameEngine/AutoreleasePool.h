#pragma once
//#include "Ref.h"
#include <vector>

namespace dhgame
{
	class Ref;
	//自动释放池，用于每帧自动释放一次节点，释放后移除池子
	class AutoreleasePool {
	protected:

		std::vector<Ref*> _object;//自动释放池用于保存

	public:
		
		static AutoreleasePool* getInstace();

		void addObject(Ref* ref);//添加节点
		void clear();//清理释放池中使用节点

	};
}