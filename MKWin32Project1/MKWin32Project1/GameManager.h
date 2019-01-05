#pragma once
#include "pch.h"
#include "MainScene.h"
#include "TitleScene.h"
#include "ResultScene.h"
#include "SceneParameter.h"

class GameManager
{
public:
	GameManager();
	~GameManager();
	void Init();
	void Start();
	void Update();
	void Finalize();
	SceneParameter* sceneParam;
	TitleScene* titleScene;
	MainScene* mainScene;
	ResultScene* resultScene;
};
