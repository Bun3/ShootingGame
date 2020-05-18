#include "DXUT.h"
#include "CPet.h"

CPet::CPet()
{
}

CPet::~CPet()
{
}

void CPet::Init(cTexture* s)
{
	spriteRenderer = new CSpriteRenderer;
	transform = new CTransform;

	spriteRenderer->sprite = s;
	m_playerPos = &OBJECT->GETPLAYER()->transform->position;
}
