#pragma once

class CEffect
{
public:
	std::function<void()> func;
	CSpriteRenderer* spriteRenderer;
	CTransform* transform;
	EFFECTTAG tag;
	Timer timer;

	bool isLoop = false;
	bool isLastFunc = false;
	bool* infinityLoop = nullptr;

public:
	CEffect();
	CEffect(EFFECTTAG _tag, cTexture* s, Vec2 pos, int end = 0, float delay = 40, Vec3 scale = VecOne, float rot = 0);
	CEffect(EFFECTTAG _tag, cTexture* s, Vec2 pos, float t = 1, int end = 0, float delay = 40, Vec3 scale = VecOne, float rot = 0);
	CEffect(EFFECTTAG _tag, cTexture* s, Vec2 pos, bool* loop, int end = 0, float delay = 40, Vec3 scale = VecOne, float rot = 0);
	virtual ~CEffect();

	void IsEnd(std::function<void()> f) { func = f; isLastFunc = true; }

public:
	void Release();
};

