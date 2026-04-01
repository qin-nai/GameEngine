#include <conio.h>
#include <thread>
#include "KeyDispatcher.h"

using namespace dhgame;

void KeyDispatcher::loop()
{
	int ch = 0;
	while (true)
	{
		ch = _getch();
		this->_queueMutex.lock();//上锁
		this->_keyQueue.push(ch);
		this->_queueMutex.unlock();//解锁
	}
}

KeyDispatcher::KeyDispatcher()
{
	std::thread t(&KeyDispatcher::loop, this);
	t.detach();

}

KeyDispatcher::~KeyDispatcher()
{

}
void KeyDispatcher::addKeyEvent(Node* target, KeyCallback callback)
{
	auto event = new KeyEvent();
	event->target = target;
	event->callback = callback;
	this->_events.push_back(event);

}
void KeyDispatcher::removeEventForTarget(Node* target)
{
	for (int i = this->_events.size() - 1; i >= 0; i--) {
		auto event = this->_events[i];
		if (event->target == target) {
			this->_events.erase(this->_events.begin() + i);
			delete event;
		}
	}
}

//获取按键队列
void KeyDispatcher::update()
{
	while (true)
	{
		std::unique_lock lock(this->_queueMutex);//上锁
		if (!this->_keyQueue.empty()) {
			auto key = this->_keyQueue.front();//取最前面的值
			this->_keyQueue.pop();//把当前队列最前面的人弹出去，离开队列
			lock.unlock();//解锁

			for (int i = 0; i < this->_events.size(); i++) {
				auto target = this->_events[i]->target;
				auto callback = this->_events[i]->callback;
				(target->*callback)(key);
			}
		}
		else {
			break;
		}
	}
}
