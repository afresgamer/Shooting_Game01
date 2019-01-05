#pragma once
#include "SceneParameter.h"
#include "BaseScene.h"
#include "BACK.h"
#include "Button.h"

class ResultScene : BaseScene
{
public:
	ResultScene();
	ResultScene(SceneParameter* sceneP);
	~ResultScene();
	void Init() override;
	void Update() override;
	void Finalize() override;
	void GameClear();
	void GameOver();

private:
	BACK * back;
	Button * button;
	SceneParameter* sceneParam;
};
