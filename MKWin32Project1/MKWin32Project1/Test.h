#pragma once
#include "DxLib.h"

class Player
{
public:
	int x = 400;//初期位置高さ
	int y = 500;//初期位置幅
	double Angle = 0;//初期角度
	int Speed = 20;//スピード
	double Scale = 0.2f;//大きさ
	double Plus_angle = 0.15f;//加算角度
private:
	
};

class Bullet
{
public:
	int Speed = 50;
	Player* p = new Player();
	int B_Handle = LoadGraph("Resource/bullet-36942_960_720.png");
	//弾発生ポイント変数
	int Spawn_x = p->x;
	int Spawn_y = p->y - 20;
private:

};

