#pragma once
#include "GameEngine_H.h"
namespace dhgame {
	class UserGurideScene : public Scene {
	protected:

		int _curScreen = 0;//当前在第几屏
		int _muneID = 0;
		Sprite* _arrow;
	public:
		
		CREATE_FUNC(UserGurideScene);
		//初始化 + 首屏
		virtual bool init() override;

		virtual void update(float dt);
		//第二屏
		void SecondScreen(float dt);
		//第三屏
		void thirdScreen(float dt);
		//显示菜单
		void showMenu();

		//按键监听
		void onKeyEvent(int keyCode);
	};
}