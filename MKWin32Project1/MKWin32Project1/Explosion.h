#pragma once

#include "pch.h"

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
	int timer;
	//�`�揈��
	void Draw(int frame);
};
