#include "DxLib.h"
#include "Test.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

static enum GameMode {
	Title,Main,Result
};


// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE); // ウィンドウモードに設定
	SetWindowSize(800, 600);// ウィンドウサイズを設定
	SetGraphMode(800, 600, 8);//画像解像度を設定
	//SetDrawScreen(DX_SCREEN_BACK);

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1) { return -1; }// エラーが起きたら直ちに終了
	
	Player* p = new Player();//プレイヤー初期化
	Bullet* b = new Bullet();//弾初期化
	
	while (ProcessMessage() == 0)
	{
		if (CheckHitKey(KEY_INPUT_ESCAPE)) { break; }	//終了処理
		ClearDrawScreen();	//ウィンドウの初期化

		//範囲制限
		if (p->x <= 20) { p->x = 20; }
		if (p->y <= 40) { p->y = 40; }
		if (p->x >= 800) { p->x = 800 - 40; }
		if (p->y >= 600) { p->y = 600 - 20; }

		//キー入力の確認
		if (CheckHitKey(KEY_INPUT_UP) || CheckHitKey(KEY_INPUT_W)) { p->y -= p->Speed / 2; p->Angle = 0; }
		if (CheckHitKey(KEY_INPUT_DOWN) || CheckHitKey(KEY_INPUT_S)) { p->y += p->Speed; p->Angle = 0; }
		if (CheckHitKey(KEY_INPUT_RIGHT) || CheckHitKey(KEY_INPUT_D)) { p->x += p->Speed; p->Angle = p->Plus_angle; }
		if (CheckHitKey(KEY_INPUT_LEFT) || CheckHitKey(KEY_INPUT_A)) { p->x -= p->Speed; p->Angle = -p->Plus_angle; }
		if (!CheckHitKeyAll()) { p->Angle = 0; }	//角度初期化
		

		//背景
		int bg = LoadGraph("Resource/lgi01a201412150700.jpg");
		DrawGraph(0, 0, bg, FALSE);

		//playerの表示
		int GHandle = LoadGraph("Resource/supercharged-rocket.png");
		DrawRotaGraph(p->x, p->y, p->Scale, p->Angle, GHandle, TRUE);
		
		//弾のキー入力の確認
		if (CheckHitKey(KEY_INPUT_SPACE))
		{
			//printfDx("Bullet");
			DrawGraph(b->Spawn_x, b->Spawn_y, b->B_Handle, TRUE);
		}

		ScreenFlip();//描画処理
	}

	DxLib_End();			// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了
}
