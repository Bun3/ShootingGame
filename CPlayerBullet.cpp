#include "DXUT.h"
#include "CPlayerBullet.h"

CPlayerBullet::CPlayerBullet()
{
}

CPlayerBullet::CPlayerBullet(cTexture* sprite, Vec2 p, Vec3 s, float r, Vec2 normalVec, Vec2 anchorPos, int col, float d, float v, GameObject* parent, int end, unsigned long delay, BulletType type)
{
	collisionCheckList = new OBJTAG[1]{ OBJTAG::TAG_ENEMY };

	spriteRenderer->animation.SetFrame(0, end, delay);
	spriteRenderer->sprite = sprite;
	normalizeVector = normalVec;
	transform->position = p;
	transform->rotation = r;
	transform->scale = s;
	m_bulletType = type;
	m_bulletDamage = d;
	m_parent = parent;
	velocity = v;

	isMax = transform->scale == VecOne;
	m_circleCollider = AddComponent<CircleCollider>();
	m_circleCollider->anchorPos = anchorPos;
	m_circleCollider->SetColliderRange(col);
}

CPlayerBullet::~CPlayerBullet()
{
}

void CPlayerBullet::Update()
{
	CNormalBullet::Update();
}

void CPlayerBullet::Render()
{
}

void CPlayerBullet::Release()
{
}

void CPlayerBullet::OnTriggerEnter2D(GameObject* obj)
{
#pragma region HitEffect

	if (obj->collider->enabled)
	{
		if (isMax)
		{
			Vec2 vec = UTILL->GetVectorNormalize(UTILL->GetNewVec2(obj->transform->position, transform->position));
			EFFECT->PlayEffect(new CEffect(EFFECTTAG::TAG_PLAYERFX, IMAGE->FindImage("PlayerMaxHit"), obj->transform->position + (vec * 40), 6));
		}
		else
			EFFECT->PlayEffect(new CEffect(EFFECTTAG::TAG_PLAYERFX, IMAGE->FindImage("PlayerNormalHit"), transform->position, 7));
	}

#pragma endregion

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

void CPlayerBullet::OnTriggerStay2D(GameObject* obj)
{
}

void CPlayerBullet::OnTriggerExit2D(GameObject* obj)
{
}
