#pragma once
#include "SceneParameter.h"
#include "BaseScene.h"
#include "BACK.h"
#include "Button.h"

class TitleScene : BaseScene
{
public:
	TitleScene();
	TitleScene(SceneParameter* sceneParam);
	~TitleScene();
	void Init() override;
	void Update() override;
	void Finalize() override;
private:
	BACK* back;
	Button* button;
	SceneParameter* sceneP;
};
