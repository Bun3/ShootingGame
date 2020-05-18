#include "DXUT.h"
#include "SoundManager.h"

SoundManager::SoundManager()
{
	System_Create(&m_pSystem);
	m_pSystem->init(100, FMOD_INIT_NORMAL, 0);
}

SoundManager::~SoundManager()
{
	for (auto iter : m_mapSound)
	{
		SAFE_DELETE(iter.second);
	}
	m_mapSound.clear();
	m_pSystem->release();
}

void SoundManager::AddSound(const string& _Key, const string& _Path, SoundType _sndType)
{
	auto find = m_mapSound.find(_Key);
	if (find == m_mapSound.end())
	{
		Sound* _pSound = nullptr;
		Channel* _pChannel = nullptr;

		string path = SoundPath + _Path;
		m_pSystem->createSound(path.c_str(), FMOD_DEFAULT, 0, &_pSound);
		m_mapSound.insert(make_pair(_Key, new CSound_(_pSound, _pChannel, _sndType)));
	}
}

CSound_* SoundManager::FindSound(const string& _Key)
{
	auto find = m_mapSound.find(_Key);
	if (find != m_mapSound.end())
	{
		return find->second;
	}
}

void SoundManager::Stop(CSound_* _Key)
{
	_Key->m_pChannel->stop();
}

void SoundManager::Stop(const string& _Key)
{
	auto find = m_mapSound.find(_Key);

	if (find != m_mapSound.end())
	{
		find->second->m_pChannel->stop();
	}
}

void SoundManager::Play(CSound_* _Key, bool _bRepeat)
{
	_Key->m_pSound->setMode(_bRepeat == true ? FMOD_LOOP_NORMAL : FMOD_DEFAULT);
	m_pSystem->playSound(_Key->m_pSound, NULL, false, &_Key->m_pChannel);
}

void SoundManager::Play(const string& _Key, bool _bRepeat)
{
	auto find = m_mapSound.find(_Key);

	if (find != m_mapSound.end())
	{
		find->second->m_pSound->setMode(_bRepeat == true ? FMOD_LOOP_NORMAL : FMOD_DEFAULT);
		m_pSystem->playSound(find->second->m_pSound, NULL, false, &find->second->m_pChannel);
	}
}

void SoundManager::SetTypeAllVolume(SoundType _Type, float _fVolume)
{
	for (auto iter : m_mapSound)
	{
		if (_Type == iter.second->m_Type)
		{
			iter.second->SetVolume(_fVolume);
		}
	}
}

void SoundManager::Update()
{
	m_pSystem->update();
}
