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


// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE); // �E�B���h�E���[�h�ɐݒ�
	SetWindowSize(800, 600);// �E�B���h�E�T�C�Y��ݒ�
	SetGraphMode(800, 600, 8);//�摜�𑜓x��ݒ�
	//SetDrawScreen(DX_SCREEN_BACK);

	// �c�w���C�u��������������
	if (DxLib_Init() == -1) { return -1; }// �G���[���N�����璼���ɏI��
	
	Player* p = new Player();//�v���C���[������
	Bullet* b = new Bullet();//�e������
	
	while (ProcessMessage() == 0)
	{
		if (CheckHitKey(KEY_INPUT_ESCAPE)) { break; }	//�I������
		ClearDrawScreen();	//�E�B���h�E�̏�����

		//�͈͐���
		if (p->x <= 20) { p->x = 20; }
		if (p->y <= 40) { p->y = 40; }
		if (p->x >= 800) { p->x = 800 - 40; }
		if (p->y >= 600) { p->y = 600 - 20; }

		//�L�[���͂̊m�F
		if (CheckHitKey(KEY_INPUT_UP) || CheckHitKey(KEY_INPUT_W)) { p->y -= p->Speed / 2; p->Angle = 0; }
		if (CheckHitKey(KEY_INPUT_DOWN) || CheckHitKey(KEY_INPUT_S)) { p->y += p->Speed; p->Angle = 0; }
		if (CheckHitKey(KEY_INPUT_RIGHT) || CheckHitKey(KEY_INPUT_D)) { p->x += p->Speed; p->Angle = p->Plus_angle; }
		if (CheckHitKey(KEY_INPUT_LEFT) || CheckHitKey(KEY_INPUT_A)) { p->x -= p->Speed; p->Angle = -p->Plus_angle; }
		if (!CheckHitKeyAll()) { p->Angle = 0; }	//�p�x������
		

		//�w�i
		int bg = LoadGraph("Resource/lgi01a201412150700.jpg");
		DrawGraph(0, 0, bg, FALSE);

		//player�̕\��
		int GHandle = LoadGraph("Resource/supercharged-rocket.png");
		DrawRotaGraph(p->x, p->y, p->Scale, p->Angle, GHandle, TRUE);
		
		//�e�̃L�[���͂̊m�F
		if (CheckHitKey(KEY_INPUT_SPACE))
		{
			//printfDx("Bullet");
			DrawGraph(b->Spawn_x, b->Spawn_y, b->B_Handle, TRUE);
		}

		ScreenFlip();//�`�揈��
	}

	DxLib_End();			// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I��
}
