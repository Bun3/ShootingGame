#pragma once

class CSound_
{
	friend class SoundManager;
public:
	CSound_(FMOD::Sound* _pSound, FMOD::Channel* _pChannel, SoundType _sndType);
	~CSound_();
public:
	bool IsPlaying();
	void Pause();
	void Resume();
	void SetVolume(float Volume);
	void Stop();
	void Play(bool _bRepeat);
private:
	SoundType m_Type;
	FMOD::Channel* m_pChannel = nullptr;
	FMOD::Sound* m_pSound = nullptr;
};

