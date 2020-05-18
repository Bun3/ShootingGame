#include "DXUT.h"
#include "CAttackPet.h"

CAttackPet::CAttackPet()
{
	Init(IMAGE->FindImage("AttackPetIdle"));
	spriteRenderer->animation.SetFrame(0, 3, 100);
	m_bulletTimer.SetTimer(0.4);
	m_bulletTimer.StartTimer();

}

CAttackPet::~CAttackPet()
{
}

void CAttackPet::Update()
{
	transform->position = Vec2(m_playerPos->x, m_playerPos->y - 100);

	if (m_bulletTimer.CheckTime())
	{
		m_bulletTimer.ResetTimer();
		OBJECT->AddObj(new CPetBullet(OBJECT->GETPLAYER(), Vec2(transform->position.x + 10, transform->position.y)), "PetBullet", OBJTAG::TAG_PLAYERBULLET);
	}
	spriteRenderer->animation.Frame();
}

void CAttackPet::Render()
{
	IMAGE->Render(spriteRenderer->sprite->FindImage(spriteRenderer->animation.NowFrame),
		transform->position,
		transform->scale,
		transform->rotation);
}

void CAttackPet::Release()
{
	SAFE_DELETE(spriteRenderer);
	SAFE_DELETE(transform);
}
