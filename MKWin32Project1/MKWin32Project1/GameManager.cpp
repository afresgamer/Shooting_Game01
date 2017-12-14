#include "GameManager.h"

void GameManager::Init()
{

	m_player = new Player();//�v���C���[������
	GetGraphSize(m_player->GHandle, &m_player->w, &m_player->h);

	m_bullet = new Bullet();//�e������
	m_bullet->SetPos(m_player->x, m_player->y);//�v���C���[�̒e�ʒu�ݒ�
	GetGraphSize(m_bullet->B_Handle, &m_bullet->w, &m_bullet->h);

	m_back = new BACK();//�w�i������

	m_meteorite = new Meteorite[4];
	GetGraphSize(m_meteorite->m_G, &m_meteorite->w, &m_meteorite->h);
	for (int i = 0; i < sizeof(m_meteorite); i++)
	{
		m_meteVec.push_back(m_meteorite[i]);
	}
	//����������
	m_explosion = new Explosion();
	//���˃t���O
	m_isBulletMove = false;
	//���ˊm�F�p�ϐ�(0���ł��ĂȂ� 1���ł��Ă���)
	m_isShot = 0;
	//���ˉ\�e��
	m_bulletCount = 0;
	//�X�R�A
	m_score = 0;

}

void GameManager::Update()
{
	//�͈͐���
	if (m_player->x <= 20) { m_player->x = 20; }
	if (m_player->y <= 40) { m_player->y = 40; }
	if (m_player->x >= 480) { m_player->x = 480 - 20; }
	if (m_player->y >= 600) { m_player->y = 600 - 20; }

	//�L�[���͂̊m�F
	if (CheckHitKey(KEY_INPUT_UP) || CheckHitKey(KEY_INPUT_W) || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_UP)) { m_player->y -= m_player->Speed / 2; m_player->Angle = 0; }
	if (CheckHitKey(KEY_INPUT_DOWN) || CheckHitKey(KEY_INPUT_S) || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_DOWN)) { m_player->y += m_player->Speed; m_player->Angle = 0; }
	if (CheckHitKey(KEY_INPUT_RIGHT) || CheckHitKey(KEY_INPUT_D) || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_RIGHT)) { m_player->x += m_player->Speed; m_player->Angle = m_player->Plus_angle; }
	if (CheckHitKey(KEY_INPUT_LEFT) || CheckHitKey(KEY_INPUT_A) || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_LEFT)) { m_player->x -= m_player->Speed; m_player->Angle = -m_player->Plus_angle; }
	//�p�x������
	if (!CheckHitKeyAll()) { m_player->Angle = 0; }
	//�e����
	if ((CheckHitKey(KEY_INPUT_SPACE) || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B)) && !m_isBulletMove) { m_isShot = true; }

	//�w�i
	//1���ڕ`��
	DrawGraph(m_back->x, m_back->y, m_back->gh, FALSE);
	//�񖇖ڕ`��
	DrawGraph(m_back->x, m_back->y - 1065, m_back->gh, FALSE);
	//�ړ��ƈړ�����
	m_back->y += SCROLL_SPEED;
	if (m_back->y >= 1065) { m_back->y = 0; }

	//player�̕\��
	m_player->y += GRAVITY;
	DrawRotaGraph(m_player->x, m_player->y, m_player->Scale, m_player->Angle, m_player->GHandle, TRUE);

	if (m_isShot) { m_isBulletMove = true; m_bullet->Spawn_x = m_player->x; m_isShot = false; }

	//�e�̓����Ɛ���
	if (m_isBulletMove)
	{
		m_bullet->Spawn_y -= m_bullet->Speed;
		DrawRotaGraph(m_bullet->Spawn_x, m_bullet->Spawn_y - 20, m_bullet->scale, 0, m_bullet->B_Handle, TRUE);

		if (m_bullet->Spawn_y <= 0)
		{
			m_isBulletMove = false;
			m_bullet->Spawn_y = m_player->y - 40;
		}
	}

	//�G�̕\��
	for (int i = 0; i < m_meteVec.size(); i++)
	{
		DrawRotaGraph(m_meteVec[i].x, m_meteVec[i].y, m_meteVec[i].scale, m_meteVec[i].angle, m_meteVec[i].m_G, TRUE);
		m_meteVec[i].y += m_meteorite[i].speed;
		if (m_meteVec[i].y > 630)
		{
			m_meteVec[i].y = 0;
			m_meteVec[i].x = GetRand(480);
		}
	}
	////�Փ˔���
	//if (IsIntersect(p->x, p->y, p->w, p->h, meteorite->x, meteorite->y, meteorite->w, meteorite->h))
	//{
	//	printfDx("�ڐG");
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
