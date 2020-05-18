#pragma once
#include "CCollider.h"
#include "CircleCollider.h"

class CircleCollider;
class BoxCollider : 
	public CCollider
{
private:
	int w, h;

public:
	RECT rect;

public:
	BoxCollider();
	BoxCollider(cTexture* sprite);
	virtual ~BoxCollider();

public:
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	void SetColliderRange(int width, int height);

	bool CheckCollider(BoxCollider* other);
	bool CheckCollider(CircleCollider* other);
};

