#pragma once

#include <Shlwapi.h>
#include <string>

// TODO : I dunno. This?!

struct info 
{
	static inline float WIDTH() { return 640; };
	static inline float HEIGHT() { return 480; };

	static inline float scrWIDTH() { return 1920; };
	static inline float scrHEIGHT() { return 1080; };
};


struct eventBools
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
