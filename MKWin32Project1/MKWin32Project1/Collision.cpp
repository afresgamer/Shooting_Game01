#include "Collision.h"

bool Collision::IsCollision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2) {
	if (((x1 > x2 && x1 < x2 + w2) || (x2 > x1 && x2 < x1 + w1)) &&
		((y1 > y2 && y1 < y2 + h2) || (y2 > y1 && y2 < y1 + h1))) return true;
	else { return false; }
}

bool Collision::IsMouseCollision(int mousePosX, int mousePosY, int x, int y, int w, int h)
{
	if (mousePosX >= x && mousePosX <= x + w && mousePosY >= y && mousePosY <= y + h) {
		return true;
	}
	else { return false; }
}
