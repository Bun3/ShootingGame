#include "DXUT.h"
#include "CDirectionBullet.h"

CDirectionBullet::CDirectionBullet()
{
}

CDirectionBullet::CDirectionBullet(cTexture* sprite, Vec2 p, Vec3 s, Vec2 normalVec, Vec2 anchorPos, int col, float d, float v, GameObject* parent, int end, unsigned long delay, BulletType type)
{	
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

CDirectionBullet::~CDirectionBullet()
{
}

void CDirectionBullet::Update()
{
	transform->Translate(normalizeVector * velocity);
}

void CDirectionBullet::Render()
{
}

void CDirectionBullet::Release()
{
}

void CDirectionBullet::OnTriggerEnter2D(GameObject* obj)
{
}

void CDirectionBullet::OnTriggerStay2D(GameObject* obj)
{
}

void CDirectionBullet::OnTriggerExit2D(GameObject* obj)
{
}
