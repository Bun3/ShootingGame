#pragma once
#include "singleton.h"
class cTexture;

class cImageManager : public singleton<cImageManager>
{
private:
	LPD3DXSPRITE m_sprite;
	map<string, cTexture *> m_image;
	LPD3DXFONT font;
public:
	cImageManager();
	virtual ~cImageManager();

	void Begin(bool Ui);
	void End();
	void ReBegin(bool Ui) { End(); Begin(Ui); }

	void Init();
	void Release();

	void ResetDevice();
	void LostDevice();

public:
	cTexture * AddImage(const string& key, const string& path, int count = 0);
	cTexture * FindImage(const string& key, int count = -1);

	void PrintText(const string& str, Vec2 pos, float size, D3DCOLOR color, bool center = false);

	void Render(cTexture* texture, Vec2 pos, Vec3 size = VecOne, float rot = 0, bool center = true, D3DCOLOR color = D3DCOLOR_ARGB(255, 255, 255, 255));
};

#define IMAGE cImageManager::GetInstance()