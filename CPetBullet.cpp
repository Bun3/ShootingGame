#include "DXUT.h"
#include "CPetBullet.h"

CPetBullet::CPetBullet()
{

}

CPetBullet::CPetBullet(GameObject* parent, Vec2 pos)
{
	collisionCheckList = new OBJTAG[1]{ OBJTAG::TAG_ENEMY };

	m_parent = parent;
	spriteRenderer->sprite = IMAGE->FindImage("PetBullet");
	m_bulletType = BulletType::TYPE_NORMAL;
	transform->scale = VecOne * 0.5f;
	normalizeVector = VecForward;
	transform->position = pos;
	transform->rotation = 0;
	m_bulletDamage = 3;
	velocity = 1000.f;

	m_circleCollider = AddComponent<CircleCollider>();
	m_circleCollider->anchorPos = Vec2(0, 0);
	m_circleCollider->SetColliderRange(30);
}

CPetBullet::~CPetBullet()
{
}

void CPetBullet::Update()
{
	transform->Translate(normalizeVector * velocity);
}

void CPetBullet::Render()
{
}

void CPetBullet::Release()
{
}

void CPetBullet::OnTriggerEnter2D(GameObject* obj)
{
	EFFECT->PlayEffect(new CEffect(EFFECTTAG::TAG_PLAYERFX, IMAGE->FindImage("PlayerNormalHit"), transform->position, 7));
	if (obj->CompareTag(OBJTAG::TAG_ENEMY))
	{
		auto enemy = dynamic_cast<CEnemy*>(obj);

		enemy->m_hp -= m_bulletDamage;
		if (enemy->m_hp <= 0 && !enemy->IsDestroy())
		{
			Print("¾ý");
			enemy->ItemDrop();
			enemy->PetCreate();
			enemy->Destroy();
			enemy->collider->enabled = false;
			if (enemy->m_dieSprite != nullptr)
			{
				enemy->spriteRenderer->sprite = enemy->m_dieSprite;
				enemy->spriteRenderer->animation.SetFrame(0, enemy->m_dieEnd, enemy->m_dieDelay);
			}
			else
			{
				enemy->SetActive(false);
				EFFECT->PlayEffect(new CEffect(EFFECTTAG::TAG_ENEMYFX, IMAGE->FindImage("RushHit"), enemy->transform->position, 6));
			}
		}
	}
}

void CPetBullet::OnTriggerStay2D(GameObject* obj)
{
}

void CPetBullet::OnTriggerExit2D(GameObject* obj)
{
}