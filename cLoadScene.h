#pragma once
#include "cScene.h"

class cLoadScene : 
	public cScene
{
private:
	string InGame = "./Resource/Image/InGame/";
	string InGameObject = "./Resource/Image/InGame/Object/";
	string InGameBackGround = "./Resource/Image/InGame/BackGround/";
	string Title = "./Resource/Image/Title/";
	string TitleButton = "./Resource/Image/Title/Button/";
	string TitleBackGround = "./Resource/Image/Title/BackGround/";

	int m_NowLoad;
	int m_MaxLoad;

	struct tagKYC
	{
		string key;
		string path;
		int cnt = 0;

		tagKYC(const string& key, const string& path, int cnt = 0)
			:key(key), path(path), cnt(cnt) {};
	};
	vector<tagKYC> m_Load;

	void Load(const string& key, const string& path, int cnt = 0)
	{
		m_Load.push_back(tagKYC(key, path + ".png", cnt));
	}

public:

	cLoadScene();
	virtual ~cLoadScene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};
