#pragma once
#include "cScene.h"
class cTitleScene 
	: public cScene
{
private:
	CButton* m_Credit;
	CButton* m_GameStart;
	CButton* m_Setting;

public:
	cTitleScene();
	virtual ~cTitleScene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};