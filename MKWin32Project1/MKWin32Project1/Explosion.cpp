#include "Explosion.h"

void Explosion::Draw(int frame)
{
	DrawRotaGraph(x, y, scale, 0, GHandle[frame], true);
}
