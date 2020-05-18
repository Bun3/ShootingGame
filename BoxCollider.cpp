#include "DXUT.h"
#include "BoxCollider.h"

BoxCollider::BoxCollider()
{
}

BoxCollider::BoxCollider(cTexture* sprite)
{
	w = (int)sprite->info.Width / 2;
	h = (int)sprite->info.Height / 2;
}

BoxCollider::~BoxCollider()
{
}

void BoxCollider::Update()
{
	Vec2 colliderPos = gameObject->transform->position + anchorPos;
	rect =
	{
		(LONG)colliderPos.x - w,
		(LONG)colliderPos.y - h,
		(LONG)colliderPos.x + w,
		(LONG)colliderPos.y + h
	};
}

void BoxCollider::Render()
{
	if (isDebug)
	{
		PAINTSTRUCT ps = { 0, };
		InvalidateRect(DXUTGetHWND(), NULL, false);
		HDC hdc = BeginPaint(DXUTGetHWND(), &ps);
		Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
		EndPaint(DXUTGetHWND(), &ps);
	}
}

void BoxCollider::Release()
{
}

void BoxCollider::SetColliderRange(int width, int height)
{
	w = width / 2;
	h = height / 2;
	gameObject->collider = this;
}

bool BoxCollider::CheckCollider(BoxCollider* other)
{
	RECT tmp;
	return IntersectRect(&tmp, &rect, &other->rect);
}

bool BoxCollider::CheckCollider(CircleCollider* other)
{
	return UTILL->VecInRect(rect, (other->gameObject->transform->position + other->anchorPos), other->radius);
}
