#include "SceneParameter.h"

SceneParameter::SceneParameter()
{
	Init();
}

SceneParameter::~SceneParameter()
{
	delete this;
}

void SceneParameter::Init()
{
	sceneNum = 0;
	m_score = 0;
	isChangeBgm = false;
	IsInit = false;
	Timer = 60;
	isClear = false;
}

int SceneParameter::GetSceneNum()
{
	return sceneNum;
}

void SceneParameter::SetSceneNum(int num)
{
	sceneNum = num;
}

bool SceneParameter::GetBGM()
{
	return isChangeBgm;
}

void SceneParameter::SetBGM(bool change)
{
	isChangeBgm = change;
}

bool SceneParameter::GetClear()
{
	return isClear;
}

void SceneParameter::SetClear(bool IsClear)
{
	isClear = IsClear;
}


