#pragma once

namespace dhgame
{
	class AppIication {

	public:
		static AppIication* getIncation();
		AppIication();
		~AppIication();
		void run();
		virtual void applicatioDidFinishLaunching()=0;
		
	private:
		
	protected:
		
	};
}