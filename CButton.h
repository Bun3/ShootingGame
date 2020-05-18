#pragma once

class cTexture;
class CButton
{
private:	
	cTexture* m_Normal;
	cTexture* m_OnCursor;
	cTexture* m_OnClick;

	Vec2 m_Pos;
	RECT m_rt;

	bool bOnCursor;
	bool bOnClick;

public:
	CButton();
	CButton(const string& path, Vec2 pos);
	virtual ~CButton();

	bool Update();
	void Render();
	void Release();
};