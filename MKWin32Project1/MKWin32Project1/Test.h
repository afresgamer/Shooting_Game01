#pragma once
#include "DxLib.h"

class Player
{
public:
	int x = 240;//�����ʒu����
	int y = 500;//�����ʒu��
	double Angle = 0;//�����p�x
	int Speed = 10;//�X�s�[�h
	double Scale = 0.2f;//�傫��
	double Plus_angle = 0.15f;//���Z�p�x
};

class Bullet
{
public:
	int Speed = 50;
	Player* p = new Player();
	int B_Handle = LoadGraph("Resource/bullet-36942_960_720.png");
	//�e�����|�C���g�ϐ�
	int Spawn_x = p->x;
	int Spawn_y = p->y - 20;
	double scale = 0.1f;

};

class BACK
{
public:
	int x = 0;
	int y = 0;
	int gh = LoadGraph("Resource/65e78013a5e2efff7467e9ee1fa7d00a--backgrounds-wallpapers-iphone-wallpaper.jpg");
private:

};


