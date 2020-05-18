#include "DXUT.h"
#include "CEnemy.h"

CEnemy::CEnemy()
{
	collisionCheckList = new OBJTAG[2]{ OBJTAG::TAG_PLAYER,OBJTAG::TAG_PLAYERBULLET };
}

CEnemy::~CEnemy()
{
}

void CEnemy::ItemDrop()
{
	func[0] = std::bind(&CEnemy::HItem, this);
	func[1] = std::bind(&CEnemy::SItem, this);
	func[2] = std::bind(&CEnemy::PItem, this);
	if (OBJECT->GETPLAYER()->ItemDrop(10))
	{
		Print("¿Í ¾ÆÀÌÅÛ!");
		//¾ÆÀÌÅÛ ¶³±¸±â
		func[rand() % 3]();
	}
}

void CEnemy::HItem()
{
	Print("H");
	OBJECT->AddObj(new cHealItem(transform->position), "cHealItem", OBJTAG::TAG_ITEM);
}

void CEnemy::SItem()
{
	Print("S");
	OBJECT->AddObj(new cSpeedUpItem(transform->position), "SpeedUpItem", OBJTAG::TAG_ITEM);
}

void CEnemy::PItem()
{
	Print("P");
	OBJECT->AddObj(new cPowerUpItem(transform->position), "PowerUpItem", OBJTAG::TAG_ITEM);
}

void CEnemy::PetCreate()
{
	if (OBJECT->GETPLAYER()->PetAcquisition(100))
	{
		Print("¿Í ±Í¿©¿î Æê!");

		if (OBJECT->GETPLAYER()->attackPet != nullptr && OBJECT->GETPLAYER()->healPet != nullptr)
		{
			Print("²Ë Ã¡´ç...");
			return;
		}

		if (OBJECT->GETPLAYER()->attackPet == nullptr && OBJECT->GETPLAYER()->healPet == nullptr)
		{
			if (rand() % 2)
				EFFECT->PlayEffect(new CEffect(EFFECTTAG::TAG_PLAYERFX, IMAGE->FindImage("PetCreate"),
					Vec2(OBJECT->GETPLAYER()->transform->position.x, OBJECT->GETPLAYER()->transform->position.y + 100),
					4, 40, VecOne))->IsEnd(std::bind(&CEnemy::HealCreate, this));
			else
				EFFECT->PlayEffect(new CEffect(EFFECTTAG::TAG_PLAYERFX, IMAGE->FindImage("PetCreate"),
					Vec2(OBJECT->GETPLAYER()->transform->position.x, OBJECT->GETPLAYER()->transform->position.y - 100),
					4, 40, VecOne))->IsEnd(std::bind(&CEnemy::AttackCreate, this));
		}
		else if (OBJECT->GETPLAYER()->attackPet != nullptr)
		{
			EFFECT->PlayEffect(new CEffect(EFFECTTAG::TAG_PLAYERFX, IMAGE->FindImage("PetCreate"),
				Vec2(OBJECT->GETPLAYER()->transform->position.x, OBJECT->GETPLAYER()->transform->position.y + 100),
				4, 40, VecOne))->IsEnd(std::bind(&CEnemy::HealCreate, this));
		}
		else if (OBJECT->GETPLAYER()->healPet != nullptr)
		{
			EFFECT->PlayEffect(new CEffect(EFFECTTAG::TAG_PLAYERFX, IMAGE->FindImage("PetCreate"),
				Vec2(OBJECT->GETPLAYER()->transform->position.x, OBJECT->GETPLAYER()->transform->position.y - 100),
				4, 40, VecOne))->IsEnd(std::bind(&CEnemy::AttackCreate, this));
		}
	}
}

void CEnemy::AttackCreate()
{
	OBJECT->GETPLAYER()->attackPet = new CAttackPet();
}

void CEnemy::HealCreate()
{
	OBJECT->GETPLAYER()->healPet = new CHealPet();
}
