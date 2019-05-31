#include <iostream>
#include <string>

#include <GL/glew.h>
#include <SDL.h>

#include "window.h"
#include "setupHandler.h"
#include "gameController.h"
#include "constants.h"

#undef main

#define STATIC_ALLOC


std::vector<unsigned int> indices = {
		 0,  1,  2,  0,  2,  3,
		 4,  5,  6,  4,  6,  7,
		 8,  9,  10, 8,  10, 11,
		 12, 13, 14, 12, 14, 15,
		 16, 17, 18, 16, 18, 19,
		 20, 21, 22, 20, 22, 23
};

GLfloat cube_vertices[] = {
	-1.0, -1.0,  1.0,
	 1.0, -1.0,  1.0,
	 1.0,  1.0,  1.0,
	-1.0,  1.0,  1.0,
	// back
	-1.0, -1.0, -1.0,
	 1.0, -1.0, -1.0,
	 1.0,  1.0, -1.0,
	-1.0,  1.0, -1.0
};

void render1(window w)
{
	glClearColor(0.4, 0.3, 0.2, 1.0f);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	static const GLfloat g_vertex_buffer_data[] = {
	   -1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f,  1.0f, 0.0f,
	};

	GLuint vertexbuffer;
	// Generate 1 buffer, put the resulting identifier in vertexbuffer
	glGenBuffers(1, &vertexbuffer);
	// The following commands will talk about our 'vertexbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	// Give our vertices to OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
	// Draw the triangle !
	glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
	glDisableVertexAttribArray(0);

	SDL_GL_SwapWindow(w.getWindowHolder());
}

void render2(window w)
{
	glClearColor(0.4, 0.3, 0.2, 1.0f);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	for (int i = 0; i < 24; i++) {
		cube_vertices[i] /= 2;
	}

	VertexArray va;
	va.bind();

	ElementBuffer eb(&indices[0], sizeof(unsigned int) * indices.size(), 36);
	VertexBuffer vb(&cube_vertices[0], sizeof(cube_vertices));

	BufferLayout bl;
	bl.push<float>(3, false);

	va.addBuffer(vb, bl);

	glDrawElements(GL_TRIANGLES, eb.getCount(), GL_UNSIGNED_INT, (void*)0);

	SDL_GL_SwapWindow(w.getWindowHolder());

	std::string a;
	std::getline(std::cin, a);
}

void render3(window w)
{
	glClearColor(0.4, 0.3, 0.2, 1.0f);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	basicShader shader;
	std::vector<Mesh> meshes;

	modelParser data("C:\\Users\\Lukas\\source\\repos\\LukasLonnbro\\OpenGL-Engine\\deps\\models\\teapot.obj");
	data.loadModel(&meshes);

	glm::mat4 model(1.0f);
	glm::mat4 view(1.0f);
	glm::mat4 projection(1.0f);

	shader.use();

	shader.setMat4("model", glm::value_ptr(model));
	shader.setMat4("view", glm::value_ptr(view));
	shader.setMat4("projection", glm::value_ptr(projection));
	for (int i = 0; i < meshes.size(); i++)
	{
		meshes[i].draw();
	}

	SDL_GL_SwapWindow(w.getWindowHolder());

	std::string a;
	std::getline(std::cin, a);
}

int main() {
	std::cout << "Hello world\n";
	
	SDL_GL_SetSwapInterval(0);
	
	setupHandler::setupSDL();
	SDL_Init(SDL_INIT_EVERYTHING);
	window myWindow("maybe", (int)info::WIDTH(), (int)info::HEIGHT());

	setupHandler::setupGL();

	gameController controller(&myWindow);
	controller.run();

	//render3(myWindow);

}
