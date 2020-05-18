#include "DXUT.h"
#include "EffectManager.h"

EffectManager::EffectManager()
{
}

EffectManager::~EffectManager()
{
}

void EffectManager::Update()
{
	for (auto iter = m_EffectList.begin(); iter != m_EffectList.end();)
	{
		auto& fx = *iter;
		if (fx->isLoop)
		{
			if (fx->infinityLoop == nullptr)
			{
				if (fx->timer.CheckTime() && fx->spriteRenderer->animation.NowFrame == fx->spriteRenderer->animation.EndFrame)
				{
					fx->Release();
					SAFE_DELETE(fx);
					iter = m_EffectList.erase(iter);
				}
				else
				{
					fx->spriteRenderer->animation.Frame();
					iter++;
				}
			}
			else
			{
				if (!fx->infinityLoop)
				{
					fx->infinityLoop = nullptr;
					fx->Release();
					SAFE_DELETE(fx);
					iter = m_EffectList.erase(iter);
				}
				else
				{
					fx->spriteRenderer->animation.Frame();
					iter++;
				}
			}
		}
		else
		{
			if (fx->spriteRenderer->animation.NowFrame == fx->spriteRenderer->animation.EndFrame)
			{
				if (fx->isLastFunc)
					fx->func();
				fx->Release();
				SAFE_DELETE(fx);
				iter = m_EffectList.erase(iter);
			}
			else
			{
				fx->spriteRenderer->animation.Frame();
				iter++;
			}
		}
	}
}

void EffectManager::Render()
{
	for (auto iter : m_EffectList)
	{
		auto& fx = *iter;
		if(fx.tag == TAG_PLAYERFX)
			IMAGE->Render(fx.spriteRenderer->sprite->FindImage(fx.spriteRenderer->animation.NowFrame), fx.transform->position, fx.transform->scale, fx.transform->rotation, true, D3DCOLOR_ARGB(transparent, 255, 255, 255));
		else
			IMAGE->Render(fx.spriteRenderer->sprite->FindImage(fx.spriteRenderer->animation.NowFrame), fx.transform->position, fx.transform->scale, fx.transform->rotation);
	}
}

void EffectManager::Release()
{
	for (auto iter : m_EffectList)
	{
		iter->Release();
		SAFE_DELETE(iter);
	}
	m_EffectList.clear();
}

CEffect* EffectManager::PlayEffect(CEffect* e)
{
	m_EffectList.emplace_back(e);
	return e;
}