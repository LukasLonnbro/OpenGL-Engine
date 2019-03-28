#pragma once

#include "window.h"

class info {
public: 
	static inline float WIDTH() { return 640; };
	static inline float HEIGHT() { return 480; };

	static inline float scrWIDTH() { return 1920; };
	static inline float scrHEIGHT() { return 1080; };
};

struct eventBools {
	bool w;
	bool s;
	bool a;
	bool d;
	bool q;

	bool shift;
	bool space;

	int mouseX;
	int mouseY;
};