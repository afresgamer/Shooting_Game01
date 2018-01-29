#include "SystemManager.h"

SystemManager::SystemManager()
{
	Init();
}

SystemManager::~SystemManager()
{
	Finalize();
}


bool SystemManager::Init()
{
	ChangeWindowMode(true); // �E�B���h�E���[�h�ɐݒ�
	SetWindowSize(480, 600);// �E�B���h�E�T�C�Y��ݒ�
	SetGraphMode(480, 600, 8);//�摜�𑜓x��ݒ�
	SetFontSize(SCORE_SIZE);//�����T�C�Y
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE);//�����̒[�̃��C���\��
												  // �c�w���C�u��������������
	if (DxLib_Init() == -1) { return false; }// �G���[���N�����璼���ɏI��

	m_gameMgr = new GameManager();
	return true;
}

void SystemManager::Update()
{
	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();	//�E�B���h�E�̏�����
		m_gameMgr->Update(); // �Q�[�����W�b�N�̍X�V

		if (CheckHitKey(KEY_INPUT_ESCAPE)) { break; }	//�I������
		ScreenFlip();//�`�揈��
	}
}

void SystemManager::Finalize()
{
	DxLib_End();			// �c�w���C�u�����g�p�̏I������
}
