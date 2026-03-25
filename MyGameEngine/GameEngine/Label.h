#pragma once
#include "Node.h"
#include <string>
using namespace std;
namespace dhgame
{
	class Label : public Node {

	public:
		
		void setString(string str);
		string getString();
		virtual void draw(char* frame, int width, int height) override;
	private:
		 
		string _str;

	protected:
		


	};
}