#pragma once
#include <string>
#include "Node.h"
namespace dhgame
{

	class Sprite : public Node{
	protected:
		char* _data = nullptr;
		long long _size = 0;

	public:

		CREATE_FUNC(Sprite);
		static Sprite* create(const std::string path);

		void setTexture(const std::string& path);

		virtual void draw(char* frame, int width, int height, Vec2 p) override;

	};
}