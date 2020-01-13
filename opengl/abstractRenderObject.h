#pragma once

#include "abstractShader.h"

#include "Mesh.h"
#include "modelParser.h"

#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <glm/gtx/string_cast.hpp>
#include <glm/ext.hpp>

#include <iostream>

#define ABSTRACT 0x01

class abstractRenderObject
{
public:
	abstractRenderObject(abstractShader * shader, const char* modelPath) :
		m_Shader(shader), path(modelPath)
	{
		modelParser parser(path);
		parser.loadModel(&m_Meshes);
		m_Model = glm::mat4(1.0f);
		setPosition(glm::vec3(0.0f));
	}

	abstractRenderObject(abstractShader * shader, const char* modelPath, glm::vec3 pos) : 
		m_Shader(shader), path(modelPath), position(pos)
	{
		modelParser parser(path);
		parser.loadModel(&m_Meshes);
		m_Model = glm::mat4(1.0f);
		setPosition(pos);
	}

	virtual void renderMeshes() const
	{
		for (unsigned int i = 0; i < m_Meshes.size(); i++)
		{
			m_Shader->setMat4("model", glm::value_ptr(m_Model));
			m_Meshes[i].draw();
		}
	}

	char getIdentifier() const { return identifier; }

	virtual inline const abstractShader * getShader() const { return m_Shader; }
	virtual void setModelMat(glm::mat4 mat) { m_Model = mat; }

	void updateModelMat() { m_Model = glm::translate(glm::mat4(1.0f), position); }
	void setPosition(glm::vec3 pos) { position = pos; updateModelMat(); }

	void coutPos() const { std::cout << position.x << " " << position.y << " " << position.z << " \n"; }
	void coutMat() const { std::cout << glm::to_string(m_Model); }

protected: 
	const char* path;

	glm::vec3 position;
	glm::mat4 m_Model;

	abstractShader * m_Shader;
	std::vector<Mesh> m_Meshes;

	char identifier;
}; 

