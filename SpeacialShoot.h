#pragma once

class CSpeacialShootBullet;
class SpeacialShoot :
	public CEnemy
{
private:
	BoxCollider* m_boxCollider;
	Timer m_exitTimer;
	Timer m_fireTimer;

	Vec2 v[3];

public:
	SpeacialShoot();
	SpeacialShoot(float exitTime);
	virtual ~SpeacialShoot();

public:

	virtual void Update()							override;
	virtual void Render()							override;
	virtual void Release()							override;
	virtual void OnTriggerEnter2D(GameObject* obj)	override;
	virtual void OnTriggerStay2D(GameObject* obj)	override;
	virtual void OnTriggerExit2D(GameObject* obj)	override;
};

