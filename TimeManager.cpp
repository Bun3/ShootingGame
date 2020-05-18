#include "DXUT.h"
#include "TimeManager.h"

TimeManager::TimeManager()
{
	m_TimeScale = 1;
}

TimeManager::~TimeManager()
{
}

float TimeManager::DeltaTime()
{
	return m_TimeScale * DXUTGetElapsedTime();
}