#include "DXUT.h"
#include "cHealItem.h"


cHealItem::cHealItem(Vec2 pos)
{
	name = "Item";
	spriteRenderer->sprite = IMAGE->FindImage("HealItem"); //수정 필요
	velocity = (500 + rand() % 400);
	transform->position = pos;
	m_boxCollider = AddComponent<BoxCollider>();
	m_boxCollider->SetColliderRange(60, 60);
	m_boxCollider->anchorPos = Vec2(0, 0);

	m_NormalVec = transform->GetRotatedDirectionVector(50 + rand() % 80);

	Init();
}

cHealItem::~cHealItem()
{
}

void cHealItem::Update()
{
	Move();
}

void cHealItem::Render()
{
}

void cHealItem::Release()
{
}

void cHealItem::OnTriggerEnter2D(GameObject* obj)
{
	if (obj->tag == OBJTAG::TAG_PLAYER)
	{
		OBJECT->GETPLAYER()->HealItem();
		SetActive(false);
		Destroy();
	}
}

void cHealItem::OnTriggerStay2D(GameObject* obj)
{
}

void cHealItem::OnTriggerExit2D(GameObject* obj)
{
}

