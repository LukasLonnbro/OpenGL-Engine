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
	~Mesh();

	void draw() const;

	VertexArray* getVa() const { return va; }
	VertexBuffer* getVb() const { return vb; }
	ElementBuffer* getEb() const { return eb; }

private:
	void setup();


	VertexArray* va;
	VertexBuffer* vb;
	ElementBuffer* eb;
	BufferLayout bl;
};