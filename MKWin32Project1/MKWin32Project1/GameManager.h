#pragma once
#include <vector>
#include "player.h"
#include "Bullet.h"
#include "BACK.h"
#include "Meteorite.h"
#include "Explosion.h"
#include "Collision.h"
#include "Button.h"

class GameManager
{
public:
	GameManager();
	~GameManager();
	void Init();
	void Update();
	void Finalize();

private:
	Player * m_player;
	Bullet* m_bullet;
	BACK* m_back;
	Meteorite* m_meteorite = new Meteorite[4];
	std::vector<Meteorite> m_meteVec;
	Collision* collision;
	//Button* button;

	Explosion* m_explosion;
	bool m_isBulletMove;
	bool m_isShot;
	int m_bulletCount;
	int m_score;
};
