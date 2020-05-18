#include "DXUT.h"
#include "Rush.h"

Rush::Rush()
{
}

Rush::Rush(Vec2 pos)
{
	transform->position = pos;
	normalizeVector = UTILL->GetVectorNormalize(UTILL->GetNewVec2(transform->position, OBJECT->GETPLAYER()->transform->position));
	transform->Rotate(normalizeVector, 290);

	spriteRenderer->sprite = IMAGE->FindImage("RushIdle");
	spriteRenderer->animation.SetFrame(0, 2, 100);
	velocity = 1000.f;
	m_hp = 3.3;

	m_circleCollider = AddComponent<CircleCollider>();
	m_circleCollider->SetColliderRange(70);
	m_circleCollider->anchorPos = Vec2(0, 18);
}

Rush::~Rush()
{
}

void Rush::Update()
{
	transform->Translate(normalizeVector * velocity);
}

void Rush::Render()
{
}

void Rush::Release()
{
}

void Rush::OnTriggerEnter2D(GameObject* obj)
{
}

void Rush::OnTriggerStay2D(GameObject* obj)
{
}

void Rush::OnTriggerExit2D(GameObject* obj)
{
}
