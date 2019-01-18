#include "TitleScene.h"

TitleScene::TitleScene()
{
	Init();
}

TitleScene::TitleScene(SceneParameter * sceneParam)
{
	Init();
	sceneP = sceneParam;
}

TitleScene::~TitleScene()
{
	Finalize();
}

void TitleScene::Init()
{
	back = new BACK();

	//Button
	button = new Button(200, 400, 300, 500, "Start");
	button->Init();
	button->SetbtnColor(GetColor(0, 255, 155));
	//BGMÄ¶
	PlaySoundFile("Resource/Space_Town_(Brand_New_Mix).mp3", DX_PLAYTYPE_LOOP);
}

void TitleScene::Update()
{
	DrawGraph(back->x, back->y, back->TBackImage, false);

	button->Draw(218,440);
	button->Update();
	if (button->IsPressed)
	{
		sceneP->SetSceneNum(SCENE_MAIN);
	}

	SetFontSize(TITLE_SIZE);
	DrawString(30, 150, "SHOOTING GAME", GetColor(255, 255, 0));
	SetFontSize(SCORE_SIZE);
}

void TitleScene::Finalize()
{
	delete this;
}
