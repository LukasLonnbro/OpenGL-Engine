#pragma once
#include "abstractRenderObject.h"

#include <glm/vec3.hpp>

class abstractLightRender : public abstractRenderObject
{
public:
	abstractLightRender(
		abstractShader* shader,
		const char* modelPath,
		glm::vec3 ambient_light,
		glm::vec3 diffuse_light,
		glm::vec3 specular_light,
		glm::vec3 m_Position) : 
		
		abstractRenderObject(shader, modelPath, m_Position)
	{}

	abstractLightRender(
		abstractShader* shader,
		const char* modelPath,
		glm::vec3 ambient_light,
		glm::vec3 diffuse_light,
		glm::vec3 specular_light) :

		ambient(ambient_light),
		diffuse(diffuse_light),
		specular(specular_light),
		abstractRenderObject(shader, modelPath)
	{}

	virtual const glm::vec3 getAmbient()	const { return ambient;  }
	virtual const glm::vec3 getDiffuse()	const { return diffuse;  }
	virtual const glm::vec3 getSpecular()	const { return specular; }
	virtual const glm::vec3 getPosition()	const { return position; }


protected:

	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
};