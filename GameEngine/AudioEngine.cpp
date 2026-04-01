#include "AudioEngine.h"
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace dhgame;

AudioEngine* AudioEngine::getInstance()
{
	static AudioEngine* instanec = new AudioEngine();

	return instanec;
}

AudioEngine::AudioEngine()
{

}

AudioEngine::~AudioEngine()
{

}

void AudioEngine::playBgMusic(const std::string path)
{
	this->stopBgMusic();
	char buffer[200];
	sprintf_s(buffer, sizeof(buffer), "open %s type mpegvide alias bgmusic", path.c_str());
	mciSendStringA(buffer, NULL, 0, NULL);
	mciSendStringA("play bgmusic repeat", NULL, 0, NULL);
}

void AudioEngine::stopBgMusic()
{
	mciSendStringA("stop bgmusic", NULL, 0, NULL);
	mciSendStringA("close bgmusic", NULL, 0, NULL);
}
