#pragma once

#include "pch.h"

class Player
{
public:
	int x = 240;//初期位置x
	int y = 500;//初期位置y
	int w;
	int h;
	double Angle = 0;//初期角度
	int GHandle = LoadGraph("Resource/supercharged-rocket.png");
	int Speed = 10;//スピード
	double Scale = 0.2f;//大きさ
	double Plus_angle = 0.15f;//加算角度
};