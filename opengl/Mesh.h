#pragma once

#include "vertexArray.h"
#include "vertexBuffer.h"
#include "elementBuffer.h"

#include <vector>
#include <glm/vec3.hpp>
#include <iostream>

struct vertexData {
	glm::vec3 position;
	glm::vec3 normal;
};

class Mesh 
{
public:
	Mesh(const std::vector<vertexData>& vertices, const std::vector<unsigned int>& indices);
	Mesh(const Mesh& other);
	Mesh& operator = (const Mesh &other)
	{
		m_Vertices = other.getVertices(); 
		m_Indices = other.getIndices(); 
		setupMesh();
	}
	~Mesh() { std::cout << "Deleting Mesh."; }

	void draw();

	const inline std::vector<vertexData> getVertices() const { return m_Vertices; };
	const inline std::vector<unsigned int> getIndices() const { return m_Indices; };

private:
	std::vector<vertexData> m_Vertices;
	std::vector<unsigned int> m_Indices;

	vertexArray va;
	vertexBuffer vb;
	elementBuffer eb;

	void setupMesh();
};