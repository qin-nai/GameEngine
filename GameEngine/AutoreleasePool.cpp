#include "AutoreleasePool.h"
#include "Ref.h"

using namespace dhgame;

AutoreleasePool* AutoreleasePool::getInstace()
{
	static AutoreleasePool* instance = new AutoreleasePool();


	return instance;
}

void AutoreleasePool::addObject(Ref* ref)
{
	ref->retain();
	this->_object.push_back(ref);
}

void AutoreleasePool::clear()
{
	for (int i = 0; i < this->_object.size(); i++) {
		this->_object[i]->release();
	}
	this->_object.clear();
}
