#pragma once
#include "Component.h"

class CTransform
	: public Component
{
public:
	Vec2 position = Vec2(0, 0);
	Vec3 scale = Vec3(1, 1, 1);
	float rotation = 0;

public:
	CTransform();
	CTransform(Vec2 p, Vec3 s = VecOne, float r = 0);
	virtual ~CTransform();

public:
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	void Translate(Vec2 translation);
	void Rotate(Vec2 direction, int textureBaseRotation = 0);
	void Rotate(float degree);
	Vec2 GetRotatedDirectionVector(float Degree);
};