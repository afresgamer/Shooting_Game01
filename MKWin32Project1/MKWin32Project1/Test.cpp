#include "Test.h"
#include <vector>

#define SCROLL_SPEED 2
#define GRAVITY 1
#define SCORE_SIZE 25

//�e�̈ʒu������
void Bullet::SetPos(int x, int y)
{
	Spawn_x = x;
	Spawn_y = y;
}

//�����蔻��
bool IsIntersect(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{
	if(((x1 > x2 && x1 < x2 + w2) || (x2 > x1 && x2 < x1 + w1) && (y1 > y2 && y1 < y2 + h2) || (y2 > y1 && y2 < y1 + h1)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Explosion::Draw()
{
	for (int i = 0; i < 10; i++)
	{
		DrawRotaGraph(x, y, scale, 0, GHandle[i], FALSE);
	}
}

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE); // �E�B���h�E���[�h�ɐݒ�
	SetWindowSize(480, 600);// �E�B���h�E�T�C�Y��ݒ�
	SetGraphMode(480, 600, 8);//�摜�𑜓x��ݒ�
	SetFontSize(SCORE_SIZE);//�����T�C�Y
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE);//�����̒[�̃��C���\��
	//SetDrawScreen(DX_SCREEN_BACK);

	// �c�w���C�u��������������
	if (DxLib_Init() == -1) { return -1; }// �G���[���N�����璼���ɏI��

	Player* p = new Player();//�v���C���[������
	GetGraphSize(p->GHandle, &p->w, &p->h);

	Bullet* p_b = new Bullet();//�e������
	p_b->SetPos(p->x, p->y);//�v���C���[�̒e�ʒu�ݒ�
	GetGraphSize(p_b->B_Handle, &p_b->w, &p_b->h);

	BACK* back = new BACK();//�w�i������

	Meteorite* meteorite = new Meteorite[4];
	GetGraphSize(meteorite->m_G, &meteorite->w, &meteorite->h);
	vector<Meteorite> meteVec;
	for (int i = 0; i < sizeof(meteorite); i++)
	{
		meteVec.push_back(meteorite[i]);
	}

	//����������
	Explosion* e = new Explosion();
	//���˃t���O
	bool isBulletMove = false;
	//���ˊm�F�p�ϐ�(0���ł��ĂȂ� 1���ł��Ă���)
	int isShot = 0;
	//���ˉ\�e��
	int Bullet_count = 0;
	//�X�R�A
	int score = 0;

	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();	//�E�B���h�E�̏�����

		//�͈͐���
		if (p->x <= 20) { p->x = 20; }
		if (p->y <= 40) { p->y = 40; }
		if (p->x >= 480) { p->x = 480 - 20; }
		if (p->y >= 600) { p->y = 600 - 20; }

		//�L�[���͂̊m�F
		if (CheckHitKey(KEY_INPUT_UP) || CheckHitKey(KEY_INPUT_W) || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_UP)) { p->y -= p->Speed / 2; p->Angle = 0; }
		if (CheckHitKey(KEY_INPUT_DOWN) || CheckHitKey(KEY_INPUT_S) || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_DOWN)) { p->y += p->Speed; p->Angle = 0; }
		if (CheckHitKey(KEY_INPUT_RIGHT) || CheckHitKey(KEY_INPUT_D) || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_RIGHT)) { p->x += p->Speed; p->Angle = p->Plus_angle; }
		if (CheckHitKey(KEY_INPUT_LEFT) || CheckHitKey(KEY_INPUT_A) || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_LEFT)) { p->x -= p->Speed; p->Angle = -p->Plus_angle; }
		//�p�x������
		if (!CheckHitKeyAll()) { p->Angle = 0; }
		//�e����
		if ((CheckHitKey(KEY_INPUT_SPACE) || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B)) && !isBulletMove) { isShot = 1; }

		//�w�i
		//1���ڕ`��
		DrawGraph(back->x, back->y, back->gh, FALSE);
		//�񖇖ڕ`��
		DrawGraph(back->x, back->y - 1065, back->gh, FALSE);
		//�ړ��ƈړ�����
		back->y += SCROLL_SPEED;
		if (back->y >= 1065) { back->y = 0; }

		//player�̕\��
		p->y += GRAVITY;
		DrawRotaGraph(p->x, p->y, p->Scale, p->Angle, p->GHandle, TRUE);

		if (isShot == 1) { isBulletMove = true; p_b->Spawn_x = p->x; isShot = 0; }

		//�e�̓����Ɛ���
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

		//�G�̕\��
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
		//�Փ˔���
		if (IsIntersect(p->x, p->y, p->w, p->h, meteorite->x, meteorite->y, meteorite->w, meteorite->h))
		{
			printfDx("�ڐG");
		}

		//DrawFormatString(0, 0, GetColor(255, 255, 0), "SCORE : %d", score);

		if (CheckHitKey(KEY_INPUT_ESCAPE)) { break; }	//�I������

		ScreenFlip();//�`�揈��
	}

	DxLib_End();			// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I��
}
