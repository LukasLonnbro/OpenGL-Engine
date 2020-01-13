#pragma once

#include <string>

#define ABSTRACT 0x0;

 class abstractShader
{
public:
	void compileAndLink(const std::string vertPath, const std::string fragPath);
	void use() const;
	void unUse() const;

	// Replace with meta programming. 
	void setFloat(const char *, const float value) const;
	void setFloat3f(const char* name, const float value[]) const;
	void setFloat3f(const char* name, float v1, float v2, float v3) const;
	//Do without including glew in header file.
	void setMat4(const char* name, const float* mat4) const;
	void setBool(const char* name, const unsigned char boolean) const;
	void setInt(const char* name, unsigned int val) const;

	virtual char getID() const { return ID; };

protected: 
	const char* vertSource;
	const char* fragSource;
	unsigned int shaderProgram;

	char ID = ABSTRACT;
};

