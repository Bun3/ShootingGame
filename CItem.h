#pragma once
class cItem :
	public GameObject
{
private:
protected:
	Vec2 m_NormalVec;
	Timer m_bounceTimer;

public:
	cItem();
	virtual ~cItem();

	void Init();

	virtual void Update()							PURE;
	virtual void Render()							PURE;
	virtual void Release()							PURE;
	virtual void OnTriggerEnter2D(GameObject* obj)	PURE;
	virtual void OnTriggerStay2D(GameObject* obj)	PURE;
	virtual void OnTriggerExit2D(GameObject* obj)	PURE;

	void Move();
};