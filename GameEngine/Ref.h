#pragma once
#include "AutoreleasePool.h"
namespace dhgame
{
	
	//引用计数
	class Ref {
	protected:

		int _refCount;//被引用的次数


	public:
		Ref();
		virtual ~Ref();

		void retain();//引用方法
		void release();//释放方法

		void autorelease();

	};
}