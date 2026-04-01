#include "Ref.h"

using namespace dhgame;

Ref::Ref()
{
	this->_refCount = 0;
}

Ref::~Ref()
{
	int a = 0;
}

void Ref::retain()
{
	this->_refCount++;
}

void Ref::release()
{
	this->_refCount--;
	if (this->_refCount == 0) {
		delete this;
	}
}

void Ref::autorelease()
{
	AutoreleasePool::getInstace()->addObject(this);
}
