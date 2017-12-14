#include "pch.h"
#include "SystemManager.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SystemManager* systemMgr = new SystemManager();
	if (!systemMgr->Init()) { return -1; }
	systemMgr->Update();
	delete systemMgr;
	return 0;				// �\�t�g�̏I��
}
