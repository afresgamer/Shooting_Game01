#include "Test.h"
#include <vector>

#define SCROLL_SPEED 2;
#define GRAVITY 2;

//弾の位置を決定
void Bullet::SetPos(int x, int y)
{
	Spawn_x = x;
	Spawn_y = y;
}

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
	Bullet* p_b = new Bullet();//弾初期化
	p_b->SetPos(p->x, p->y);//プレイヤーの弾位置設定
	BACK* back = new BACK();//背景初期化
	Meteorite* meteorite = new Meteorite[4];
	vector<Meteorite> meteVec;
	for (int i = 0; i < sizeof(meteorite); i++)
	{
		meteVec.push_back(meteorite[i]);
	}
	//発射フラグ
	bool isBulletMove = false;
	//発射確認用変数(0が打ってない 1が打っている)
	int isShot = 0;
	//発射可能弾数
	int Bullet_count = 0;

	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();	//ウィンドウの初期化

		//範囲制限
		if (p->x <= 20) { p->x = 20; }
		if (p->y <= 40) { p->y = 40; }
		if (p->x >= 480) { p->x = 480 - 20; }
		if (p->y >= 600) { p->y = 600 - 20; }

		//キー入力の確認
		if (CheckHitKey(KEY_INPUT_UP) || CheckHitKey(KEY_INPUT_W) || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_UP)) { p->y -= p->Speed / 2; p->Angle = 0; }
		if (CheckHitKey(KEY_INPUT_DOWN) || CheckHitKey(KEY_INPUT_S) || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_DOWN)) { p->y += p->Speed; p->Angle = 0; }
		if (CheckHitKey(KEY_INPUT_RIGHT) || CheckHitKey(KEY_INPUT_D) || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_RIGHT)) { p->x += p->Speed; p->Angle = p->Plus_angle; }
		if (CheckHitKey(KEY_INPUT_LEFT) || CheckHitKey(KEY_INPUT_A) || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_LEFT)) { p->x -= p->Speed; p->Angle = -p->Plus_angle; }
		//角度初期化
		if (!CheckHitKeyAll()) { p->Angle = 0; }
		//弾発射
		if (CheckHitKey(KEY_INPUT_SPACE) || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B) && !isBulletMove) { isShot = 1; }

		//背景
		//1枚目描画
		DrawGraph(back->x, back->y, back->gh, FALSE);
		//二枚目描画
		DrawGraph(back->x, back->y - 1065, back->gh, FALSE);
		//移動と移動判定
		back->y += SCROLL_SPEED;
		if (back->y >= 1065) { back->y = 0; }

		//playerの表示
		p->y += GRAVITY;
		DrawRotaGraph(p->x, p->y, p->Scale, p->Angle, p->GHandle, TRUE);

		if (isShot == 1) { isBulletMove = true; p_b->Spawn_x = p->x; isShot = 0; }

		//弾の動きと制御
		if (isBulletMove)
		{
			p_b->Spawn_y -= p_b->Speed;
			DrawRotaGraph(p_b->Spawn_x, p_b->Spawn_y - 20, p_b->scale, 0, p_b->B_Handle, TRUE);
			if (p_b->Spawn_y <= 0)
			{
				isBulletMove = false;
				p_b->Spawn_y = p->y - 40;
			}
		}

		//敵の表示
		for (int i = 0; i < meteVec.size(); i++)
		{
			DrawRotaGraph(meteVec[i].x,meteVec[i].y,meteVec[i].scale,meteVec[i].angle,meteVec[i].m_G,TRUE);
			meteVec[i].y += meteorite[i].speed;
			if (meteVec[i].y > 630)
			{ 
				meteVec[i].y = 0;
				meteVec[i].x = GetRand(480);
			}
		}
		if (CheckHitKey(KEY_INPUT_ESCAPE)) { break; }	//終了処理

		ScreenFlip();//描画処理
	}

	DxLib_End();			// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了
}
