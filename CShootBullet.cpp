#include "DXUT.h"
#include "CShootBullet.h"

CShootBullet::CShootBullet()
{
}

CShootBullet::CShootBullet(cTexture* sprite, Vec2 p, Vec3 s, Vec2 normalVec, Vec2 anchorPos, int col, float d, float v, GameObject* parent, int end, unsigned long delay, BulletType type)
{
	collisionCheckList = new OBJTAG[1]{ OBJTAG::TAG_PLAYER };

	spriteRenderer->animation.SetFrame(0, end, delay);
	transform->Rotate(normalVec, 270);
	spriteRenderer->sprite = sprite;
	normalizeVector = normalVec;
	transform->position = p;
	transform->scale = s;
	m_bulletType = type;
	m_bulletDamage = d;
	m_parent = parent;
	velocity = v;

	m_circleCollider = AddComponent<CircleCollider>();
	m_circleCollider->anchorPos = anchorPos;
	m_circleCollider->SetColliderRange(col);
}

CShootBullet::~CShootBullet()
{
}

void CShootBullet::Update()
{
	CDirectionBullet::Update();
}

void CShootBullet::Render()
{
}

void CShootBullet::Release()
{
}

void CShootBullet::OnTriggerEnter2D(GameObject* obj)
{
	if (obj->tag == OBJTAG::TAG_PLAYER)
	{
		EFFECT->PlayEffect(new CEffect(EFFECTTAG::TAG_ENEMYFX, IMAGE->FindImage("ShootHit"), transform->position, 6, 40, VecOne));
	}
}

void CShootBullet::OnTriggerStay2D(GameObject* obj)
{
}

void CShootBullet::OnTriggerExit2D(GameObject* obj)
{
}
