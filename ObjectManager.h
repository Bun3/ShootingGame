#pragma once
#include "singleton.h"
#include "GameObject.h"

class CPlayer;
class ObjectManager :
	public singleton<ObjectManager>
{

private:
	list<GameObject *> m_GameObjList;
	CPlayer* m_Player;
public:
	ObjectManager();
	virtual ~ObjectManager();

	void Update();
	void Render();
	void Release();

	void Enter(GameObject*& obj1, GameObject*& obj2);
	void Stay(GameObject*& obj1, GameObject*& obj2);
	void Exit(GameObject*& obj1, GameObject*& obj2);

	GameObject* AddObj(GameObject* obj, const string& objName, OBJTAG objTag);

	CPlayer* GETPLAYER() { return m_Player; }
	void SETPLAYER(CPlayer* player) { m_Player = player; }

	bool CheckCollider(GameObject* obj1, GameObject* obj2);
	bool IsBullet(GameObject*& obj);

	list<GameObject*>& GetObjList() { return m_GameObjList; }
};

#define OBJECT ObjectManager::GetInstance()