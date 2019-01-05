#include "Button.h"
#include "pch.h"

Button::Button(int x, int y, int w, int h, const char* str) {
	mX = x;
	InitmX = x;
	mY = y;
	InitmY = y;
	mW = w;
	InitmW = w;
	mH = h;
	InitmH = h;
	mStr = str;
}

Button::~Button() {
	Finalize();
}

void Button::Init() 
{
	collision = new Collision();
	btnColor = GetColor(255, 255, 255);
	TextColor = GetColor(255, 0, 0);
}

void Button::Update()
{
	//マウスの状態確認
	mouse = GetMouseInput();
	GetMousePoint(&mouseX, &mouseY);
	//カーソルがボタン上にあるとき
	if (collision->IsMouseCollision(mouseX,mouseY,mX,mY,mW,mH))
	{
		PlayButtonAnim();
		if (mouse & MOUSE_INPUT_LEFT) {
			ButtonAnim();
			IsPressed = true;
		}
		else { IsPressed = false; }
	}
	else if(!collision->IsMouseCollision(mouseX, mouseY, mX, mY, mW, mH)) {
		StopButtonAnim();
	}
}

void Button::Finalize()
{
	delete this;
}

void Button::Draw(int x, int y) 
{
	DrawBox(mX, mY, mW, mH, btnColor, TRUE);
	DrawString(x, y, mStr ,TextColor);
}

void Button::ButtonAnim() 
{
	mX += 1;
	mW -= 1;
	mY += 1;
	mH -= 1;
	if (mX > InitmX + 3 && mW < InitmW - 3 && mY > InitmY + 3 && mH < InitmH - 3) {
		mX = InitmX;
		mW = InitmW;
		mY = InitmY;
		mH = InitmH;
	}
}

void Button::SetbtnColor(unsigned int color)
{
	btnColor = color;
}

void Button::SetTextColor(unsigned int color)
{
	TextColor = color;
}

void Button::PlayButtonAnim()
{
	mX += 1;
	mW -= 1;
	mY += 1;
	mH -= 1;
	if (mX > InitmX + 3 && mW < InitmW - 3 && mY > InitmY + 3 && mH < InitmH - 3) {
		mX = InitmX + 3;
		mW = InitmW - 3;
		mY = InitmY + 3;
		mH = InitmH - 3;
	}
}

void Button::StopButtonAnim()
{
	mX = InitmX;
	mW = InitmW;
	mY = InitmY;
	mH = InitmH;
}
