#include "DXUT.h"
#include "SpeacialShoot.h"

SpeacialShoot::SpeacialShoot()
{
}

SpeacialShoot::SpeacialShoot(float exitTime)
{

	spriteRenderer->sprite = IMAGE->FindImage("SShootIdle");
	spriteRenderer->animation.SetFrame(0, 3, 100);
	transform->position = Vec2(1800, rand() % 700 + 100);
	velocity = 1000.f;
	m_hp = 14;

	m_dieSprite = IMAGE->FindImage("SShootDie");
	m_dieDelay = 100;
	m_dieEnd = 6;

	m_boxCollider = AddComponent<BoxCollider>();
	m_boxCollider->SetColliderRange(50, 100);
	m_boxCollider->anchorPos = Vec2(-5, 0);

	m_exitTimer.SetTimer(exitTime);
	m_fireTimer.SetTimer(2);
	m_fireTimer.StartTimer();

}

SpeacialShoot::~SpeacialShoot()
{
}

void SpeacialShoot::Update()
{
	m_handPos = Vec2(transform->position.x - 10, transform->position.y);

	if (m_exitTimer.CheckTime() && !IsDestroy())
	{
		m_fireTimer.ResetTimer();
		m_fireTimer.StopTimer();
		transform->Translate(VecBackward * velocity);
	}

	if (!m_exitTimer.IsRunning())
	{
		if (transform->position.x > 1400)
			transform->Translate(VecBackward * velocity);
		else
		{
			transform->position.x = 1400;
			m_exitTimer.StartTimer();
		}
	}

	if (m_fireTimer.CheckTime() && m_exitTimer.IsRunning())
	{
		m_fireTimer.ResetTimer();

		Vec2 direction = UTILL->GetVectorNormalize(UTILL->GetNewVec2(transform->position, OBJECT->GETPLAYER()->transform->position));
		OBJECT->AddObj(
			new CSpeacialShootBullet(IMAGE->FindImage("SShootBullet"), m_handPos, VecOne * 0.6f, direction, Vec2(0, 0), 30, 1, 1500.f, this, 2),
			"ShootBullet", OBJTAG::TAG_ENEMYBULLET);
	}
	if (IsDestroy() && spriteRenderer->animation.NowFrame == 6)
	{
		SetActive(false);
	}
}

void SpeacialShoot::Render()
{
}

void SpeacialShoot::Release()
{
}

void SpeacialShoot::OnTriggerEnter2D(GameObject* obj)
{
}

void SpeacialShoot::OnTriggerStay2D(GameObject* obj)
{
}

void SpeacialShoot::OnTriggerExit2D(GameObject* obj)
{
}
