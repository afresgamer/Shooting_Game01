#pragma once

class Collision 
{
public:
	bool IsCollision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);
	bool IsMouseCollision(int mousePosX, int mousePosY, int x, int y, int w, int h);

};
