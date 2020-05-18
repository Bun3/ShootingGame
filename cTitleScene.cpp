#include "DXUT.h"
#include "cTitleScene.h"


cTitleScene::cTitleScene()
{
}


cTitleScene::~cTitleScene()
{
}

void cTitleScene::Init()
{
	m_GameStart = new CButton("tGameStart", Vec2(WINCENTER.x + 300, WINCENTER.y));
}

void cTitleScene::Update()
{
	if (m_GameStart->Update())
		SCENE->ChangeScene("InGame");
}

void cTitleScene::Render()
{
	IMAGE->Render(IMAGE->FindImage("TitleBack"), WINCENTER);
	m_GameStart->Render();
}

void cTitleScene::Release()
{
	m_GameStart->Release();
	SAFE_DELETE(m_GameStart);
}
