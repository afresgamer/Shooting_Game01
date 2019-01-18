#include "ResultScene.h"

ResultScene::ResultScene()
{
	Init();
}

ResultScene::ResultScene(SceneParameter * sceneP)
{
	Init();
	sceneParam = sceneP;
}

ResultScene::~ResultScene()
{
	Finalize();
}

void ResultScene::Init()
{
	back = new BACK();
	button = new Button(130, 450, 330, 500, "TO TITLE");
	button->Init();
	button->SetbtnColor(GetColor(0, 255, 0));
	button->SetTextColor(GetColor(255, 0, 0));
}

void ResultScene::Update()
{
	if (sceneParam->GetClear())
	{
		GameClear();
	}
	else if(!sceneParam->GetClear())
	{
		GameOver();
	}
}

void ResultScene::GameClear()
{
	if (sceneParam->GetBGM()) {
		StopSoundFile();
		PlaySoundFile("Resource/Across_-Battle_Results-.mp3", DX_PLAYTYPE_LOOP);
		sceneParam->SetBGM(false);
	}

	DrawGraph(back->x, back->y, back->RBackImage, false);

	button->Draw(170, 465);
	button->Update();
	if (button->IsPressed)
	{
		sceneParam->SetSceneNum(SCENE_TITLE);
		//‰Šú‰»ˆ—
		sceneParam->Init();
	}
	SetFontSize(RESULT_SIZE);
	DrawString(120, 80, "Result", GetColor(255, 255, 0));
	SetFontSize(SCORE_SIZE * 2);
	DrawString(120, 200, "GAME CLEAR", GetColor(200, 0, 200));
	DrawFormatString(120, 300, GetColor(0, 0, 200), "Score: %d", sceneParam->m_score);
	SetFontSize(SCORE_SIZE);
}

void ResultScene::GameOver()
{
	if (sceneParam->GetBGM()) {
		StopSoundFile();
<<<<<<< HEAD
		PlaySoundFile("Resource/gameover.mp3", DX_PLAYTYPE_LOOP);
=======
		PlaySoundFile("Resource/‚³‚ª‚µ‚à‚Ì.mp3", DX_PLAYTYPE_LOOP);
>>>>>>> fc5c319ea7b759d123fa00c9326963419b316632
		sceneParam->SetBGM(false);
	}

	DrawGraph(back->x, back->y, back->RBackImage, false);

	button->Draw(170, 465);
	button->Update();
	if (button->IsPressed)
	{
		sceneParam->SetSceneNum(SCENE_TITLE);
		//‰Šú‰»ˆ—
		sceneParam->Init();
	}
	SetFontSize(RESULT_SIZE);
	DrawString(120, 80, "Result", GetColor(255, 255, 0));
	SetFontSize(SCORE_SIZE * 2);
	DrawString(120, 200, "GAME OVER", GetColor(200, 0, 200));
	DrawFormatString(120, 300, GetColor(0, 0, 200), "Score: %d", sceneParam->m_score);
	SetFontSize(SCORE_SIZE);
}

void ResultScene::Finalize()
{
	delete this;
}
