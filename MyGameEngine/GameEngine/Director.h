#pragma once
#include "Scene.h"
namespace dhgame {
	struct Size {
		int width;
		int height;
	};
	class Director
	{
	public:
		friend class AppIication;

		~Director();

		static Director* getInstance();
		void setDesignResolutionSize(int width, int height);
		void runWithScene(Scene* scene);
	private:
		Director();
		void draw();
		void drawNodes(Node* root);
	protected:
		//设计分辨率
		Size _designResolutionSize;
		char* _frame = nullptr;
		//当前运行的场景
		Scene* _runningScene = nullptr;
	};
}