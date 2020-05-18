#include "DXUT.h"
#include "CNormalBullet.h"

CNormalBullet::CNormalBullet()
{
}

CNormalBullet::CNormalBullet(cTexture* sprite, Vec2 p, Vec3 s, float r, Vec2 normalVec, Vec2 anchorPos, int col, float d, float v, GameObject* parent, int end, unsigned long delay, BulletType type)
{
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

	m_circleCollider = AddComponent<CircleCollider>();
	m_circleCollider->anchorPos = anchorPos;
	m_circleCollider->SetColliderRange(col);
}

CNormalBullet::~CNormalBullet()
{
}

void CNormalBullet::Update()
{
	transform->Translate(normalizeVector * velocity);
}

void CNormalBullet::Render()
{
}

void CNormalBullet::Release()
{
}

void CNormalBullet::OnTriggerEnter2D(GameObject* obj)
{
}

void CNormalBullet::OnTriggerStay2D(GameObject* obj)
{
}

void CNormalBullet::OnTriggerExit2D(GameObject* obj)
{
}
