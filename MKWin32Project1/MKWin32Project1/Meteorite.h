#pragma once
#include "pch.h"

class Meteorite
{
public:
	/*void Init();
	int GetEmptyArea();*/
	bool IsEmpty[7];
	int x;
	int y = 0;
	int w = 40;
	int h = 40;
	int speed = 10;
	double scale = 0.2;
	double angle = 0;
	//èoåªå¬êî
	int num = 5;
	int m_G = LoadGraph("Resource/JP_MTGANN_Symbol.png");
private:
};

