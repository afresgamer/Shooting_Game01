#pragma once
#include "pch.h"

class Bullet
{
public:
	int Speed = 30;
	void SetPos(int, int);//プレイヤーと敵で位置を決定
	const int max_B = 5;
	int B_Handle = LoadGraph("Resource/bullet-36942_960_720.png");
	//弾発生ポイント変数
	int Spawn_x;
	int Spawn_y;
	int w = 30;
	int h = 50;
	double scale = 0.08f;
};