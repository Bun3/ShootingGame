#pragma once

class CPetBullet : public CNormalBullet
{
private:


public:
	CPetBullet();
	CPetBullet(GameObject* parent, Vec2 pos);
	virtual ~CPetBullet();

	virtual void Update()							override;
	virtual void Render()							override;
	virtual void Release()							override;
	virtual void OnTriggerEnter2D(GameObject* obj)	override;
	virtual void OnTriggerStay2D(GameObject* obj)	override;
	virtual void OnTriggerExit2D(GameObject* obj)	override;
};

