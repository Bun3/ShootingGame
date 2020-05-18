#pragma once

class CPlayer :
	public CCharacter
{
private:
	cTexture* m_chargingSprite;
	cFrame m_chargingAnimation;

	CCollider* m_boxCollider;
	Timer m_fireTimer;

	float m_MinAttack;
	float m_MaxAttack;
	float m_nAttack;
	Vec3 m_bMinSize = VecOne * 0.2f;
	Vec3 m_bMaxSize = VecOne;

	//ChargingVelocity
	float m_cv;

	//ChargingGauge
	float m_cg;

	//ShootingState
	bool m_ss;

	//Continuous Firing Gauge
	int m_cfg;

	int m_AttackKey;
	float m_bulletVelocity;

	bool isCharging = false;
	float chargingRot = 360.f;

public:
	CAttackPet* attackPet = nullptr;
	CHealPet* healPet = nullptr;

public:
	CPlayer();
	virtual ~CPlayer();

public:

	virtual void Update()							override;
	virtual void Render()							override;
	virtual void Release()							override;
	virtual void OnTriggerEnter2D(GameObject* obj)	override;
	virtual void OnTriggerStay2D(GameObject* obj)	override;
	virtual void OnTriggerExit2D(GameObject* obj)	override;

	void Move();
	void Attack();

	void Charging();
	void MinShoot();
	void MidShoot();
	void MaxShoot();

	void PowerUpItem();
	void SpeedUpItem();
	void HealItem();

	int GetHp() const { return m_hp; }

	bool PetAcquisition(int percent) { return rand() % 100 < percent; }
	bool ItemDrop(int percent) { return rand() % 100 < percent; }
};