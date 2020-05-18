#include "DXUT.h"
#include "CPlayer.h"

CPlayer::CPlayer()
{
	collisionCheckList = new OBJTAG[3]{ OBJTAG::TAG_ITEM,OBJTAG::TAG_ENEMYBULLET,OBJTAG::TAG_ENEMY };

	spriteRenderer->sprite = IMAGE->FindImage("PlayerIdle");
	spriteRenderer->animation.SetFrame(0, 3, 100);
	transform->position = Vec2(100, WINSIZEY / 2);
	velocity = 1000.f;
	m_hp = 3;

	m_boxCollider = AddComponent<BoxCollider>();
	((BoxCollider*)m_boxCollider)->SetColliderRange(40, 80);
	m_boxCollider->anchorPos = Vec2(10, 0);

	m_MinAttack = 0.3f;
	m_MaxAttack = 14.f;
	m_nAttack = 2.0f;

	m_cfg = 0;
	m_cg = 0.f;
	m_cv = 0.005f;
	m_ss = false;

	m_AttackKey = VK_SPACE;
	m_bulletVelocity = 2500.f;

	m_chargingSprite = IMAGE->FindImage("PlayerCharging");
	m_chargingAnimation.SetFrame(0, 2, 100);

	m_fireTimer.SetTimer(0.05);
	m_fireTimer.StartTimer();
}

CPlayer::~CPlayer()
{
}

void CPlayer::Update()
{
	m_handPos = Vec2(transform->position.x + 10, transform->position.y);

	if (m_chargingAnimation.NowFrame == 5)
	{
		isCharging = false;
		m_chargingAnimation.SetFrame(0, 2, 100);
	}
	if (isCharging)
		m_chargingAnimation.Frame();

	Move();

	if (InSideScreen())
		Attack();

	if (attackPet != nullptr)
		attackPet->Update();
	if (healPet != nullptr)
		healPet->Update();
}

void CPlayer::Render()
{
	if (isCharging)
		IMAGE->Render(m_chargingSprite->FindImage(m_chargingAnimation.NowFrame), m_handPos, m_chargingAnimation.EndFrame == 5 ? VecOne : VecOne * m_cg, chargingRot);

	if (attackPet != nullptr)
		attackPet->Render();
	if (healPet != nullptr)
		healPet->Render();
}

void CPlayer::Release()
{
	if (attackPet != nullptr)
	{
		attackPet->Release();
		SAFE_DELETE(attackPet);
	}
	if (healPet != nullptr)
	{
		healPet->Release();
		SAFE_DELETE(healPet);
	}
}

void CPlayer::OnTriggerEnter2D(GameObject* obj)
{
	if (obj->CompareTag(OBJTAG::TAG_ENEMY))
	{
		auto enemy = dynamic_cast<CEnemy*>(obj);

		enemy->HitPlayer();
		if (dynamic_cast<Rush*>(enemy) != nullptr || dynamic_cast<SpeacialRush*>(enemy) != nullptr)
		{
			EFFECT->PlayEffect(new CEffect(EFFECTTAG::TAG_ENEMYFX, IMAGE->FindImage("RushHit"), transform->position, 6));
			enemy->SetActive(false);
			enemy->Destroy();
		}
	}
	else if (obj->CompareTag(OBJTAG::TAG_ENEMYBULLET))
	{
		m_hp--;
		//EFFECT->PlayEffect(new CEffect(EFFECTTAG::TAG_ENEMYFX, IMAGE->FindImage("RushHit"), transform->position, 6));
	}
}

void CPlayer::OnTriggerStay2D(GameObject* obj)
{
}

void CPlayer::OnTriggerExit2D(GameObject* obj)
{
}

void CPlayer::Move()
{
	normalizeVector = Vec2(INPUT->GetHorizontalAxis(), INPUT->GetVerticalAxis());
	transform->Translate(normalizeVector * velocity);

	if (normalizeVector.x == -1)
		spriteRenderer->sprite = IMAGE->FindImage("PlayerBackMove");
	else
		spriteRenderer->sprite = IMAGE->FindImage("PlayerIdle");

	//Left
	if (transform->position.x <= 0)
		transform->position.x = 0;

	//Right
	if (transform->position.x >= WINSIZEX)
		transform->position.x = WINSIZEX;

	//Up
	if (transform->position.y <= 0)
		transform->position.y = 0;

	//Down
	if (transform->position.y >= WINSIZEY)
		transform->position.y = WINSIZEY;
}

void CPlayer::Attack()
{
	if (INPUT->KeyPress(m_AttackKey))
	{
		m_cg = m_cg < 1.f ? (m_cg + m_cv) : m_cg;

		if (m_cg >= 1.0f) m_cg = 1.0f;

		m_cfg = m_cg < 0.2f ? 4 : 0;
		m_ss = m_cg < 0.2f;

		if (m_cg >= 0.2f)
			Charging();
	}
	else
	{

		if (!m_ss && m_cfg == 0)
		{
			if (m_cg >= 0.2f && m_cg < 1.f)
			{
				MidShoot();
			}
			else if (m_cg >= 1.f)
				MaxShoot();
		}

		if (m_cfg > 0)
			m_cfg--;

		m_cg = 0.f;
	}

	m_ss = m_cfg == 0 ? false : true;
	m_cfg = m_cg >= 0.2f ? 0 : m_cfg;

	if (m_ss && m_cfg > 0 && m_fireTimer.CheckTime())
		MinShoot();
}

void CPlayer::Charging()
{
	isCharging = true;
}

void CPlayer::MinShoot()
{
	m_fireTimer.ResetTimer();

	OBJECT->AddObj(new CPlayerBullet(IMAGE->FindImage("PlayerBullet"), m_handPos, m_bMinSize, 0, VecForward,
		Vec2(10, 0), 20, m_MinAttack, m_bulletVelocity, this, 2, 60), "PlayerBullet", OBJTAG::TAG_PLAYERBULLET);
}

void CPlayer::MidShoot()
{
	m_fireTimer.ResetTimer();
	isCharging = false;

	Print(m_cg * m_nAttack);
	OBJECT->AddObj(new CPlayerBullet(IMAGE->FindImage("PlayerBullet"), m_handPos, m_cg * VecOne, 0, VecForward,
		Vec2(m_cg * 50, 0), m_cg * 100, m_cg * m_nAttack, m_bulletVelocity, this, 2, 60), "PlayerBullet", OBJTAG::TAG_PLAYERBULLET);
}

void CPlayer::MaxShoot()
{
	m_fireTimer.ResetTimer();
	m_chargingAnimation.SetFrame(3, 5, 100);

	OBJECT->AddObj(new CPlayerBullet(IMAGE->FindImage("PlayerMaxBullet"), m_handPos, m_bMaxSize, 0, VecForward,
		Vec2(40, 0), 110, m_MaxAttack, m_bulletVelocity, this, 2, 30, BulletType::TYPE_SPEAR), "PlayerMaxBullet", OBJTAG::TAG_PLAYERBULLET);
}

void CPlayer::PowerUpItem()
{
	if (m_MinAttack <= 1)
	{
		m_MinAttack += 0.1f;
		m_nAttack += 0.15;
		m_MaxAttack += 1;
	}
}

void CPlayer::SpeedUpItem()
{
	if (velocity <= 1700)
		velocity += 100;
}

void CPlayer::HealItem()
{
	if (m_hp < 3)
		m_hp++;
}
