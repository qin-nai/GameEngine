#pragma once
#include <queue>
#include <mutex>
#include <vector>

namespace dhgame
{
	class Node;
	typedef void(Node::* KeyCallback)(int keyCode);

	struct KeyEvent
	{
		Node* target;
		KeyCallback callback;
	};

	class KeyDispatcher {
	protected:
		std::mutex _queueMutex;
		std::queue<int> _keyQueue;//保存所有按键队列
		std::vector<KeyEvent*> _events;//保存的回调

	private:

		void loop();

	public:
		KeyDispatcher();
		~KeyDispatcher();

		void addKeyEvent(Node* target, KeyCallback callback);//添加按键事件
		void removeEventForTarget(Node* target);//移除按键事件

		void update();
	};
}