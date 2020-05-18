#include "DXUT.h"
#include "CTransform.h"

CTransform::CTransform()
{
}

CTransform::CTransform(Vec2 p, Vec3 s, float r)
{
	position = p;
	rotation = r;
	scale = s;
}

CTransform::~CTransform()
{
}

void CTransform::Update()
{
}

void CTransform::Render()
{
}

void CTransform::Release()
{
}

void CTransform::Translate(Vec2 translation)
{
	position.x += translation.x * TIME->DeltaTime();
	position.y += translation.y * TIME->DeltaTime();
}

void CTransform::Rotate(Vec2 direction, int textureBaseRotation)
{
	if (textureBaseRotation >= 360)
		textureBaseRotation -= 360 * (textureBaseRotation / 360);
	if (textureBaseRotation < 0)
		textureBaseRotation = 360 * (abs(textureBaseRotation) / 360) + textureBaseRotation;
	gameObject->transform->rotation = atan2f(direction.y, direction.x) * DEG + textureBaseRotation - 90;
}

void CTransform::Rotate(float degree)
{
	D3DXMATRIX matRot;

	D3DXMatrixRotationZ(&matRot, D3DXToRadian(degree));
	D3DXVec2TransformNormal(&gameObject->normalizeVector, &gameObject->normalizeVector, &matRot);
}

Vec2 CTransform::GetRotatedDirectionVector(float Degree)
{
	Vec2  Dir = Vec2(0.f, 1.f);
	D3DXMATRIX  matRot;

	D3DXMatrixRotationZ(&matRot, D3DXToRadian(Degree));
	D3DXVec2TransformNormal(&Dir, &Dir, &matRot);

	return Dir;
}
