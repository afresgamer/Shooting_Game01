#include "Explosion.h"

void Explosion::Draw()
{
	for (int i = 0; i < 10; i++)
	{
		DrawRotaGraph(x, y, scale, 0, GHandle[i], FALSE);
	}
}
