#pragma once
#include <string>

namespace dhgame
{
	
	//引用计数
	class AudioEngine {
	protected:



	public:

		static AudioEngine* getInstance();

		AudioEngine();
		~AudioEngine();

		void playBgMusic(const std::string path);//播放音乐
		void stopBgMusic();//关闭音乐

	};
}