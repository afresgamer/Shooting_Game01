#pragma once
#include "DxLib.h"
using namespace std;

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
	int Speed = 30;
	void SetPos(int, int);//�v���C���[�ƓG�ňʒu������
	const int max_B = 5;
	int B_Handle = LoadGraph("Resource/bullet-36942_960_720.png");
	//�e�����|�C���g�ϐ�
	int Spawn_x;
	int Spawn_y;
	double scale = 0.08f;

};

class BACK
{
public:
	int x = 0;
	int y = 0;
	int gh = LoadGraph("Resource/65e78013a5e2efff7467e9ee1fa7d00a--backgrounds-wallpapers-iphone-wallpaper.jpg");
private:

};

class Meteorite
{
public:
	//Meteorite(int,int,int,int,double);
	int x;
	int y = 0;
	int speed = 10;
	double scale = 0.5f;
	double angle = -0.8f;
	int num = 5;
	int m_G = LoadGraph("Resource/comet.png");
};

