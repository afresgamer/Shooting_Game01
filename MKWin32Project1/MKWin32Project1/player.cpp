#include "player.h"

void Player::Update() 
{
	//�͈͐���
	if (x <= 20) { x = 20; }
	if (y <= 40) { y = 40; }
	if (x >= 480) { x = 480 - 20; }
	if (y >= 600) { y = 600 - 20; }

	//�L�[���͂̊m�F
	if (CheckHitKey(KEY_INPUT_UP) || CheckHitKey(KEY_INPUT_W) || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_UP))
	{
		y -= Speed / 2; Angle = 0;
	}
	if (CheckHitKey(KEY_INPUT_DOWN) || CheckHitKey(KEY_INPUT_S) || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_DOWN))
	{
		y += Speed; Angle = 0;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT) || CheckHitKey(KEY_INPUT_D) || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_RIGHT))
	{
		x += Speed; Angle = Plus_angle;
	}
	if (CheckHitKey(KEY_INPUT_LEFT) || CheckHitKey(KEY_INPUT_A) || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_LEFT))
	{
		x -= Speed; Angle = -Plus_angle;
	}
	//�p�x������
	if (!CheckHitKeyAll()) { Angle = 0; }

	//player�̕\��
	y += GRAVITY;
}