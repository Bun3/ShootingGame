#pragma once
#include "Component.h"

class CCollider :
	public Component
{
protected:
	bool isDebug = false;

public:
	bool isEnter = false;
	bool isStay = false;
	bool isExit = false;

	Vec2 anchorPos = Vec2(0, 0);

public:
	CCollider();
	virtual ~CCollider();

public:
	virtual void Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;
};

