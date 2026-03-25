#pragma once
#include "Node.h"
#include <string>
using namespace std;
namespace dhgame
{
	class Label : public Node {

	public:
		
		CREATE_FUNC(Label);

		void setString(string str);
		string getString();
		virtual void draw(char* frame, int width, int height, Vec2 p) override;
	private:
		 
		string _str;

	protected:
		


	};
}