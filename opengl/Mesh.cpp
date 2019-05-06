#include "Mesh.h"
#include "elementBuffer.h"

#include <iostream>

#include <gl/glew.h>

Mesh::Mesh(const std::vector<vertexData>& vertices, const std::vector<unsigned int>& indices) :
	m_Vertices(vertices),
	m_Indices(indices),
	va(),
	vb(&vertices[0], vertices.size() * sizeof(vertexData)),
	eb(&indices[0], indices.size() * sizeof(unsigned int))
{
	setupMesh();
}
Mesh::Mesh(const Mesh& other) : Mesh(other.getVertices(), other.getIndices())
{
}


void Mesh::setupMesh() 
{
	va.bind();

	bufferLayout bl;
	bl.push<float>(3, true);
	bl.push<float>(3, true);

	va.addBuffer(vb, bl);
}

void Mesh::draw() 
{
	va.bind();
	glDrawElements(GL_TRIANGLES, m_Indices.size(), GL_UNSIGNED_INT, 0);
}