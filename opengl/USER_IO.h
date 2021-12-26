#pragma once
#include "constants.h"

#define evt USER_IO::get_keyboard()

struct Keyboard
{
	bool a;
	bool d;
	bool e;
	bool f;
	bool q;
	bool r;
	bool s;
	bool w;
	bool x;

	bool shift;
	bool space;

	int mouseX;
	int mouseY;
};


class USER_IO
{
public:
	USER_IO();
	~USER_IO();

	static void update();

	const inline static Keyboard * get_keyboard() { return &m_Keyboard; };

	static void setMousePos(int xPos, int yPos);

private:
	static Keyboard m_Keyboard;
};


