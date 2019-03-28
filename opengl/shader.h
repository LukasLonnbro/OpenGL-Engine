#pragma once

#include <glew/glew.h>
#include <string>

class shader
{
public:
	shader(std::string vertSource, std::string fragSource);
	~shader();

	void use();
	void unUse();

	// Replace with meta programming. 
	void setFloat(const char *, float value);
	void setFloat3f(const char* name, float value[]);
	//Do without including glew in header file.
	void setMat4(const char* name, GLfloat* mat4);
	void setBool(const char* name, GLboolean boolean);

protected: 
	const char* vertSource;
	const char* fragSource;
	unsigned int shaderProgram;
};

