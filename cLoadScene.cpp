#include "DXUT.h"
#include "cLoadScene.h"

cLoadScene::cLoadScene()
{
}

cLoadScene::~cLoadScene()
{
}

void cLoadScene::Init()
{
	m_NowLoad = 0;

	//여기에 파일 로드
	//Ex) Load("key","파일경로",텍스쳐 장 수-1);

#pragma region Title

	Load("TitleBack", TitleBackGround + "back");

	Load("tCreditNormal", TitleButton + "/Credit/Normal");
	Load("tCreditOnCursor", TitleButton + "/Credit/OnCursor");
	Load("tCreditOnClick", TitleButton + "/Credit/OnClick");

	Load("tGameStartNormal", TitleButton + "/GameStart/Normal");
	Load("tGameStartOnCursor", TitleButton + "/GameStart/OnCursor");
	Load("tGameStartOnClick", TitleButton + "/GameStart/OnClick");

	Load("tSettingNormal", TitleButton + "/Setting/Normal");
	Load("tSettingOnCursor", TitleButton + "/Setting/OnCursor");
	Load("tSettingOnClick", TitleButton + "/Setting/OnClick");

#pragma endregion

#pragma region InGame

	Load("InGameFar", InGameBackGround + "Background_FarView");
	Load("InGameNear", InGameBackGround + "Background_NearView");
	Load("InGameMiddle", InGameBackGround + "Background_MiddleView");

	Load("PlayerIdle",	InGameObject + "Player/Idle/_%d", 3);
	Load("PlayerMaxHit",	InGameObject + "Player/MaxHit/_%d", 6);
	Load("PlayerBackMove", InGameObject + "Player/BackMove/_%d", 3);
	Load("PlayerMaxShoot",	InGameObject + "Player/MaxShoot/_%d", 3);
	Load("PlayerCharging",	InGameObject + "Player/Charging/_%d", 5);
	Load("PlayerMaxBullet", InGameObject + "Player/MaxBullet/_%d", 2);
	Load("PlayerNormalHit", InGameObject + "Player/NormalHit/_%d", 7);
	Load("PlayerBullet",	InGameObject + "Player/NormalBullet/_%d", 2);

	Load("RushHit", InGameObject + "Rush/Hit/_%d", 6);
	Load("RushIdle",	InGameObject + "Rush/Idle/_%d", 2);
	Load("SRushIdle", InGameObject + "SpeacialRush/Idle/_%d", 2);

	Load("ShootDie", InGameObject + "Shoot/Die/_%d", 6);
	Load("ShootHit", InGameObject + "Shoot/Hit/_%d", 6);
	Load("ShootIdle",	InGameObject + "Shoot/Idle/_%d", 3);
	Load("ShootBullet", InGameObject + "Shoot/Bullet/_%d", 2);
	Load("SShootDie", InGameObject + "SpeacialShoot/Die/_%d", 6);
	Load("SShootHit", InGameObject + "SpeacialShoot/Hit/_%d", 6);
	Load("SShootIdle", InGameObject + "SpeacialShoot/Idle/_%d", 3);
	Load("SShootBullet", InGameObject + "SpeacialShoot/Bullet/_%d", 2);

	Load("PetHealEffect", InGameObject + "Pet/Heal/Effect/_%d", 3);
	Load("HealPetIdle", InGameObject + "Pet/Heal/_%d", 3);
	Load("AttackPetIdle", InGameObject + "Pet/Attack/_%d", 3);
	Load("PetCreate", InGameObject + "Pet/CreateEffect/_%d", 4);
	Load("PetBullet", InGameObject + "Pet/Attack/Bullet");

	Load("PowerUpItem", InGameObject + "Item/PowerUpIcon");
	Load("SpeedUpItem", InGameObject + "Item/SpeedUpIcon");
	Load("HealItem", InGameObject + "Item/HealIcon");

	Load("HpOn", InGame + "UI/HpOn");
	Load("HpOff", InGame + "UI/HpOff");

	SOUND->AddSound("AbillityUp", "Item/AbillityUp.wav", SoundType::ST_EFFECT);
	SOUND->AddSound("MaxBullet", "Player/MaxBullet.mp3", SoundType::ST_EFFECT);
	SOUND->AddSound("Bullet", "Player/Bullet.mp3", SoundType::ST_EFFECT);
	SOUND->AddSound("Charge", "Player/Charge.mp3", SoundType::ST_EFFECT);
	SOUND->AddSound("BulletHit", "BulletHit.wav", SoundType::ST_EFFECT);
	SOUND->AddSound("PetCreate", "PetCreate.wav", SoundType::ST_EFFECT);
	SOUND->AddSound("MonsterShoot", "Monster.wav", SoundType::ST_EFFECT);
	SOUND->AddSound("RushDie", "RushDie.wav", SoundType::ST_EFFECT);
	SOUND->AddSound("RushDie", "ShootDie.wav", SoundType::ST_EFFECT);

#pragma endregion

	m_MaxLoad = m_Load.size();
}

void cLoadScene::Update()
{
	if (m_NowLoad != m_MaxLoad)
	{
		IMAGE->AddImage(
			m_Load[m_NowLoad].key,
			m_Load[m_NowLoad].path,
			m_Load[m_NowLoad].cnt);
		m_NowLoad++;
	}
	else
		SCENE->ChangeScene("Title");
}

void cLoadScene::Render()
{
}

void cLoadScene::Release()
{
}