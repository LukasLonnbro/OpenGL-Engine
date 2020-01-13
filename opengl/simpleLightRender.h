#pragma once
#include "abstractLightRender.h"

class simpleLightRender : public abstractLightRender
{
public:
	simpleLightRender(
		abstractShader* shader,
		const char* modelPath,
		glm::vec3 ambient, 
		glm::vec3 diffuse, 
		glm::vec3 specular) :
		
		abstractLightRender(shader, modelPath, ambient, diffuse, specular)
	{}
};