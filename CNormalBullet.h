#pragma once
class CNormalBullet :
	public CBullet
{
protected:
	CircleCollider* m_circleCollider;

public:
	CNormalBullet();
	CNormalBullet(cTexture* sprite, Vec2 p, Vec3 s, float r, Vec2 normalVec,
		Vec2 anchorPos, int col, float d, float v, GameObject* parent,
		int end = 0, unsigned long delay = 40, BulletType type = BulletType::TYPE_NORMAL);
	virtual ~CNormalBullet();

	virtual void Update()							override;
	virtual void Render()							override;
	virtual void Release()							override;
	virtual void OnTriggerEnter2D(GameObject* obj)	override;
	virtual void OnTriggerStay2D(GameObject* obj)	override;
	virtual void OnTriggerExit2D(GameObject* obj)	override;
};