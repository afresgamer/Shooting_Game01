#include "GameManager.h"

void GameManager::Init()
{

	m_player = new Player();//プレイヤー初期化
	GetGraphSize(m_player->GHandle, &m_player->w, &m_player->h);

	m_bullet = new Bullet();//弾初期化
	m_bullet->SetPos(m_player->x, m_player->y);//プレイヤーの弾位置設定
	GetGraphSize(m_bullet->B_Handle, &m_bullet->w, &m_bullet->h);

	m_back = new BACK();//背景初期化

	m_meteorite = new Meteorite[4];
	GetGraphSize(m_meteorite->m_G, &m_meteorite->w, &m_meteorite->h);
	for (int i = 0; i < sizeof(m_meteorite); i++)
	{
		m_meteVec.push_back(m_meteorite[i]);
	}
	//爆発初期化
	m_explosion = new Explosion();
	//発射フラグ
	m_isBulletMove = false;
	//発射確認用変数(0が打ってない 1が打っている)
	m_isShot = 0;
	//発射可能弾数
	m_bulletCount = 0;
	//スコア
	m_score = 0;

}

void GameManager::Update()
{
	//範囲制限
	if (m_player->x <= 20) { m_player->x = 20; }
	if (m_player->y <= 40) { m_player->y = 40; }
	if (m_player->x >= 480) { m_player->x = 480 - 20; }
	if (m_player->y >= 600) { m_player->y = 600 - 20; }

	//キー入力の確認
	if (CheckHitKey(KEY_INPUT_UP) || CheckHitKey(KEY_INPUT_W) || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_UP)) { m_player->y -= m_player->Speed / 2; m_player->Angle = 0; }
	if (CheckHitKey(KEY_INPUT_DOWN) || CheckHitKey(KEY_INPUT_S) || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_DOWN)) { m_player->y += m_player->Speed; m_player->Angle = 0; }
	if (CheckHitKey(KEY_INPUT_RIGHT) || CheckHitKey(KEY_INPUT_D) || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_RIGHT)) { m_player->x += m_player->Speed; m_player->Angle = m_player->Plus_angle; }
	if (CheckHitKey(KEY_INPUT_LEFT) || CheckHitKey(KEY_INPUT_A) || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_LEFT)) { m_player->x -= m_player->Speed; m_player->Angle = -m_player->Plus_angle; }
	//角度初期化
	if (!CheckHitKeyAll()) { m_player->Angle = 0; }
	//弾発射
	if ((CheckHitKey(KEY_INPUT_SPACE) || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B)) && !m_isBulletMove) { m_isShot = true; }

	//背景
	//1枚目描画
	DrawGraph(m_back->x, m_back->y, m_back->gh, false);
	//二枚目描画
	DrawGraph(m_back->x, m_back->y - 1065, m_back->gh, false);
	//移動と移動判定
	m_back->y += SCROLL_SPEED;
	if (m_back->y >= 1065) { m_back->y = 0; }

	//playerの表示
	m_player->y += GRAVITY;
	DrawRotaGraph(m_player->x, m_player->y, m_player->Scale, m_player->Angle, m_player->GHandle, true);

	if (m_isShot) { m_isBulletMove = true; m_bullet->Spawn_x = m_player->x; m_isShot = false; }

	//弾の動きと制御
	if (m_isBulletMove)
	{
		m_bullet->Spawn_y -= m_bullet->Speed;
		DrawRotaGraph(m_bullet->Spawn_x, m_bullet->Spawn_y - 20, m_bullet->scale, 0, m_bullet->B_Handle, true);

		if (m_bullet->Spawn_y <= 0)
		{
			m_isBulletMove = false;
			m_bullet->Spawn_y = m_player->y - 40;
		}
	}

	//敵の表示
	for (int i = 0; i < m_meteVec.size(); i++)
	{
		DrawRotaGraph(m_meteVec[i].x, m_meteVec[i].y, m_meteVec[i].scale, m_meteVec[i].angle, m_meteVec[i].m_G, true);
		m_meteVec[i].y += m_meteorite[i].speed;
		if (m_meteVec[i].y > 630)
		{
			m_meteVec[i].y = 0;
			m_meteVec[i].x = GetRand(480);
		}
	}
	////衝突判定
	//if (IsIntersect(p->x, p->y, p->w, p->h, meteorite->x, meteorite->y, meteorite->w, meteorite->h))
	//{
	//	printfDx("接触");
	//}

	//DrawFormatString(0, 0, GetColor(255, 255, 0), "SCORE : %d", score);

}

void GameManager::Finalize()
{
}

GameManager::GameManager()
{
	Init();
}

GameManager::~GameManager()
{
	Finalize();
}
