#pragma once

#include "abstractShader.h"

#include "Mesh.h"
#include "modelParser.h"

#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

class abstractRenderObject
{
public:
	abstractRenderObject(abstractShader * shader, const char* modelPath) : m_Shader(shader), path(modelPath)
	{
		modelParser parser(path);
		m_Meshes = parser.loadModel();
	}

	virtual void renderMeshes() const
	{
		for (unsigned int i = 0; i < m_Meshes.size(); i++)
		{
			m_Shader->setMat4("model", glm::value_ptr(m_Model));
			m_Meshes[i].draw();
		}
	}

	virtual inline const abstractShader * getShader() const { return m_Shader; }
	virtual void setModelMat(glm::mat4 mat) { m_Model = mat; }

	virtual void coutsomethingrandom() { std::cout << "stuff\n"; }

protected: 
	const char* path;

	glm::mat4 m_Model;
	abstractShader * m_Shader;
	std::vector<Mesh> m_Meshes;
};  

