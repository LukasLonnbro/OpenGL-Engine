#pragma once

#include <string>

 class abstractShader
{
public:
	void compileAndLink(const std::string vertPath, const std::string fragPath);
	void use();
	void unUse();

	// Replace with meta programming. 
	void setFloat(const char *, const float value) const;
	void setFloat3f(const char* name, const float value[]) const;
	//Do without including glew in header file.
	void setMat4(const char* name, const float* mat4) const;
	void setBool(const char* name, const unsigned char boolean) const;

protected: 
	const char* vertSource;
	const char* fragSource;
	unsigned int shaderProgram;
};

