#pragma once

class CSpriteRenderer;
class CTransform;
class CPet
{
protected:
	CSpriteRenderer* spriteRenderer;
	CTransform* transform;
	Vec2* m_playerPos;

	void Init(cTexture* s);
public:
	CPet();
	virtual ~CPet();

	virtual void Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;
};