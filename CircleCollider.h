#pragma once
#include "CCollider.h"
#include "BoxCollider.h"

class BoxCollider;
class CircleCollider :
	public CCollider
{
private:
	Vec2 m_ChangedPos;
	RECT m_EllipseRect;

public:
	int radius;

public:
	CircleCollider();
	CircleCollider(int diameter);
	virtual ~CircleCollider();

public:
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	void SetColliderRange(int length);

	bool CheckCollider(BoxCollider* other);
	bool CheckCollider(CircleCollider* other);
};