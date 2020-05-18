#pragma once
#include "singleton.h"

class TimeManager :
	public singleton<TimeManager>
{
private: 
	float m_TimeScale;

public:
	TimeManager();
	virtual ~TimeManager();

	void TimeScale(float s) { m_TimeScale = s; }
	float TimeScale() const { return m_TimeScale; };

	float DeltaTime();
};

#define TIME TimeManager::GetInstance()