#pragma once

#pragma comment (lib, "dsound.lib")

#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <vector>
#include <time.h>
#include <stdarg.h>
#include <string>
#include <string.h>
#include <functional>
#include "SDKsound.h"
#include "inc/fmod.hpp"

#pragma comment(lib,"fmod_vc.lib")

using namespace std;
using namespace FMOD;

#define g_Device DXUTGetD3D9Device()

#ifdef _DEBUG
#define DEBUG_LOG(log) cout << log << endl;
#define Print(log) cout << log << endl;
#else
#define DEBUG_LOG(log)
#define Print(log)
#endif // _DEBUG

#define PIE 3.141592f
#define RAD PIE / 180.0f
#define DEG 180.0f / PIE
#define VecOne Vec3(1, 1, 1)
#define VecZero Vec3(0, 0, 0)
#define VecForward Vec2(1, 0)
#define VecBackward Vec2(-1, 0)
#define VecUp Vec2(0, -1)
#define VecDown Vec2(0, 1)

using Vec2 = D3DXVECTOR2;
using Vec3 = D3DXVECTOR3;
using crString = const string &;

const int WINSIZEX = 1600;
const int WINSIZEY = 900;

const RECT WINRECT = { 0,0,WINSIZEX,WINSIZEY };
const Vec2 WINCENTER = { WINSIZEX / 2,WINSIZEY / 2 };

enum BulletType
{
	TYPE_NORMAL, TYPE_SPEAR
};

enum CollisionDetectedType
{
	COL_BOX2BOX, COL_CIRCLE2CIRCLE, COL_BOX2CIRCLE, COL_CIRCLE2BOX
};

enum OBJTAG
{
	TAG_PLAYER, TAG_ENEMY, TAG_PLAYERBULLET, TAG_ENEMYBULLET, TAG_ITEM
};

enum EFFECTTAG
{
	TAG_PLAYERFX, TAG_ENEMYFX
};

enum SoundType
{
	ST_BACKGROUND,
	ST_EFFECT
};

#include "cCameraManager.h"
#include "cSceneManager.h"
#include "cImageManager.h"
#include "cInputManager.h"
#include "cUtillManager.h"
#include "ObjectManager.h"
#include "EffectManager.h"
#include "SoundManager.h"
#include "TimeManager.h"

#include "cTexture.h"
#include "CSpriteRenderer.h"
#include "CTransform.h"
#include "CSound_.h"
#include "CCollider.h"
#include "CircleCollider.h"
#include "BoxCollider.h"

#include "CButton.h"
#include "GameObject.h"
#include "CEffect.h"
#include "CBullet.h"
#include "CNormalBullet.h"
#include "CDirectionBullet.h"
#include "CPetBullet.h"

#include "CPet.h"
#include "CAttackPet.h"
#include "CHealPet.h"

#include "CCharacter.h"

#include "CPlayerBullet.h"
#include "CPlayer.h"

#include "CItem.h"
#include "cPowerUpItem.h"
#include "cSpeedUpItem.h"
#include "cHealItem.h"

#include "CEnemy.h"
#include "Rush.h"
#include "SpeacialRush.h"
#include "CShootBullet.h"
#include "Shoot.h"
#include "CSpeacialShootBullet.h"
#include "SpeacialShoot.h"

