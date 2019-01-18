#pragma once
#include <vector>
#include "player.h"
#include "Bullet.h"
#include "BACK.h"
#include "Meteorite.h"
#include "Explosion.h"
#include "Collision.h"
#include "Button.h"
#include "BaseScene.h"
#include "SceneParameter.h"

class MainScene : BaseScene
{
public:
	MainScene();
	MainScene(SceneParameter* sceneP);
	~MainScene();
	void Init() override;
	void Update() override;
	void Finalize() override;
private:
	Player* m_player;
	Bullet* m_bullet;
	BACK* m_back;
	Meteorite* m_meteorite = new Meteorite[4];
	std::vector<Meteorite> m_meteVec;
	Collision* collision;
	Explosion* m_explosion;
	SceneParameter* sceneParam;
private:
	bool m_isBulletMove;
	bool m_isShot;
	int m_bulletCount;
	int timerCount = 0;
	int ShotSE = LoadSoundMem("Resource/shoot1.mp3");
	int ExploSE = LoadSoundMem("Resource/small_explosion1.mp3");
};
