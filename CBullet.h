#pragma once

class CBullet : 
	public GameObject
{
public:
	float m_bulletDamage;
	GameObject* m_parent;
	BulletType m_bulletType;

public:
	CBullet();
	virtual ~CBullet();

	virtual void Update()							PURE;
	virtual void Render()							PURE;
	virtual void Release()							PURE;
	virtual void OnTriggerEnter2D(GameObject* obj)	PURE;
	virtual void OnTriggerStay2D(GameObject* obj)	PURE;
	virtual void OnTriggerExit2D(GameObject* obj)	PURE;
};

