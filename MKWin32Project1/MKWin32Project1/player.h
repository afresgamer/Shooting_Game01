#pragma once

#include "pch.h"

class Player
{
public:
	void Update();
	int x = 240;//�����ʒux
	int y = 500;//�����ʒuy
	int w = 40;
	int h = 90;
	double Angle = 0;//�����p�x
	int GHandle = LoadGraph("Resource/supercharged-rocket.png");
	int Speed = 10;//�X�s�[�h
	int Health = 10;//���C�t
	double Scale = 0.2f;//�傫��
	double Plus_angle = 0.15f;//���Z�p�x
};