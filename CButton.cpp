#include "DXUT.h"
#include "CButton.h"

CButton::CButton()
{
}

CButton::CButton(const string& path, Vec2 pos)
{
	m_Pos = pos;

	m_Normal = IMAGE->FindImage(path + "Normal");
	m_OnCursor = IMAGE->FindImage(path + "OnCursor");
	m_OnClick = IMAGE->FindImage(path + "OnClick");

	SetRect(&m_rt,
		m_Pos.x - m_Normal->info.Width / 2,
		m_Pos.y - m_Normal->info.Height / 2,
		m_Pos.x + m_Normal->info.Width / 2,
		m_Pos.y + m_Normal->info.Height / 2);

	bOnClick = false;
	bOnCursor = false;
}

CButton::~CButton()
{
}

bool CButton::Update()
{
	if (bOnClick)
		if (INPUT->MouseLUp())
			return true;
	POINT pt;
	pt.x = INPUT->GetMousePos().x;
	pt.y = INPUT->GetMousePos().y;
	if (PtInRect(&m_rt, pt))
	{
		bOnCursor = true;
		if (INPUT->MouseLDown())
			bOnClick = true;
	}
	else
	{
		bOnCursor = false;
		bOnClick = false;
	}
	return false;
}

void CButton::Render()
{
	if (bOnClick)IMAGE->Render(m_OnClick, m_Pos, VecOne * 1.5f);
	else if (bOnCursor) IMAGE->Render(m_OnCursor, m_Pos, VecOne * 1.5f);
	else IMAGE->Render(m_Normal, m_Pos, VecOne * 1.5f);
}

void CButton::Release()
{
}
