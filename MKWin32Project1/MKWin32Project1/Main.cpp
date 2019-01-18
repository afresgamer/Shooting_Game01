#include "pch.h"
#include "SystemManager.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SystemManager* systemMgr = new SystemManager();
	if (!systemMgr->Init()) { return -1; }
	systemMgr->Update();
	delete systemMgr;
	return 0;				// ソフトの終了
}
