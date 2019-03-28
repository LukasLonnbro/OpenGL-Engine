#pragma once
#include "abstractShader.h"

class basicShader : public abstractShader
{
public:
	basicShader() {
		compileAndLink(
			"C:\\Users\\Lukas\\source\\repos\\opengl\\opengl\\deps\\shaders\\basicVert.glsl",
			"C:\\Users\\Lukas\\source\\repos\\opengl\\opengl\\deps\\shaders\\basicFrag.glsl"
		);
	}
};

