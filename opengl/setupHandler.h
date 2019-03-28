#pragma once
class setupHandler
{
public:
	static void setupSDL();
	static void setupGL();
	static void config();
private:
	static int contextVersionMax;
	static int contextVersionMin;
	static int doublebuffer;
};

