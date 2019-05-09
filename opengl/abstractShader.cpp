#include "abstractShader.h"
#include "errorhandler.h"
#include "paths.h"

#include <gl/glew.h>

#include <string>
#include <vector>
#include <iostream>

#include <fstream>

std::string shaderPath()
{
	return paths::getShaderPath();
}

std::string readFromFile(std::string filePath) {
	std::string contents;
	std::ifstream source(filePath, std::ios::in);

	if (!source.is_open()) {
		std::cout << "Could not read file " << filePath << ". File does not exist." << std::endl;
		int a;
		std::cin >> a;
		return "";
	}

	std::string line;
	while (!source.eof()) {
		std::getline(source, line);
		contents.append(line + "\n");
	}
	source.close();

	return contents;
}

//Automate abstractShader subclass creation, program that sets up shader paramaters based of files in the Shaders folder. 
void abstractShader::compileAndLink(const std::string vertPath, const std::string fragPath)
{
	// Read our shaders into the appropriate buffers
	std::string vertexSource = readFromFile(shaderPath() + vertPath);// Get source code for vertex shader.
	std::string fragmentSource = readFromFile(shaderPath() + fragPath);// Get source code for fragment shader.

	// Create an empty vertex shader handle
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

	// Send the vertex shader source code to GL
	// Note that std::string's .c_str is NULL character terminated.
	const GLchar *source = (const GLchar *)vertexSource.c_str();
	glShaderSource(vertexShader, 1, &source, 0);

	// Compile the vertex shader
	glCompileShader(vertexShader);

	GLint isCompiled = 0;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);
	if (isCompiled == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

		// The maxLength includes the NULL character
		std::vector<GLchar> infoLog(maxLength);
		glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &infoLog[0]);

		// We don't need the shader anymore.
		glDeleteShader(vertexShader);

		std::cout << "Vertexshader compilation fail: \n";
		for (int i = 0; i < infoLog.size(); i++)
			std::cout << infoLog[i];
		std::string a;
		std::getline(std::cin, a);

		// Use the infoLog as you see fit.
		errorhandler::addError(&infoLog[0], FATALERROR, "Vertex shader compilation failed.");

		// In this simple program, we'll just leave
		return;
	}

	// Create an empty fragment shader handle
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	// Send the fragment shader source code to GL
	// Note that std::string's .c_str is NULL character terminated.
	source = (const GLchar *)fragmentSource.c_str();
	glShaderSource(fragmentShader, 1, &source, 0);

	// Compile the fragment shader
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);
	if (isCompiled == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

		// The maxLength includes the NULL character
		std::vector<GLchar> infoLog(maxLength);
		glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);

		// We don't need the shader anymore.
		glDeleteShader(fragmentShader);
		// Either of them. Don't leak shaders.
		glDeleteShader(vertexShader);

		std::cout << "Fragmentshader compilation fail: \n";
		for (int i = 0; i < infoLog.size(); i++)
			std::cout << infoLog[i];

		// Use the infoLog as you see fit.
		errorhandler::addError(&infoLog[0], FATALERROR, "Fragment shader compilation failed.");

		// In this simple program, we'll just leave
		return;
	}

	// Vertex and fragment shaders are successfully compiled.
	// Now time to link them together into a program.
	// Get a program object.
	shaderProgram = glCreateProgram();

	// Attach our shaders to our program
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);

	// Link our program
	glLinkProgram(shaderProgram);

	// Note the different functions here: glGetProgram* instead of glGetShader*.
	GLint isLinked = 0;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, (int *)&isLinked);
	if (isLinked == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &maxLength);

		// The maxLength includes the NULL character
		std::vector<GLchar> infoLog(maxLength);
		glGetProgramInfoLog(shaderProgram, maxLength, &maxLength, &infoLog[0]);

		// We don't need the program anymore.
		glDeleteProgram(shaderProgram);
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		// Use the infoLog as you see fit.


		// In this simple program, we'll just leave
		return;
	}

	// Always detach shaders after a successful link.
	glDetachShader(shaderProgram, vertexShader);
	glDetachShader(shaderProgram, fragmentShader);
}
// TODO: Double check for possible memory leaks.

void abstractShader::setFloat(const char * name, const float value) const {
	glUniform1f(glGetUniformLocation(shaderProgram, name), value);
}
void abstractShader::setFloat3f(const char* name, const float value[]) const {
	glUniform3f(glGetUniformLocation(shaderProgram, name), value[0], value[1], value[2]);
}
void abstractShader::setMat4(const char* name, const float* mat4) const {
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram, name), 1, GL_FALSE, mat4);
}
void abstractShader::setBool(const char* name, const unsigned char boolean) const {
	glUniform1i(glGetUniformLocation(shaderProgram, name), boolean);
}

void abstractShader::use() const
{
	glUseProgram(shaderProgram);	// Don't leak shaders either.
}
void abstractShader::unUse() const
{
	glUseProgram(0);
}
