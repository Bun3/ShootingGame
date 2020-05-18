#pragma once
#include "GameObject.h"

class GameObject;
class Component abstract
{
	friend class GameObject;

public:
	GameObject* gameObject = nullptr;
	bool enabled = false;

public:
	Component();
	virtual ~Component();

private:
	virtual void Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;

};