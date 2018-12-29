#include "player.h"

void Player::Update() 
{
	//範囲制限
	if (x <= 20) { x = 20; }
	if (y <= 40) { y = 40; }
	if (x >= 480) { x = 480 - 20; }
	if (y >= 600) { y = 600 - 20; }

	//キー入力の確認
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
	//角度初期化
	if (!CheckHitKeyAll()) { Angle = 0; }

	//playerの表示
	y += GRAVITY;
}