#include "DXUT.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider()
{
}

CircleCollider::CircleCollider(int diameter)
{
	radius = diameter / 2;
}

CircleCollider::~CircleCollider()
{
}

void CircleCollider::Update()
{
	m_ChangedPos = gameObject->transform->position + anchorPos;
	m_EllipseRect =
	{
		(LONG)m_ChangedPos.x - radius,
		(LONG)m_ChangedPos.y - radius,
		(LONG)m_ChangedPos.x + radius,
		(LONG)m_ChangedPos.y + radius
	};
}

void CircleCollider::Render()
{
	if (isDebug)
	{
		PAINTSTRUCT ps = { 0, };
		InvalidateRect(DXUTGetHWND(), NULL, false);
		HDC hdc = BeginPaint(DXUTGetHWND(), &ps);

		Ellipse(hdc, m_EllipseRect.left, m_EllipseRect.top, m_EllipseRect.right, m_EllipseRect.bottom);
		EndPaint(DXUTGetHWND(), &ps);
	}
}

void CircleCollider::Release()
{
}

void CircleCollider::SetColliderRange(int length)
{
	radius = length / 2;
	gameObject->collider = this;
}

bool CircleCollider::CheckCollider(BoxCollider* other)
{
	return 	UTILL->VecInRect(other->rect, (gameObject->transform->position + anchorPos), radius);
}

bool CircleCollider::CheckCollider(CircleCollider* other)
{
	return radius + other->radius
		>= UTILL->VecLength(UTILL->GetNewVec2(gameObject->transform->position + anchorPos, other->gameObject->transform->position + other->anchorPos)) ? true : false;
}
