#pragma once
#include "abstractShader.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class basicShader : public abstractShader
{
public:
	basicShader() {
		compileAndLink(
			"basicVert.glsl",
			"basicFrag.glsl"
		);
	}

	void setModelMat(glm::mat4& mat) { setMat4("model", glm::value_ptr(mat)); };
	void setViewMat(glm::mat4& mat) { setMat4("view", glm::value_ptr(mat)); };

};

