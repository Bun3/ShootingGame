#include "DXUT.h"
#include "cInGameScene.h"

cInGameScene::cInGameScene()
{
}

cInGameScene::~cInGameScene()
{
}

void cInGameScene::Init()
{
	m_Near = Scroll(IMAGE->FindImage("InGameNear"), 12);
	m_Middle = Scroll(IMAGE->FindImage("InGameMiddle"), 8);
	m_Far = Scroll(IMAGE->FindImage("InGameFar"), 2); 
	OBJECT->SETPLAYER((CPlayer*)OBJECT->AddObj(new CPlayer, "Player", OBJTAG::TAG_PLAYER));
	EFFECT->SetTransparent(255);
	rushDispenser.SetTimer(2);
	shootDispenser.SetTimer(4);
	rushDispenser.StartTimer();
	shootDispenser.StartTimer();
}

void cInGameScene::Update()
{
	m_Far.Update();
	m_Middle.Update();
	m_Near.Update();
	if (rushDispenser.CheckTime())
	{
		rushDispenser.ResetTimer();
		if (rand() % 2)
			OBJECT->AddObj(new Rush(Vec2(1700, rand() % WINSIZEY)), "Rush", OBJTAG::TAG_ENEMY);
		else 
			OBJECT->AddObj(new SpeacialRush(Vec2(1700, rand() % WINSIZEY)), "SRush", OBJTAG::TAG_ENEMY);
	}
	if (shootDispenser.CheckTime())
	{
		shootDispenser.ResetTimer();
		if (rand() % 2)
			OBJECT->AddObj(new Shoot(10), "Shoot", OBJTAG::TAG_ENEMY);
		else
			OBJECT->AddObj(new SpeacialShoot(10), "ASD", OBJTAG::TAG_ENEMY);
	}

	OBJECT->Update();
	EFFECT->Update();
}

void cInGameScene::Render()
{
	m_Far.Render();
	m_Middle.Render();
	OBJECT->Render();
	EFFECT->Render();
	m_Near.Render();

	for (int i = 0; i < 3; i++)
	{
		m_Hps[i] = OBJECT->GETPLAYER()->m_hp >= i + 1 ? IMAGE->FindImage("HpOn") : IMAGE->FindImage("HpOff");
		IMAGE->Render(m_Hps[i], Vec2(80 + i * 150, 60), VecOne * 0.8f);
	}
}

void cInGameScene::Release()
{
	EFFECT->Release();
	OBJECT->Release();
	m_Far.Release();
	m_Near.Release();
	m_Middle.Release();
}

void Scroll::Update()
{
	for (int i = 0; i < 2; i++)
	{
		if (m_Pos[i].x <= rimit)
			m_Pos[i].x = origin;

		m_Pos[i].x -= (int)(m_ScrollSpeed);
	}
}

void Scroll::Render()
{
	for (int i = 0; i < 2; i++)
	{
		IMAGE->Render(m_BackSprite, m_Pos[i]);
	}
}

void Scroll::Release()
{
}
