#pragma once

#include "pch.h"

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