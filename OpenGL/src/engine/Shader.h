#pragma once

#include <string>
#include <unordered_map>

class Shader
{
public:
private:
	unsigned int renderer_id;
	std::string filePath;
	std::unordered_map<std::string, int> locations;
	int GetUniformLocation(const std::string& name);
public:
	Shader(const std::string& filename);
	unsigned int CompileShader(unsigned int type, std::string source);
	~Shader();

	void Bind() const;
	void Unbind() const;

	void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
	void SetUniform1i(const std::string& name, int value);
};