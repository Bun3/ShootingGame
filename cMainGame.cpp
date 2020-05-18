#include "DXUT.h"
#include "cMainGame.h"

#include "cLoadScene.h"
#include "cTitleScene.h"
#include "cInGameScene.h"

cMainGame::cMainGame()
{
}


cMainGame::~cMainGame()
{
}

void cMainGame::Init()
{
	srand((unsigned)time(NULL));

	IMAGE->Init();
	CAMERA->Init();
	INPUT->Init();

	SCENE->AddScene("Load", new cLoadScene);
	SCENE->AddScene("Title", new cTitleScene);
	SCENE->AddScene("InGame", new cInGameScene);

	SCENE->ChangeScene("Load");
}

void cMainGame::Update()
{
	INPUT->Update();
	SCENE->Update();
	SOUND->Update();
	CAMERA->Update();
}

void cMainGame::Render()
{
	CAMERA->SetTramsform();

	IMAGE->Begin(false);

	SCENE->Render();

	IMAGE->End();
}

void cMainGame::Release()
{
	cCameraManager::ResetInstance();
	cImageManager::ResetInstance();
	cInputManager::ResetInstance();
	cSceneManager::ResetInstance();
	cUtillManager::ResetInstance();
	ObjectManager::ResetInstance();
	EffectManager::ResetInstance();
	SoundManager::ResetInstance();
	TimeManager::ResetInstance();
}

void cMainGame::ResetDevice()
{
	IMAGE->ResetDevice();
}

void cMainGame::LostDevice()
{
	IMAGE->LostDevice();
}