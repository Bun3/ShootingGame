#pragma once
#include "CPet.h"

class CAttackPet :
	public CPet
{
private:
	Timer m_bulletTimer;
public:
	CAttackPet();
	virtual ~CAttackPet();

	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

