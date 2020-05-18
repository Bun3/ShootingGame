#pragma once

class CCharacter :
	public GameObject
{
protected:
	Vec2 m_handPos;
public:
	float m_hp;

public:
	CCharacter();
	virtual ~CCharacter();

public:

	virtual void Update()							PURE;
	virtual void Render()							PURE;
	virtual void Release()							PURE;
	virtual void OnTriggerEnter2D(GameObject* obj)	PURE;
	virtual void OnTriggerStay2D(GameObject* obj)	PURE;
	virtual void OnTriggerExit2D(GameObject* obj)	PURE;

	void HitEffect();
};