#pragma once

#include "pch.h"
#include "GameManager.h"

class SystemManager
{
public:
	SystemManager();
	~SystemManager();

	bool Init();
	void Update();
	void Finalize();

private:
	GameManager* m_gameMgr;
};