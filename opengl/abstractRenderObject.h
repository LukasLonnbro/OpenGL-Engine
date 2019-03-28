#pragma once

#include "abstractShader.h"

#include "Mesh.h"
#include "modelParser.h"

#include <glm/glm/mat4x4.hpp>
#include <glm/glm/gtc/type_ptr.hpp>

#include <iostream>

class abstractRenderObject
{
public:
	abstractRenderObject(const abstractShader * shader, const char* modelPath) : m_Shader(shader), path(modelPath) 
	{
		modelParser parser(path);
		m_Meshes = parser.loadModel();
	}

	virtual void renderMeshes() 
	{
		for (unsigned int i = 0; i < m_Meshes.size(); i++)
		{
			m_Shader->setMat4("model", glm::value_ptr(m_Model));
			m_Meshes[i].draw();
		}
	}

	virtual inline const abstractShader * getShader() { return m_Shader; }
	void setModelMat(glm::mat4 mat) { m_Model = mat; }

protected: 
	const char* path;

	glm::mat4 m_Model;
	const abstractShader * m_Shader;
	std::vector<Mesh> m_Meshes;
};  

