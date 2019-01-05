#pragma once
#include "Collision.h"

class Button
{
public:
	Button(int x, int y, int w, int h, const char* str);
	~Button();
	void Init();
	void Update();
	void Finalize();
	void Draw(int x , int y);
	void PlayButtonAnim();
	void StopButtonAnim();
	void ButtonAnim();
	void SetbtnColor(unsigned int color);
	void SetTextColor(unsigned int color);
	bool IsPressed;
private:
	int mouse, mouseX, mouseY;
	unsigned int btnColor, TextColor;
	int InitmX, InitmY, InitmW, InitmH;
	int mX, mY, mW, mH;
	const char* mStr;
	Collision* collision;
};
