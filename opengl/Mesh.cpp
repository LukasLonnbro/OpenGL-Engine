#include "Mesh.h"
#include "elementBuffer.h"
#include "bufferLayout.h"

#include <iostream>

#include <gl/glew.h>

// If buffers need to be uploaded again, local copy of data might be needed here.
Mesh::Mesh(const std::vector<vertexData>& vertices, const std::vector<unsigned int>& indices)
{
	/*for (int i = 0; i < vertices.size(); i++) {
		std::cout << "i: " << i << "\nx : " << vertices[i].normal.x << " y: " << vertices[i].normal.y << " z: " << vertices[i].normal.z << "\n";
	}*/
	
	
	va = new VertexArray();
	vb = new VertexBuffer(&vertices[0], vertices.size() * sizeof(vertexData));
	eb = new ElementBuffer(&indices[0], indices.size() * sizeof(unsigned int), indices.size());
	setup();
}
Mesh::Mesh(const Mesh& other)
{
	va = other.getVa();
	eb = other.getEb();
	vb = other.getVb();
}
Mesh::~Mesh()
{

}


void Mesh::setup()
{
	va->bind();
	
	BufferLayout bl;
	bl.push<float>(3, true);
	bl.push<float>(3, true);

	va->addBuffer((*vb), bl);
}

void Mesh::draw() const
{
	va->bind();
	eb->bind();
	glDrawElements(GL_TRIANGLES, eb->getCount(), GL_UNSIGNED_INT, 0);
}