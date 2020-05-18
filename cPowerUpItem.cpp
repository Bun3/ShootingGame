#include "DXUT.h"
#include "cPowerUpItem.h"

cPowerUpItem::cPowerUpItem(Vec2 pos)
{
	name = "Item";
	spriteRenderer->sprite = IMAGE->FindImage("PowerUpItem");
	velocity = (500 + rand() % 400);
	transform->position = pos;
	m_boxCollider = AddComponent<BoxCollider>();
	m_boxCollider->SetColliderRange(47, 60);
	m_boxCollider->anchorPos = Vec2(0, 0);

	m_NormalVec = transform->GetRotatedDirectionVector(50 + rand() % 80);

	Init();
}

cPowerUpItem::~cPowerUpItem()
{
}

void cPowerUpItem::Update()
{
	Move();
}

void cPowerUpItem::Render()
{
}

void cPowerUpItem::Release()
{
}

void cPowerUpItem::OnTriggerEnter2D(GameObject* obj)
{
	if (obj->tag == OBJTAG::TAG_PLAYER)
	{
		OBJECT->GETPLAYER()->PowerUpItem();
		SetActive(false);
		Destroy();
	}
}

void cPowerUpItem::OnTriggerStay2D(GameObject* obj)
{
}

void cPowerUpItem::OnTriggerExit2D(GameObject* obj)
{
}
