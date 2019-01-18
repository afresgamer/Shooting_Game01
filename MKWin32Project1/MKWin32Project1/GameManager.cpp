#include "GameManager.h"

void GameManager::Init()
{
	sceneParam = new SceneParameter();
	titleScene = new TitleScene(sceneParam); 
	mainScene = new MainScene(sceneParam);
	resultScene = new ResultScene(sceneParam);
	sceneParam->IsInit = true;
}

void GameManager::Start()
{
	titleScene->Init();
	mainScene->Init();
	resultScene->Init();
	sceneParam->IsInit = true;
}

void GameManager::Update()
{
	if (!sceneParam->IsInit) { Start(); }

	switch (sceneParam->GetSceneNum())
	{
	case SCENE_TITLE:
		titleScene->Update();
		break;
	case SCENE_MAIN:
		mainScene->Update();
		break;
	case SCENE_RESULT:
		resultScene->Update();
	default:
		break;
	}
}

void GameManager::Finalize()
{
	delete this;
}


GameManager::GameManager()
{
	Init();
}

GameManager::~GameManager()
{
	Finalize();
}
