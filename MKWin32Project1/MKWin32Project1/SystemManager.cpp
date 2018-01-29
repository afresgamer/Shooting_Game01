#include "SystemManager.h"

SystemManager::SystemManager()
{
	Init();
}

SystemManager::~SystemManager()
{
	Finalize();
}


bool SystemManager::Init()
{
	ChangeWindowMode(true); // ウィンドウモードに設定
	SetWindowSize(480, 600);// ウィンドウサイズを設定
	SetGraphMode(480, 600, 8);//画像解像度を設定
	SetFontSize(SCORE_SIZE);//文字サイズ
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE);//文字の端のライン表示
												  // ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1) { return false; }// エラーが起きたら直ちに終了

	m_gameMgr = new GameManager();
	return true;
}

void SystemManager::Update()
{
	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();	//ウィンドウの初期化
		m_gameMgr->Update(); // ゲームロジックの更新

		if (CheckHitKey(KEY_INPUT_ESCAPE)) { break; }	//終了処理
		ScreenFlip();//描画処理
	}
}

void SystemManager::Finalize()
{
	DxLib_End();			// ＤＸライブラリ使用の終了処理
}
