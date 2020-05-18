#include "DXUT.h"
#include "GameObject.h"

GameObject::GameObject()
{
	gameObject = this;
	transform = AddComponent<CTransform>();
	spriteRenderer = AddComponent<CSpriteRenderer>();
	normalizeVector = Vec2(0, 0);
}

GameObject::~GameObject()
{
	ComponemtsRelease();
}

void GameObject::ComponentsUpdate()
{
	for (auto iter : m_Components)
		iter->Update();
}

void GameObject::ComponentsRender()
{
	for (auto iter : m_Components)
		iter->Render();
}

void GameObject::ComponemtsRelease()
{
	SAFE_DELETE(collisionCheckList);
	for (auto component : m_Components)
	{
		component->Release();
		SAFE_DELETE(component);
	}
	m_Components.clear();
}

bool GameObject::InSideScreen()
{
	return UTILL->VecInRect(WINRECT, transform->position);
}

bool GameObject::GetObjectCollisionCheckResult(GameObject* other)
{
	if (collisionCheckList == nullptr)
		return false;

	for (int i = 0; i < sizeof(collisionCheckList) / sizeof(collisionCheckList[0]); i++)
	{
		if (collisionCheckList[i] == other->tag)
			return true;
	}
	return false;
}

CollisionDetectedType GameObject::GetCollisionDetectedType(GameObject* other)
{
	bool isBox[2] = { false,false };
	bool isCir[2] = { false,false };

	if (gameObject->GetComponent<BoxCollider>() != nullptr)
		isBox[0] = true;
	else if (gameObject->GetComponent<CircleCollider>() != nullptr)
		isCir[0] = true;
	else
		Print("Obj_1 is don't have Collider!");

	if (other->GetComponent<BoxCollider>() != nullptr)
		isBox[1] = true;
	else if (other->GetComponent<CircleCollider>() != nullptr)
		isCir[1] = true;
	else
		Print("Obj_2 is don't have Collider!");

	if (isBox[0] && isBox[1])
		return COL_BOX2BOX;
	else if (isBox[0] && isCir[1])
		return COL_BOX2CIRCLE;
	else if (isCir[0] && isBox[1])
		return COL_CIRCLE2BOX;
	else if (isCir[1] && isCir[1])
		return COL_CIRCLE2CIRCLE;
	else
		Print("COL_Detected Error!!!");
}