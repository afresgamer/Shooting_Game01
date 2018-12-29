#include "GameManager.h"

void GameManager::Init()
{
	m_player = new Player();//プレイヤー初期化

	m_bullet = new Bullet();//弾初期化
	m_bullet->SetPos(m_player->x, m_player->y);//プレイヤーの弾位置設定

	m_back = new BACK();//背景初期化

	m_meteorite = new Meteorite[4];
	for (int i = 0; i < sizeof(m_meteorite); i++)
	{
		m_meteVec.push_back(m_meteorite[i]);
	}
	//爆発初期化
	m_explosion = new Explosion();
	m_explosion->timer = 0;
	//発射フラグ
	m_isBulletMove = false;
	//発射確認用変数
	m_isShot = false;
	//発射可能弾数
	m_bulletCount = 0;
	//スコア
	m_score = 0;
	//BGM再生
	PlaySoundFile("Resource/tw067.mp3",DX_PLAYTYPE_LOOP);
	//Button
	//button = new Button(200, 400, 300, 500, "Button");
	//button->Init();
	//当たり判定
	collision = new Collision();
}

void GameManager::Update()
{
	//Player更新処理
	m_player->Update();
	
	//弾発射
	if ((CheckHitKey(KEY_INPUT_SPACE) || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B)) && !m_isBulletMove) 
	{ m_isShot = true; }

	//背景
	//1枚目描画
	DrawGraph(m_back->x, m_back->y, m_back->gh, false);
	//二枚目描画
	DrawGraph(m_back->x, m_back->y - 1065, m_back->gh, false);
	//移動と移動判定
	m_back->y += SCROLL_SPEED;
	if (m_back->y >= 1065) { m_back->y = 0; }

	//playerの表示
	DrawRotaGraph(m_player->x, m_player->y, m_player->Scale, m_player->Angle, m_player->GHandle, false);

	if (m_isShot) { m_isBulletMove = true; m_bullet->Spawn_x = m_player->x; m_isShot = false; }

	//弾の動きと制御
	if (m_isBulletMove)
	{
		m_bullet->Spawn_y -= m_bullet->Speed;
		DrawRotaGraph(m_bullet->Spawn_x, m_bullet->Spawn_y - 20, m_bullet->scale, 0, m_bullet->B_Handle, false);

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
		m_meteVec[i].y += m_meteorite->speed;
		if (m_meteVec[i].y > 630)
		{
			m_meteVec[i].y = 0;
			m_meteVec[i].x = GetRand(480);
		}////衝突判定(PlayerとEnemy)
		else if (collision->IsCollision(m_meteVec[i].x, m_meteVec[i].y, m_meteVec[i].w, m_meteVec[i].h,
			m_player->x, m_player->y, m_player->w, m_player->h))
		{
			m_meteVec[i].y = 0;
			m_meteVec[i].x = GetRand(480);
		}////衝突判定(BulletとEnemy)
		else if (collision->IsCollision(m_meteVec[i].x, m_meteVec[i].y, m_meteVec[i].w, m_meteVec[i].h,
			m_bullet->Spawn_x, m_bullet->Spawn_y - 20, m_bullet->w, m_bullet->h))
		{
			m_meteVec[i].y = 0;
			m_meteVec[i].x = GetRand(480);
			m_score += 10;
			m_isBulletMove = false;
			m_bullet->Spawn_y = m_player->y - 40;
		}
	}

	//button->Draw();
	//button->Update();
	DrawFormatString(320, 0, RGB(255,0,0), "Score : %d", m_score); // 文字を描画する
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
