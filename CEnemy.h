#pragma once

class CEnemy :
	public CCharacter
{
public:
	std::function<void()> func[3];
	cTexture* m_dieSprite = nullptr;
	int m_dieEnd = 0;
	int m_dieDelay = 40;

public:
	CEnemy();
	virtual ~CEnemy();

public:

	virtual void Update()							PURE;
	virtual void Render()							PURE;
	virtual void Release()							PURE;
	virtual void OnTriggerEnter2D(GameObject* obj)	PURE;
	virtual void OnTriggerStay2D(GameObject* obj)	PURE;
	virtual void OnTriggerExit2D(GameObject* obj)	PURE;

	void ItemDrop();

	void HItem();
	void SItem();
	void PItem();

	void PetCreate();
	void HealCreate();
	void AttackCreate();
	void HitPlayer() { OBJECT->GETPLAYER()->m_hp--;}
};