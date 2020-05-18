#include "DXUT.h"
#include "CSpeacialShootBullet.h"

CSpeacialShootBullet::CSpeacialShootBullet()
{
}

CSpeacialShootBullet::CSpeacialShootBullet(cTexture* sprite, Vec2 p, Vec3 s, Vec2 normal, Vec2 anchorPos, int col, float d, float v, GameObject* parent, int end, unsigned long delay, BulletType type)
{
	collisionCheckList = new OBJTAG[1]{ OBJTAG::TAG_PLAYER };

	spriteRenderer->animation.SetFrame(0, end, delay);
	spriteRenderer->sprite = sprite;
	transform->position = p;
	transform->scale = s;
	normalizeVector = normal;
	transform->Rotate(normalizeVector, 270);
	m_bulletType = type;
	m_bulletDamage = d;
	m_parent = parent;
	velocity = v;

	m_circleCollider = AddComponent<CircleCollider>();
	m_circleCollider->anchorPos = anchorPos;
	m_circleCollider->SetColliderRange(col);
}

CSpeacialShootBullet::~CSpeacialShootBullet()
{
}

void CSpeacialShootBullet::Update()
{
	transform->Translate(normalizeVector * velocity);
}

void CSpeacialShootBullet::Render()
{
}

void CSpeacialShootBullet::Release()
{
}

void CSpeacialShootBullet::OnTriggerEnter2D(GameObject* obj)
{
	if (obj->tag == OBJTAG::TAG_PLAYER)
		EFFECT->PlayEffect(new CEffect(EFFECTTAG::TAG_ENEMYFX, IMAGE->FindImage("SShootHit"), transform->position, 6));
}

void CSpeacialShootBullet::OnTriggerStay2D(GameObject* obj)
{
}

void CSpeacialShootBullet::OnTriggerExit2D(GameObject* obj)
{
}
