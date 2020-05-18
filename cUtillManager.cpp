#include "DXUT.h"
#include "cUtillManager.h"

bool cUtillManager::VecInRect(const RECT& _r, Vec2 v, float _radius)
{
	if (v.x + _radius >= _r.left && v.x - _radius <= _r.right
		&& v.y + _radius >= _r.top && v.y - _radius <= _r.bottom)
		return true;
	else
		return false;
}

float cUtillManager::VecLength(Vec2 vec)
{
	return sqrtf((vec.x * vec.x) + (vec.y * vec.y));
}

Vec2 cUtillManager::GetVectorNormalize(Vec2 vec)
{
	return vec / VecLength(vec);
}

Vec2 cUtillManager::GetNormalVector(float degree)
{
	Vec2 dir = Vec2(0, 1);
	D3DXMATRIX matRot;

	D3DXMatrixRotationZ(&matRot, D3DXToRadian(degree));
	D3DXVec2TransformNormal(&dir, &dir, &matRot);
	return dir;
}

bool Timer::CheckTime()
{
	if (isCheckTime)
	{
		result += TIME->DeltaTime();
		if (result >= timer)
			return true;
	}
	return false;
}
