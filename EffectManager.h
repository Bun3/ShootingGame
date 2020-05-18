#pragma once
#include "singleton.h"
#include "CEffect.h"

class EffectManager :
	public singleton<EffectManager>
{
private:
	int transparent;
	list<CEffect*> m_EffectList;
public:
	EffectManager();
	virtual ~EffectManager();

	void Update();
	void Render();
	void Release();

	CEffect* PlayEffect(CEffect* e);
	void SetTransparent(int t) { transparent = t; }
	int GetTransparent() { return transparent; }
};

#define EFFECT EffectManager::GetInstance()