#include "DXUT.h"
#include "CSpriteRenderer.h"

CSpriteRenderer::CSpriteRenderer()
{
}

CSpriteRenderer::CSpriteRenderer(cTexture* s, int e, float d)
{
	sprite = s;
	animation.SetFrame(0, e, d);
}

CSpriteRenderer::~CSpriteRenderer()
{
}

void CSpriteRenderer::Update()
{
	if (gameObject->activeSelf)
		animation.Frame();
}

void CSpriteRenderer::Render()
{
	if (gameObject->tag == OBJTAG::TAG_PLAYERBULLET)
	{
		IMAGE->Render(sprite->FindImage(animation.NowFrame),
			gameObject->transform->position, gameObject->transform->scale,
			gameObject->transform->rotation, true,
			D3DCOLOR_ARGB(EFFECT->GetTransparent(), 255, 255, 255));
	}
	else
	{
		IMAGE->Render(sprite->FindImage(animation.NowFrame),
			gameObject->transform->position,
			gameObject->transform->scale,
			gameObject->transform->rotation);
	}
}

void CSpriteRenderer::Release()
{
}

bool cFrame::Frame()
{
	m_FrameDis += (timeGetTime() - m_FrameDis) * TIME->TimeScale();
	if (m_FrameSkip <= m_FrameDis)
	{
		NowFrame = NowFrame == EndFrame ? StartFrame : NowFrame + 1;

		m_FrameDis = timeGetTime();
		m_FrameSkip = m_FrameDis + m_FrameDelay;
		return true;
	}
	return false;
}

void cFrame::SetFrame(int start, int end, unsigned long delay)
{
	NowFrame = StartFrame = start;
	EndFrame = end;
	m_FrameDelay = delay;
	m_FrameDis = timeGetTime();
	m_FrameSkip = m_FrameDis + m_FrameDelay;
}