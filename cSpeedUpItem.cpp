#include "DXUT.h"
#include "cSpeedUpItem.h"

cSpeedUpItem::cSpeedUpItem(Vec2 pos)
{
	name = "Item";
	spriteRenderer->sprite = IMAGE->FindImage("SpeedUpItem");
	velocity = (500 + rand() % 400);
	transform->position = pos;
	m_boxCollider = AddComponent<BoxCollider>();
	m_boxCollider->SetColliderRange(80, 43);
	m_boxCollider->anchorPos = Vec2(20, 0);

	m_NormalVec = transform->GetRotatedDirectionVector(50 + rand() % 80);

	Init();
}

cSpeedUpItem::~cSpeedUpItem()
{
}

void cSpeedUpItem::Update()
{
	Move();
}

void cSpeedUpItem::Render()
{
}

void cSpeedUpItem::Release()
{
}

void cSpeedUpItem::OnTriggerEnter2D(GameObject* obj)
{
	if (obj->tag == OBJTAG::TAG_PLAYER)
	{
		OBJECT->GETPLAYER()->SpeedUpItem();
		SetActive(false);
		Destroy();
	}
}

void cSpeedUpItem::OnTriggerStay2D(GameObject* obj)
{
}

void cSpeedUpItem::OnTriggerExit2D(GameObject* obj)
{
}