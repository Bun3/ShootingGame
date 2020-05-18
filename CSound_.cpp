#include "DXUT.h"
#include "CSound_.h"

CSound_::CSound_(FMOD::Sound* _pSound, FMOD::Channel* _pChannel, SoundType _sndType) :
	m_pSound(_pSound), m_pChannel(_pChannel), m_Type(_sndType)
{
}

CSound_::~CSound_()
{
	m_pSound->release();
}

bool CSound_::IsPlaying()
{
	bool result;
	m_pChannel->isPlaying(&result);
	return result;
}

void CSound_::Pause()
{
	m_pChannel->setPaused(true);
}

void CSound_::Resume()
{
	m_pChannel->setPaused(false);
}

void CSound_::SetVolume(float Volume)
{
	m_pChannel->setVolume(Volume);
}

void CSound_::Stop()
{
	m_pChannel->stop();
}

void CSound_::Play(bool _bRepeat)
{

}
