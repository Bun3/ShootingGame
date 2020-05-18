#pragma once
class SpeacialRush :
	public CEnemy
{
private:
	CircleCollider* m_circleCollider;

public:
	SpeacialRush();
	SpeacialRush(Vec2 pos);
	virtual ~SpeacialRush();

public:

	virtual void Update()							override;
	virtual void Render()							override;
	virtual void Release()							override;
	virtual void OnTriggerEnter2D(GameObject* obj)	override;
	virtual void OnTriggerStay2D(GameObject* obj)	override;
	virtual void OnTriggerExit2D(GameObject* obj)	override;
};

