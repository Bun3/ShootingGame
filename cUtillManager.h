#pragma once
#include "singleton.h"

class Timer
{
private:
	float timer = 0;
	float result = 0;
	bool isCheckTime = false;
public:
	bool CheckTime();
	bool IsRunning() const { return isCheckTime; }

	void StartTimer() { isCheckTime = true; }
	void StopTimer() { isCheckTime = false; }

	void SetTimer(float _t) { timer = _t; }
	void ResetTimer() { result = 0; }
};

class cUtillManager :
	public singleton<cUtillManager>
{
public:
	bool VecInRect(const RECT& _r, Vec2 v, float _radius = 0);
	float VecLength(Vec2 vec);
	Vec2 GetVectorNormalize(Vec2 vec);
	Vec2 GetNewVec2(Vec2 startVec, Vec2 targetVec) { return Vec2(targetVec.x - startVec.x, targetVec.y - startVec.y); };
	Vec2 GetNormalVector(float degree);
};

#define UTILL cUtillManager::GetInstance()