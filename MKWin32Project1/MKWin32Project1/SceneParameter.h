#pragma once
#include "pch.h"

class SceneParameter
{
public:
	SceneParameter();
	~SceneParameter();
	void Init();
	//ƒV[ƒ“Ø‚è‘Ö‚¦getter setter
	int GetSceneNum();
	void SetSceneNum(int num);
	//BGMØ‚è‘Ö‚¦getter setter
	bool GetBGM();
	void SetBGM(bool change);
	//GameClear”»’ègetter setter
	bool GetClear();
	void SetClear(bool IsClear);
	int m_score = 0;
	bool IsInit = false;
	int Timer = 60;
private:
	int sceneNum = 0;
	bool isChangeBgm = false;
	bool isClear = false;
};

