#include "Test.h"
#include <vector>
#include <math.h>
using namespace std;

#define SCROLL_SPEED 2;

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE); // ウィンドウモードに設定
	SetWindowSize(480, 600);// ウィンドウサイズを設定
	SetGraphMode(480, 600, 8);//画像解像度を設定
	//SetDrawScreen(DX_SCREEN_BACK);

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1) { return -1; }// エラーが起きたら直ちに終了
	
	Player* p = new Player();//プレイヤー初期化
	Bullet* b = new Bullet();//弾初期化
	BACK* back = new BACK();//背景初期化
	//発射フラグ
	bool isBulletMove = false;
	//発射可能弾数
	int Bullet_count = 0;
	
	while (ProcessMessage() == 0)
	{
		if (CheckHitKey(KEY_INPUT_ESCAPE)) { break; }	//終了処理
		ClearDrawScreen();	//ウィンドウの初期化

		//範囲制限
		if (p->x <= 20) { p->x = 20; }
		if (p->y <= 40) { p->y = 40; }
		if (p->x >= 480) { p->x = 480 - 20; }
		if (p->y >= 600) { p->y = 600 - 20; }

		//キー入力の確認
		if (CheckHitKey(KEY_INPUT_UP) || CheckHitKey(KEY_INPUT_W)) { p->y -= p->Speed / 2; p->Angle = 0; }
		if (CheckHitKey(KEY_INPUT_DOWN) || CheckHitKey(KEY_INPUT_S)) { p->y += p->Speed; p->Angle = 0; }
		if (CheckHitKey(KEY_INPUT_RIGHT) || CheckHitKey(KEY_INPUT_D)) { p->x += p->Speed; p->Angle = p->Plus_angle; }
		if (CheckHitKey(KEY_INPUT_LEFT) || CheckHitKey(KEY_INPUT_A)) { p->x -= p->Speed; p->Angle = -p->Plus_angle; }
		if (!CheckHitKeyAll()) { p->Angle = 0; }	//角度初期化
		//弾発射
		if (CheckHitKey(KEY_INPUT_SPACE)) { isBulletMove = true; b->Spawn_x = p->x; }


		//背景
		//1枚目描画
		DrawGraph(back->x, back->y, back->gh, FALSE);
		//二枚目描画
		DrawGraph(back->x, back->y + 1065, back->gh, FALSE);
		//移動と移動判定
		back->y -= SCROLL_SPEED;
		if (back->y <= -1065) { back->y = 0; }
		
		//playerの表示
		int GHandle = LoadGraph("Resource/supercharged-rocket.png");
		DrawRotaGraph(p->x, p->y, p->Scale, p->Angle, GHandle, TRUE);
		
		//弾の動きと制御
		if (isBulletMove)
		{
			DrawRotaGraph(b->Spawn_x, b->Spawn_y - 20, b->scale, 0, b->B_Handle, TRUE);
			b->Spawn_y -= 2;
			if (b->Spawn_y <= 0.1f) {
				isBulletMove = false;
				b->Spawn_y = p->y - 10;
			}
		}

		ScreenFlip();//描画処理
	}

	DxLib_End();			// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了
}
