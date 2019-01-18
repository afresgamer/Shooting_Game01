#include "MainScene.h"

MainScene::MainScene()
{
	Init();
}

MainScene::MainScene(SceneParameter * sceneP)
{
	Init();
	sceneParam = sceneP;
}

MainScene::~MainScene()
{
	Finalize();
}

void MainScene::Init()
{
	m_player = new Player();//ƒvƒŒƒCƒ„[‰Šú‰»

	m_bullet = new Bullet();//’e‰Šú‰»
	m_bullet->SetPos(m_player->x, m_player->y);//ƒvƒŒƒCƒ„[‚Ì’eˆÊ’uİ’è

	m_back = new BACK();//”wŒi‰Šú‰»

	m_meteorite = new Meteorite[4];
	for (int i = 0; i < sizeof(m_meteorite); i++)
	{
		m_meteVec.push_back(m_meteorite[i]);
	}
	//”š”­‰Šú‰»
	m_explosion = new Explosion();
	m_explosion->timer = 0;
	m_explosion->isCreate = false;
	//”­Ëƒtƒ‰ƒO
	m_isBulletMove = false;
	//”­ËŠm”F—p•Ï”
	m_isShot = false;
	//”­Ë‰Â”\’e”
	m_bulletCount = 0;
	//“–‚½‚è”»’è
	collision = new Collision();
}

void MainScene::Update()
{
	//PlayerXVˆ—
	m_player->Update();
	//”wŒi
	//1–‡–Ú•`‰æ
	DrawGraph(m_back->x, m_back->y, m_back->MBackImage, false);
	//“ñ–‡–Ú•`‰æ
	DrawGraph(m_back->x, m_back->y - 1065, m_back->MBackImage, false);
	//ˆÚ“®‚ÆˆÚ“®”»’è
	m_back->y += SCROLL_SPEED;
	if (m_back->y >= 1065) { m_back->y = 0; }

	//player‚Ì•\¦
	DrawRotaGraph(m_player->x, m_player->y, m_player->Scale, m_player->Angle, m_player->GHandle, true);

	//’e”­Ë
	if ((CheckHitKey(KEY_INPUT_SPACE) || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B)) && !m_isBulletMove)
	{
		m_isShot = true;
	}

	if (m_isShot) { m_isBulletMove = true; m_bullet->Spawn_x = m_player->x; m_isShot = false; }
	//’e‚Ì“®‚«‚Æ§Œä
	if (m_isBulletMove)
	{
		m_bullet->Spawn_y -= m_bullet->Speed;
		DrawRotaGraph(m_bullet->Spawn_x, m_bullet->Spawn_y - 20, m_bullet->scale, 0, m_bullet->B_Handle, true);
		PlaySoundMem(ShotSE, DX_PLAYTYPE_BACK);
		if (m_bullet->Spawn_y <= 0)
		{
			m_isBulletMove = false;
			m_bullet->Spawn_y = m_player->y + 40;
		}
	}

	//“G‚Ì•\¦
	for (int i = 0; i < m_meteVec.size(); i++)
	{
		DrawRotaGraph(m_meteVec[i].x, m_meteVec[i].y, m_meteVec[i].scale, m_meteVec[i].angle, m_meteVec[i].m_G, true);
		m_meteVec[i].y += m_meteorite->speed;
		if (m_meteVec[i].y > 630)
		{
			m_meteVec[i].y = 0;
			m_meteVec[i].x = GetRand(480);
		}////Õ“Ë”»’è(Player‚ÆEnemy)
		else if (collision->IsCollision(m_meteVec[i].x, m_meteVec[i].y, m_meteVec[i].w, m_meteVec[i].h,
			m_player->x, m_player->y, m_player->w, m_player->h))
		{
			m_meteVec[i].y = 0;
			m_meteVec[i].x = GetRand(480);
			m_player->Health--;

		}////Õ“Ë”»’è(Bullet‚ÆEnemy)
		else if (collision->IsCollision(m_meteVec[i].x, m_meteVec[i].y, m_meteVec[i].w, m_meteVec[i].h,
			m_bullet->Spawn_x, m_bullet->Spawn_y - 20, m_bullet->w, m_bullet->h))
		{
			//effectˆ—
			m_explosion->x = m_meteVec[i].x;
			m_explosion->y = m_meteVec[i].y;
			m_explosion->isCreate = true;

			m_meteVec[i].y = 0;
			m_meteVec[i].x = GetRand(480);
			sceneParam->m_score += 10;
			m_isBulletMove = false;
			m_bullet->Spawn_y = m_player->y + 40;
		}
	}
	//BGMØ‚è‘Ö‚¦
	if (!sceneParam->GetBGM()) {
		StopSoundFile();
		PlaySoundFile("Resource/tw067.mp3", DX_PLAYTYPE_LOOP);
		sceneParam->SetBGM(true);
	}
	//Effect•`‰æ‚·‚é
	if (m_explosion->isCreate) {
		m_explosion->timer++;
		m_explosion->Draw(m_explosion->timer);
		PlaySoundMem(ExploSE, DX_PLAYTYPE_BACK);
		if (m_explosion->timer > 10)
		{
			m_explosion->isCreate = false;
			m_explosion->timer = 0;
		}
	}

	//Life
	DrawBox(35, 0, 200, 20, GetColor(255, 0, 0), true);
	DrawBox(35, 0, m_player->Health * 20, 20, GetColor(0, 255, 0), true);
<<<<<<< HEAD
	
=======
	//Timer
	timerCount++;
	if (timerCount > 40)
	{
		sceneParam->Timer--;
		timerCount = 0;
	}
>>>>>>> fc5c319ea7b759d123fa00c9326963419b316632
	//GameClear
	if (sceneParam->Timer == 0 || sceneParam->Timer <= 0)
	{
		sceneParam->SetSceneNum(SCENE_RESULT);
		sceneParam->SetClear(true);
		sceneParam->Timer = 0;
		m_player->Health = 10;
	}

<<<<<<< HEAD
	//Timer
	timerCount++;
	if (timerCount > 40)
	{
		sceneParam->Timer--;
		timerCount = 0;
	}
	// Timer‚ğ•`‰æ‚·‚é
	SetFontSize(SCORE_SIZE * 2);
	DrawFormatString(240, 0, GetColor(255, 0, 255), "%d", sceneParam->Timer);
	SetFontSize(SCORE_SIZE);
=======
	DrawFormatString(290, 0, GetColor(255, 0, 255), "%d", sceneParam->Timer);
>>>>>>> fc5c319ea7b759d123fa00c9326963419b316632

	// Score‚ğ•`‰æ‚·‚é
	DrawString(0, 0, "HP", GetColor(0, 255, 0));
	DrawFormatString(320, 0, RGB(255, 0, 0), "Score: %d", sceneParam->m_score);

	//€–Sˆ—(Game Over)
	if (m_player->Health <= 0 || m_player->Health == 0)
	{
		sceneParam->SetSceneNum(SCENE_RESULT);
		sceneParam->SetClear(false);
		m_player->Health = 10;
	}
}

void MainScene::Finalize()
{
	delete this;
}
