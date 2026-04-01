#pragma once
#include "Node.h"
#include <string>
namespace dhgame
{
	// 文本类
	class Label : public Node {

	public:
		
		CREATE_FUNC(Label);
		static Label* create(const std::string text);

		void setString(std::string str);
		std::string getString();
		virtual void draw(char* frame, int width, int height, Vec2 p) override;
	private:
		 
		std::string _str;

	protected:
		


	};
}