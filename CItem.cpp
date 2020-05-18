#include "DXUT.h"
#include "CItem.h"

cItem::cItem()
{
	collisionCheckList = new OBJTAG[1]{ OBJTAG::TAG_PLAYER };
}

cItem::~cItem()
{
}

void cItem::Init()
{
	m_bounceTimer.SetTimer(15);
	m_bounceTimer.StartTimer();
}

void cItem::Move()
{
	transform->Translate(m_NormalVec * velocity);

	if (!m_bounceTimer.CheckTime())
	{
		//Left
		if (transform->position.x <= spriteRenderer->sprite->info.Height / 2)
			m_NormalVec.x = -m_NormalVec.x;

		//Right
		if (transform->position.x >= WINSIZEX - spriteRenderer->sprite->info.Width / 2)
			m_NormalVec.x = -m_NormalVec.x;

		//Up
		if (transform->position.y <= spriteRenderer->sprite->info.Height / 2)
			m_NormalVec.y = -m_NormalVec.y;

		//Down
		if (transform->position.y >= WINSIZEY - spriteRenderer->sprite->info.Height / 2)
			m_NormalVec.y = -m_NormalVec.y;
	}
}
