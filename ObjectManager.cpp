#include "DXUT.h"
#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
}

void ObjectManager::Update()
{
	for (auto iter = m_GameObjList.begin(); iter != m_GameObjList.end();)
	{
		auto& obj1 = *iter;

		for (auto iter2 = m_GameObjList.begin(); iter2 != m_GameObjList.end();)
		{
			auto& obj2 = *iter2;
			if (obj1 != obj2 && obj1->GetObjectCollisionCheckResult(obj2) && obj1->activeSelf && obj2->activeSelf)
			{
				//Enter
				if (CheckCollider(obj1, obj2) && obj1->collider->enabled && obj2->collider->enabled)
				{
					if (!(obj1->collider->isEnter && obj2->collider->isEnter))
					{
						Enter(obj1, obj2);

						if (IsBullet(obj1))
						{
							if (((CBullet*)obj1)->m_bulletType == BulletType::TYPE_NORMAL)
							{
								Exit(obj1, obj2);

								obj1->SetActive(false);
								obj1->Destroy();
							}
						}
						if (IsBullet(obj2))
						{
							if (((CBullet*)obj2)->m_bulletType == BulletType::TYPE_NORMAL)
							{
								Exit(obj1, obj2);

								obj2->SetActive(false);
								obj2->Destroy();
							}
						}
					}
					else if (obj1->collider->isEnter && obj2->collider->isEnter)
					{
						Stay(obj1, obj2);
					}
				}
				//Exit
				else if (obj1->collider->isStay && obj2->collider->isStay)
				{
					Exit(obj1, obj2);
				}
			}
			iter2++;
		}

#pragma region ObjectUpdate

		if (!obj1->activeSelf && obj1->IsDestroy())
		{
			obj1->ComponemtsRelease();
			obj1->Release();
			SAFE_DELETE(obj1);
			iter = m_GameObjList.erase(iter);
		}
		else
		{
			obj1->Update();
			obj1->ComponentsUpdate();
			if (obj1->transform->position.x <= -500 || obj1->transform->position.x >= 2000 || obj1->transform->position.y <= -500 || obj1->transform->position.y >= 1500)
			{
				//Print(obj1->name + " is Erase");
				obj1->SetActive(false);
				obj1->Destroy();
			}
			iter++;
		}

#pragma endregion
	}
}

void ObjectManager::Render()
{
	for (auto iter : m_GameObjList)
	{
		iter->Render();
		iter->ComponentsRender();
	}
}

void ObjectManager::Release()
{
	for (auto iter : m_GameObjList)
	{
		(*iter).Release();
		SAFE_DELETE(iter);
	}
	m_GameObjList.clear();
}

void ObjectManager::Enter(GameObject*& obj1, GameObject*& obj2)
{
	obj1->collider->isEnter = true;
	obj2->collider->isEnter = true;

	obj1->OnTriggerEnter2D(obj2);
	obj2->OnTriggerEnter2D(obj1);
}

void ObjectManager::Stay(GameObject*& obj1, GameObject*& obj2)
{
	obj1->collider->isStay = true;
	obj2->collider->isStay = true;

	obj1->OnTriggerStay2D(obj2);
	obj2->OnTriggerStay2D(obj1);
}

void ObjectManager::Exit(GameObject*& obj1, GameObject*& obj2)
{
	obj1->collider->isEnter = false;
	obj2->collider->isEnter = false;
	obj1->collider->isStay = false;
	obj2->collider->isStay = false;

	obj1->OnTriggerExit2D(obj2);
	obj2->OnTriggerExit2D(obj1);
}

GameObject* ObjectManager::AddObj(GameObject* obj, const string& objName, OBJTAG objTag)
{
	obj->tag = objTag;
	obj->name = objName;
	m_GameObjList.emplace_back(obj);
	return obj;
}

bool ObjectManager::CheckCollider(GameObject* obj1, GameObject* obj2)
{
	bool isBox[2] = { false,false };
	bool isCir[2] = { false,false };

	if (obj1->GetComponent<BoxCollider>() != nullptr)
		isBox[0] = true;
	else if (obj1->GetComponent<CircleCollider>() != nullptr)
		isCir[0] = true;
	else
		Print("Obj_1 is don't have Collider!");

	if (obj2->GetComponent<BoxCollider>() != nullptr)
		isBox[1] = true;
	else if (obj2->GetComponent<CircleCollider>() != nullptr)
		isCir[1] = true;
	else
		Print("Obj_2 is don't have Collider!");

	if (isBox[0] && isBox[1])
		return obj1->GetComponent<BoxCollider>()->CheckCollider(obj2->GetComponent<BoxCollider>());
	else if (isBox[0] && isCir[1])
		return obj1->GetComponent<BoxCollider>()->CheckCollider(obj2->GetComponent<CircleCollider>());
	else if (isCir[0] && isBox[1])
		return obj1->GetComponent<CircleCollider>()->CheckCollider(obj2->GetComponent<BoxCollider>());
	else if (isCir[1] && isCir[1])
		return obj1->GetComponent<CircleCollider>()->CheckCollider(obj2->GetComponent<CircleCollider>());
	else
		Print("COL_Detected Error!!!");
}

bool ObjectManager::IsBullet(GameObject*& obj)
{
	return dynamic_cast<CBullet*>(obj) != nullptr;
}
