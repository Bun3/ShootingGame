#pragma once
#include "Component.h"

class cFrame
{
private:
	unsigned long m_FrameDelay;
	unsigned long m_FrameSkip;
	unsigned long m_FrameDis = 0;

public:
	int StartFrame;
	int EndFrame;
	int NowFrame;

	bool Frame();
	void SetFrame(int start, int end, unsigned long delay);
	void ChangeDelay(unsigned long delay) { m_FrameDelay = delay; }
};

class CSpriteRenderer :
	public Component
{
public:
	cTexture* sprite;
	cFrame animation;

public:
	CSpriteRenderer();
	CSpriteRenderer(cTexture* s, int e = 0, float d = 40);
	virtual ~CSpriteRenderer();

public:
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

