#include "DXUT.h"
#include "SpeacialRush.h"

SpeacialRush::SpeacialRush()
{
}

SpeacialRush::SpeacialRush(Vec2 pos)
{
	transform->position = pos;
	normalizeVector = UTILL->GetVectorNormalize(UTILL->GetNewVec2(transform->position, OBJECT->GETPLAYER()->transform->position));
	transform->Rotate(normalizeVector, 290);

	spriteRenderer->sprite = IMAGE->FindImage("SRushIdle");
	spriteRenderer->animation.SetFrame(0, 2, 100);
	velocity = 1000.f;
	m_hp = 15;

	m_circleCollider = AddComponent<CircleCollider>();
	m_circleCollider->SetColliderRange(90);
	m_circleCollider->anchorPos = Vec2(-10, 18);
}

SpeacialRush::~SpeacialRush()
{
}

void SpeacialRush::Update()
{
	transform->Translate(normalizeVector * velocity);
}

void SpeacialRush::Render()
{
}

void SpeacialRush::Release()
{
}

void SpeacialRush::OnTriggerEnter2D(GameObject* obj)
{

}

void SpeacialRush::OnTriggerStay2D(GameObject* obj)
{
}

void SpeacialRush::OnTriggerExit2D(GameObject* obj)
{
}
