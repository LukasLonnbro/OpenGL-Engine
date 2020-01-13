#pragma once
#include "abstractShader.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#define BASIC 0x01

class basicShader : public abstractShader
{
public:
	basicShader() {
		compileAndLink(
			"basicVert.glsl",
			"basicFrag.glsl"
		);

		ID = BASIC;
	}

	void setModelMat(glm::mat4& mat) { setMat4("model", glm::value_ptr(mat)); };
	void setViewMat(glm::mat4& mat) { setMat4("view", glm::value_ptr(mat)); };

};

