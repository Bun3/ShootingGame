#pragma once
#include "singleton.h"
#include "CSound_.h"

class SoundManager :
	public singleton<SoundManager>
{
private:
	string SoundPath = "./Resource/Sound/";

public:
	SoundManager();
	~SoundManager();

	void AddSound(const string& _Key, const string& _Path, SoundType _sndType);

	CSound_* FindSound(const string& _Key);

	void Stop(CSound_* _Key);
	void Stop(const string& _Key);

	void Play(CSound_* _Key, bool _bRepeat);
	void Play(const string& _Key, bool _bRepeat);

	void SetTypeAllVolume(SoundType _Type, float _fVolume);

	void Update();
private:
	System* m_pSystem;

	map<string, CSound_*> m_mapSound;
};

#define SOUND SoundManager::GetInstance()
