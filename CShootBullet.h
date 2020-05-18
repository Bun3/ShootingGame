#pragma once
class CShootBullet :
	public CDirectionBullet
{
protected:
	CircleCollider* m_circleCollider;

public:
	CShootBullet();
	//CDirectionBullet(CNormalBullet* bullet, Vec2 anchorPos, float colRadius, BulletType type = BulletType::TYPE_NORMAL);
	CShootBullet(cTexture* sprite, Vec2 p, Vec3 s, Vec2 normalVec,
		Vec2 anchorPos, int col, float d, float v, GameObject* parent,
		int end = 0, unsigned long delay = 40, BulletType type = BulletType::TYPE_NORMAL);
	virtual ~CShootBullet();

	virtual void Update()							override;
	virtual void Render()							override;
	virtual void Release()							override;
	virtual void OnTriggerEnter2D(GameObject* obj)	override;
	virtual void OnTriggerStay2D(GameObject* obj)	override;
	virtual void OnTriggerExit2D(GameObject* obj)	override;
};

