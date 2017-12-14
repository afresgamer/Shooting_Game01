#pragma once
#include "pch.h"

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
	//oŒ»ŒÂ”
	int num = 5;
	int m_G = LoadGraph("Resource/comet.png");
};

