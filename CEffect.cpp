#include "DXUT.h"
#include "CEffect.h"

CEffect::CEffect()
{
}

CEffect::CEffect(EFFECTTAG _tag, cTexture* s, Vec2 pos, int end, float delay, Vec3 scale, float rot)
{
	spriteRenderer = new CSpriteRenderer(s, end, delay);
	transform = new CTransform(pos, scale, rot);
	tag = _tag;
}

CEffect::CEffect(EFFECTTAG _tag, cTexture* s, Vec2 pos, float t, int end, float delay, Vec3 scale, float rot)
{
	spriteRenderer = new CSpriteRenderer(s, end, delay);
	transform = new CTransform(pos, scale, rot);
	timer.SetTimer(t);
	isLoop = true;
	tag = _tag;
}

CEffect::CEffect(EFFECTTAG _tag, cTexture* s, Vec2 pos, bool* loop, int end, float delay, Vec3 scale, float rot)
{
	spriteRenderer = new CSpriteRenderer(s, end, delay);
	transform = new CTransform(pos, scale, rot);
	infinityLoop = loop;
	isLoop = true;
	tag = _tag;
}

CEffect::~CEffect()
{
}

void CEffect::Release()
{
	spriteRenderer->Release();
	transform->Release();
	SAFE_DELETE(spriteRenderer);
	SAFE_DELETE(transform);
}
