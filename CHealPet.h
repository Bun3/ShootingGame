#pragma once
#include "CPet.h"

class CHealPet : 
	public CPet
{
	Timer m_healTimer;
	bool isAlreadyHeal;
public:
	CHealPet();
	virtual ~CHealPet();

	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	void Heal();
};

