#pragma once
#include "DxLib.h"

class Player
{
public:
	int x = 400;//�����ʒu����
	int y = 500;//�����ʒu��
	double Angle = 0;//�����p�x
	int Speed = 20;//�X�s�[�h
	double Scale = 0.2f;//�傫��
	double Plus_angle = 0.15f;//���Z�p�x
private:
	
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
private:

};

