#include "DXUT.h"
#include "CHealPet.h"

CHealPet::CHealPet()
{
	Init(IMAGE->FindImage("HealPetIdle"));
	spriteRenderer->animation.SetFrame(0, 3, 100);
	m_healTimer.SetTimer(10);
	m_healTimer.StartTimer();
}

CHealPet::~CHealPet()
{
}

void CHealPet::Update()
{
	transform->position = Vec2(m_playerPos->x, m_playerPos->y + 100);

	if (m_healTimer.CheckTime())
	{
		m_healTimer.ResetTimer();
		if (OBJECT->GETPLAYER()->m_hp < 3)
		{
			Heal();
		}
		else if (OBJECT->GETPLAYER()->m_hp >= 3)
		{
			isAlreadyHeal = true;
		}
	}

	if (isAlreadyHeal && OBJECT->GETPLAYER()->m_hp < 3)
	{
		isAlreadyHeal = false;
		Heal();
	}
	spriteRenderer->animation.Frame();
}

void CHealPet::Render()
{
	IMAGE->Render(spriteRenderer->sprite->FindImage(spriteRenderer->animation.NowFrame),
		transform->position,
		transform->scale,
		transform->rotation);
}

void CHealPet::Release()
{
	SAFE_DELETE(spriteRenderer);
	SAFE_DELETE(transform);
}

void CHealPet::Heal()
{
	EFFECT->PlayEffect(new CEffect(EFFECTTAG::TAG_PLAYERFX, IMAGE->FindImage("PetHealEffect"), transform->position, 3, 40, VecOne));
	OBJECT->GETPLAYER()->m_hp++;
	Print("Heal" + to_string(OBJECT->GETPLAYER()->m_hp));
}
