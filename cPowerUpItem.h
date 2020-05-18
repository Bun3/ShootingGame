#pragma once
class cPowerUpItem :
	public cItem
{
private :
	BoxCollider* m_boxCollider;

public :
	cPowerUpItem(Vec2 pos);
	virtual ~cPowerUpItem();

	virtual void Update()							override;
	virtual void Render()							override;
	virtual void Release()							override;
	virtual void OnTriggerEnter2D(GameObject* obj)	override;
	virtual void OnTriggerStay2D(GameObject* obj)	override;
	virtual void OnTriggerExit2D(GameObject* obj)	override;
};
