#pragma once
#include "GameEngine_H.h"
namespace dhgame {
	class AppDelegate : private AppIication {
	public:
		AppDelegate();
		~AppDelegate();
		virtual void applicatioDidFinishLaunching() override;
	private:

	};
}