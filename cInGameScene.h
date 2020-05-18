#pragma once
#include "cScene.h"

struct Scroll
{
private:
	cTexture* m_BackSprite;
	Vec2 m_Pos[2];
	int m_ScrollSpeed;
	int rimit;
	int origin;

public:
	Scroll() {};
	Scroll(cTexture* sprite, int speed)
		:m_BackSprite(sprite)
	{
		m_Pos[0] = Vec2(m_BackSprite->info.Width / 2, WINSIZEY / 2);
		m_Pos[1] = Vec2((int)m_BackSprite->info.Width * 1.5, WINSIZEY / 2);
		m_ScrollSpeed = speed;
		rimit = -(int)m_BackSprite->info.Width / 2;
		origin = m_BackSprite->info.Width * 1.5;
	};
	void Update();
	void Render();
	void Release();
};

class cInGameScene :
	public cScene
{
private:
	Scroll m_Far;
	Scroll m_Middle;
	Scroll m_Near;

	//cPlayer* player;
	//cShoot* shoot;
	Timer shootDispenser;
	Timer rushDispenser;

	cTexture* m_Hps[3];

public:
	cInGameScene();
	virtual ~cInGameScene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

};