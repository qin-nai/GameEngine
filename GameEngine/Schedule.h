#pragma once
#include <vector>

namespace dhgame
{
	class Node;
	typedef void (Node::*CallbackFunc)(float);

	//回调任务
	struct CallbackTast
	{
		Node* target;//那个节点需要定时回调
		dhgame::CallbackFunc callback;//节点回调函数
		float duration;//多长时间调用一次（单位：秒）
		float leftTime;//还剩下多长时间调用（单位：秒）
		bool isRepeat;//是否重复
	};
	//定时器
	class Schedule {
	protected:

		std::vector<CallbackTast*>_task;//所有的定时任务
		
	public:

		void schedule(Node* target, CallbackFunc callback, float duration, bool isRepeat);

		void updata(float dt);

		//异常计时任务
		void unschedleForTarget(Node* target);

	};
}