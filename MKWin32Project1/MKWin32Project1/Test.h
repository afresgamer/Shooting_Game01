#pragma once
#include "DxLib.h"
using namespace std;

class Player
{
public:
	int x = 240;//�����ʒux
	int y = 500;//�����ʒuy
	int w;
	int h;
	double Angle = 0;//�����p�x
	int GHandle = LoadGraph("Resource/supercharged-rocket.png");
	int Speed = 10;//�X�s�[�h
	double Scale = 0.2f;//�傫��
	double Plus_angle = 0.15f;//���Z�p�x
};

class Bullet
{
public:
	int Speed = 30;
	void SetPos(int, int);//�v���C���[�ƓG�ňʒu������
	const int max_B = 5;
	int B_Handle = LoadGraph("Resource/bullet-36942_960_720.png");
	//�e�����|�C���g�ϐ�
	int Spawn_x;
	int Spawn_y;
	int w;
	int h;
	double scale = 0.08f;
};

class BACK
{
public:
	int x = 0;
	int y = 0;
	int gh = LoadGraph("Resource/65e78013a5e2efff7467e9ee1fa7d00a--backgrounds-wallpapers-iphone-wallpaper.jpg");
};

class Meteorite
{
public:
	int x;
	int y = 0;
	int w;
	int h;
	int speed = 10;
	double scale = 1;
	double angle = -0.8f;
	//�o����
	int num = 5;
	int m_G = LoadGraph("Resource/comet.png");
};

class Explosion
{
public:
	int x;
	int y;
	double scale = 1;
	//�摜�f�[�^�̌Ăяo��
	int GHandle[10] = 
	{ 
		LoadGraph("Resource/Explosion (1).png"), LoadGraph("Resource/Explosion (2).png") ,LoadGraph("Resource/Explosion (3).png") 
		,LoadGraph("Resource/Explosion (4).png") ,LoadGraph("Resource/Explosion (5).png") ,LoadGraph("Resource/Explosion (6).png")
		,LoadGraph("Resource/Explosion (7).png") ,LoadGraph("Resource/Explosion (8).png") ,LoadGraph("Resource/Explosion (9).png")
		,LoadGraph("Resource/Explosion (10).png")
	};
	int timer = GetNowCount();
	//�`�揈��
	void Draw();
};
