#include "Schedule.h"

using namespace dhgame;

void Schedule::schedule(Node* target, CallbackFunc callback, float duration, bool isRepeat)
{
	auto task = new CallbackTast();
	task->target = target;
	task->callback = callback;
	task->duration = duration;
	task->leftTime = duration;
	task->isRepeat = isRepeat;

	this->_task.push_back(task);

}

void Schedule::updata(float dt)
{
	for (int i = this->_task.size() - 1; i >= 0; i--) {
		auto task = this->_task[i];
		task->leftTime = task->leftTime - dt;
		if (task->leftTime > 0) continue;

		auto target = task->target;
		auto callback = task->callback;
		(target->*callback)(task->duration ? task->duration : dt);

		if (task->isRepeat) {
			task->leftTime = task->duration;
		}
		else {
			this->_task.erase(this->_task.begin() + i);
			delete task;
		}
	}
}

void Schedule::unschedleForTarget(Node* target)
{
	for (int i = this->_task.size() - 1; i >= 0; i--) {
		auto task = this->_task[i];
		if (target == task->target) {
			this->_task.erase(this->_task.begin() + i);
			delete task;
		}
	}
}
